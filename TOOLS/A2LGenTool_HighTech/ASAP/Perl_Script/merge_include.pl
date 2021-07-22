#
use strict;
use Getopt::Long;
use File::Basename;
use File::Spec;

# options
my $inFile;
my $outFile;
my $verb;
my $usage;

# parse command line args
GetOptions( 'f=s',    \$inFile,
            'o=s',    \$outFile,
            'verb!',  \$verb,
            'h!',     \$usage);

if ($usage) {
  my $plain_text;
$plain_text = <<'_PLAIN_TEXT';
This script expands all include directives in the given file (see -f option).

Usage: perl merge_include.pl <options>
  <options>:
    -f=<file>         -> <file> defines the input file to be processed.
    -o=<file>         -> <file> defines the resulting file, where all include directives are expanded.
    -verb             -> activates verbose output
    -h                -> print this lines
_PLAIN_TEXT

  print $plain_text;
  exit 1;
} # usage


# check the input file.
if (-e $inFile) {
  # read data
  open FH, '<' . $inFile or
      report('F', "Cannot read input file $inFile: $!", -1);
  my @data = <FH>;
  close FH;
  print "reading input file $inFile completed\n" if ($verb);

  # remove newlines
  chomp(@data);

  my $curBasePath = File::Basename::dirname($inFile);
  print "set current bas path to: [$curBasePath]\n" if ($verb);
  @data = expand_includes($curBasePath, \@data);

  # add newlines
  @data = map { "$_$/" } @data;

  # write data
  print "writting output file $outFile\n" if ($verb);
  open FH, '>' . $outFile or
      report('F', "Cannot write output file $outFile: $!", -1);
  print FH @data;
  close FH;
  print "successfully finished.\n" if ($verb);
} else {
  report('F', "input file $inFile does not exists: $!");
}

exit(0);

#########################################################
#                                                       #
#               subfunctions                            #
#                                                       #
#########################################################
sub expand_includes {
  my ($curBasePath, $data) = @_;
  my @output = ();

  foreach my $line (@{$data}) {
    if ($line =~ m|^\s*/include\s+"?([^"]*)"?|) { #"
      my $path = $1;
      $path =~ s/\s*$//;
      $path = File::Spec->canonpath($path);
      print "found include $path\n" if ($verb);

      my $fullPath;
      if (-e $path) {
        $fullPath = $path;
      } else {
        $fullPath = File::Spec->catdir( $curBasePath, $path );
      }
      print "using full path $fullPath\n" if ($verb);

      open FH, '<' . $fullPath or
          report('F', "Cannot read include '$fullPath': $!", -1);
      my @lines = <FH>;
      close FH;

      # remove newlines
      chomp(@lines);

      my $newBasePath = File::Basename::dirname(File::Spec->canonpath($fullPath));
      print "entering file [$fullPath´] with current base path [$newBasePath]\n" if ($verb);
      @lines = expand_includes($newBasePath, \@lines);
      print "finished file [$fullPath´]\n" if ($verb);

      push @output, @lines;
    } else {
      push @output, $line;
    }
  }
  return @output;
}


my %LogTypes = (
  "F"   => "Fatal",
  "E"   => "Error",
  "W"   => "Warning",
  "I"   => "Information"
);

sub report ($$;$) {
  my ($type, $text, $errorCode) = @_;

  my $prefix = $LogTypes{$type};
  $prefix = 'Fatal' unless (defined $prefix);

  my ($pack, $file, $line) = caller;
  $line = '' unless (defined $line);
  $file = '' unless (defined $file);

  print STDERR $type, 'in <',$file,' (line: ',$line,')>: ',$text,"\n";

  if (defined $errorCode) {
    exit ($errorCode);
  }
}
