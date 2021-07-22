/*
 * Bsw_OsTasks.c
 *
 *  Created on: Jun 14, 2018
 *      Author: CIX2SGH
 */

#include "Os.h"

static volatile uint32 osTask_1ms_cnt;
static volatile uint32 osTask_2ms_cnt;
static volatile uint32 osTask_5ms_cnt;
static volatile uint32 osTask_10ms_cnt;
static volatile uint32 osTask_50ms_cnt;

FUNC(void, OS_CODE) RE_BSW_OsTask_1ms(void)
{
    osTask_1ms_cnt++;
}

FUNC(void, OS_CODE) RE_BSW_OsTask_2ms(void)
{
    osTask_2ms_cnt++;
}

FUNC(void, OS_CODE) RE_BSW_OsTask_5ms(void)
{
    osTask_5ms_cnt++;
}

FUNC(void, OS_CODE) RE_BSW_OsTask_10ms(void)
{
    osTask_10ms_cnt++;
}

FUNC(void, OS_CODE) RE_BSW_OsTask_50ms(void)
{
    osTask_50ms_cnt++;
}
