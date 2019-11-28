/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_1/test_bench.v";
static unsigned int ng1[] = {6U, 0U};
static unsigned int ng2[] = {128U, 0U};
static int ng3[] = {0, 0};



static void Initial_43_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);

LAB4:    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    goto LAB1;

}


extern void work_m_00000000002770943091_2578365841_init()
{
	static char *pe[] = {(void *)Initial_43_0};
	xsi_register_didat("work_m_00000000002770943091_2578365841", "isim/test_bench_isim_beh.exe.sim/work/m_00000000002770943091_2578365841.didat");
	xsi_register_executes(pe);
}
