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
static const char *ng0 = "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2/test_bench.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {3U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {42407U, 0U};



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

LAB4:    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB18;
    goto LAB1;

LAB18:    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB19:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB20:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB21:    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB22;
    goto LAB1;

LAB22:    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB23:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB24:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB25:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB26:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB27:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB29:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB30;
    goto LAB1;

LAB30:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB31:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB32:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB33:    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB34:    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB35:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB36:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB37:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB38:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB39:    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB40:    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB41:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB42:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB43:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB44;
    goto LAB1;

LAB44:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB45:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB46;
    goto LAB1;

LAB46:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB47:    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB48:    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB49:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB50;
    goto LAB1;

LAB50:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB51;
    goto LAB1;

LAB51:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB52;
    goto LAB1;

LAB52:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB53;
    goto LAB1;

LAB53:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB54;
    goto LAB1;

LAB54:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB55:    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB56;
    goto LAB1;

LAB56:    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB57:    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB58;
    goto LAB1;

LAB58:    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB59:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB60:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB61;
    goto LAB1;

LAB61:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB62;
    goto LAB1;

LAB62:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB63;
    goto LAB1;

LAB63:    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB64;
    goto LAB1;

LAB64:    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB65;
    goto LAB1;

LAB65:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB66;
    goto LAB1;

LAB66:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB67:    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB68;
    goto LAB1;

LAB68:    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB69:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB70;
    goto LAB1;

LAB70:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB71:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB72;
    goto LAB1;

LAB72:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB73;
    goto LAB1;

LAB73:    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB74;
    goto LAB1;

LAB74:    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB75:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB76;
    goto LAB1;

LAB76:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB1;

}


extern void work_m_00000000001127530810_2578365841_init()
{
	static char *pe[] = {(void *)Initial_43_0};
	xsi_register_didat("work_m_00000000001127530810_2578365841", "isim/test_bench_isim_beh.exe.sim/work/m_00000000001127530810_2578365841.didat");
	xsi_register_executes(pe);
}
