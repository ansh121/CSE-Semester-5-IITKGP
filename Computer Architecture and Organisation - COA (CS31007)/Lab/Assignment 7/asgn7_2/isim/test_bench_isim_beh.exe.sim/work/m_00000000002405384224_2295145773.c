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
static const char *ng0 = "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2/Mult_3.v";
static int ng1[] = {0, 0};
static int ng2[] = {16, 0};
static int ng3[] = {15, 0};



static void Cont_105_0(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 2848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 15);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 15);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 3512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 3416);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Always_106_1(char *t0)
{
    char t6[8];
    char t30[8];
    char t31[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    int t40;

LAB0:    t1 = (t0 + 3096U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 3432);
    *((int *)t2) = 1;
    t3 = (t0 + 3128);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(107, ng0);

LAB5:    xsi_set_current_line(108, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB14;

LAB13:    t5 = (t2 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB14;

LAB17:    if (*((unsigned int *)t3) < *((unsigned int *)t2))
        goto LAB15;

LAB16:    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t2) = t14;
    t5 = (t0 + 1928);
    t7 = (t0 + 1928);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t30, t21, 2, t22, 32, 1);
    t28 = (t30 + 4);
    t15 = *((unsigned int *)t28);
    t40 = (!(t15));
    if (t40 == 1)
        goto LAB21;

LAB22:
LAB20:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(109, ng0);
    t28 = (t0 + 1048U);
    t29 = *((char **)t28);
    t28 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t28, t29, 0, 0, 16, 0LL);
    goto LAB12;

LAB14:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;
    goto LAB16;

LAB18:    xsi_set_current_line(111, ng0);
    t21 = (t0 + 1928);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    memset(t31, 0, 8);
    t29 = (t31 + 4);
    t32 = (t28 + 4);
    t14 = *((unsigned int *)t28);
    t15 = (t14 >> 15);
    t16 = (t15 & 1);
    *((unsigned int *)t31) = t16;
    t17 = *((unsigned int *)t32);
    t18 = (t17 >> 15);
    t19 = (t18 & 1);
    *((unsigned int *)t29) = t19;
    t34 = (t0 + 1928);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memset(t33, 0, 8);
    t37 = (t33 + 4);
    t38 = (t36 + 4);
    t20 = *((unsigned int *)t36);
    t23 = (t20 >> 0);
    *((unsigned int *)t33) = t23;
    t24 = *((unsigned int *)t38);
    t25 = (t24 >> 0);
    *((unsigned int *)t37) = t25;
    t26 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t26 & 32767U);
    t27 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t27 & 32767U);
    xsi_vlogtype_concat(t30, 16, 16, 2U, t33, 15, t31, 1);
    t39 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t39, t30, 0, 0, 16, 0LL);
    goto LAB20;

LAB21:    xsi_vlogvar_wait_assign_value(t5, t6, 0, *((unsigned int *)t30), 1, 0LL);
    goto LAB22;

}


extern void work_m_00000000002405384224_2295145773_init()
{
	static char *pe[] = {(void *)Cont_105_0,(void *)Always_106_1};
	xsi_register_didat("work_m_00000000002405384224_2295145773", "isim/test_bench_isim_beh.exe.sim/work/m_00000000002405384224_2295145773.didat");
	xsi_register_executes(pe);
}
