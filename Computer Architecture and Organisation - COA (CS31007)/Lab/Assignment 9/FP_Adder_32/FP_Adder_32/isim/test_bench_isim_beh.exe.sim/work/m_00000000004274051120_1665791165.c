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
static const char *ng0 = "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 9/FP_Adder_32/FP_Adder_32/FP_adder_32.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0, 0, 0};
static unsigned int ng3[] = {1U, 0U};



static void Always_45_0(char *t0)
{
    char t6[8];
    char t30[8];
    char t31[8];
    char t32[16];
    char t33[8];
    char t44[8];
    char t55[8];
    char t56[8];
    char t57[8];
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
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t58;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3648);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(45, ng0);

LAB5:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 1208U);
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

LAB11:    xsi_set_current_line(50, ng0);

LAB14:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 23);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 23);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 255U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 255U);
    t5 = (t0 + 1688U);
    t7 = *((char **)t5);
    memset(t30, 0, 8);
    t5 = (t30 + 4);
    t8 = (t7 + 4);
    t15 = *((unsigned int *)t7);
    t16 = (t15 >> 23);
    *((unsigned int *)t30) = t16;
    t17 = *((unsigned int *)t8);
    t18 = (t17 >> 23);
    *((unsigned int *)t5) = t18;
    t19 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t19 & 255U);
    t20 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t20 & 255U);
    memset(t31, 0, 8);
    t21 = (t6 + 4);
    if (*((unsigned int *)t21) != 0)
        goto LAB16;

LAB15:    t22 = (t30 + 4);
    if (*((unsigned int *)t22) != 0)
        goto LAB16;

LAB19:    if (*((unsigned int *)t6) < *((unsigned int *)t30))
        goto LAB17;

LAB18:    t29 = (t31 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t31);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(55, ng0);

LAB24:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 8388607U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 8388607U);
    t5 = ((char*)((ng3)));
    t7 = (t0 + 1528U);
    t8 = *((char **)t7);
    memset(t30, 0, 8);
    t7 = (t30 + 4);
    t21 = (t8 + 4);
    t15 = *((unsigned int *)t8);
    t16 = (t15 >> 23);
    *((unsigned int *)t30) = t16;
    t17 = *((unsigned int *)t21);
    t18 = (t17 >> 23);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t19 & 511U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 511U);
    xsi_vlogtype_concat(t32, 33, 33, 3U, t30, 9, t5, 1, t6, 23);
    t22 = (t0 + 2248);
    xsi_vlogvar_assign_value(t22, t32, 0, 0, 33);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t30, 0, 8);
    t2 = (t30 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t30) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t13 & 8388607U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 8388607U);
    t5 = ((char*)((ng3)));
    xsi_vlogtype_concat(t6, 24, 24, 2U, t5, 1, t30, 23);
    t7 = (t0 + 1528U);
    t8 = *((char **)t7);
    memset(t31, 0, 8);
    t7 = (t31 + 4);
    t21 = (t8 + 4);
    t15 = *((unsigned int *)t8);
    t16 = (t15 >> 23);
    *((unsigned int *)t31) = t16;
    t17 = *((unsigned int *)t21);
    t18 = (t17 >> 23);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t19 & 255U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 255U);
    t22 = (t0 + 1688U);
    t28 = *((char **)t22);
    memset(t33, 0, 8);
    t22 = (t33 + 4);
    t29 = (t28 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (t23 >> 23);
    *((unsigned int *)t33) = t24;
    t25 = *((unsigned int *)t29);
    t26 = (t25 >> 23);
    *((unsigned int *)t22) = t26;
    t27 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t27 & 255U);
    t37 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t37 & 255U);
    memset(t44, 0, 8);
    xsi_vlog_unsigned_minus(t44, 8, t31, 8, t33, 8);
    memset(t55, 0, 8);
    xsi_vlog_unsigned_rshift(t55, 24, t6, 24, t44, 8);
    t34 = (t0 + 1528U);
    t35 = *((char **)t34);
    memset(t56, 0, 8);
    t34 = (t56 + 4);
    t36 = (t35 + 4);
    t38 = *((unsigned int *)t35);
    t39 = (t38 >> 23);
    *((unsigned int *)t56) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 >> 23);
    *((unsigned int *)t34) = t41;
    t42 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t42 & 255U);
    t48 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t48 & 255U);
    t43 = (t0 + 1688U);
    t45 = *((char **)t43);
    memset(t57, 0, 8);
    t43 = (t57 + 4);
    t46 = (t45 + 4);
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 31);
    t51 = (t50 & 1);
    *((unsigned int *)t57) = t51;
    t52 = *((unsigned int *)t46);
    t53 = (t52 >> 31);
    t58 = (t53 & 1);
    *((unsigned int *)t43) = t58;
    xsi_vlogtype_concat(t32, 33, 33, 3U, t57, 1, t56, 8, t55, 24);
    t47 = (t0 + 2408);
    xsi_vlogvar_assign_value(t47, t32, 0, 0, 33);

LAB22:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(46, ng0);

LAB13:    xsi_set_current_line(47, ng0);
    t28 = ((char*)((ng2)));
    t29 = (t0 + 2248);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 33);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 33);
    goto LAB12;

LAB16:    t28 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB18;

LAB17:    *((unsigned int *)t31) = 1;
    goto LAB18;

LAB20:    xsi_set_current_line(51, ng0);

LAB23:    xsi_set_current_line(52, ng0);
    t34 = (t0 + 1688U);
    t35 = *((char **)t34);
    memset(t33, 0, 8);
    t34 = (t33 + 4);
    t36 = (t35 + 4);
    t37 = *((unsigned int *)t35);
    t38 = (t37 >> 0);
    *((unsigned int *)t33) = t38;
    t39 = *((unsigned int *)t36);
    t40 = (t39 >> 0);
    *((unsigned int *)t34) = t40;
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 & 8388607U);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 8388607U);
    t43 = ((char*)((ng3)));
    t45 = (t0 + 1688U);
    t46 = *((char **)t45);
    memset(t44, 0, 8);
    t45 = (t44 + 4);
    t47 = (t46 + 4);
    t48 = *((unsigned int *)t46);
    t49 = (t48 >> 23);
    *((unsigned int *)t44) = t49;
    t50 = *((unsigned int *)t47);
    t51 = (t50 >> 23);
    *((unsigned int *)t45) = t51;
    t52 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t52 & 511U);
    t53 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t53 & 511U);
    xsi_vlogtype_concat(t32, 33, 33, 3U, t44, 9, t43, 1, t33, 23);
    t54 = (t0 + 2408);
    xsi_vlogvar_assign_value(t54, t32, 0, 0, 33);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t30, 0, 8);
    t2 = (t30 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t30) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t13 & 8388607U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 8388607U);
    t5 = ((char*)((ng3)));
    xsi_vlogtype_concat(t6, 24, 24, 2U, t5, 1, t30, 23);
    t7 = (t0 + 1688U);
    t8 = *((char **)t7);
    memset(t31, 0, 8);
    t7 = (t31 + 4);
    t21 = (t8 + 4);
    t15 = *((unsigned int *)t8);
    t16 = (t15 >> 23);
    *((unsigned int *)t31) = t16;
    t17 = *((unsigned int *)t21);
    t18 = (t17 >> 23);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t19 & 255U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 255U);
    t22 = (t0 + 1528U);
    t28 = *((char **)t22);
    memset(t33, 0, 8);
    t22 = (t33 + 4);
    t29 = (t28 + 4);
    t23 = *((unsigned int *)t28);
    t24 = (t23 >> 23);
    *((unsigned int *)t33) = t24;
    t25 = *((unsigned int *)t29);
    t26 = (t25 >> 23);
    *((unsigned int *)t22) = t26;
    t27 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t27 & 255U);
    t37 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t37 & 255U);
    memset(t44, 0, 8);
    xsi_vlog_unsigned_minus(t44, 8, t31, 8, t33, 8);
    memset(t55, 0, 8);
    xsi_vlog_unsigned_rshift(t55, 24, t6, 24, t44, 8);
    t34 = (t0 + 1688U);
    t35 = *((char **)t34);
    memset(t56, 0, 8);
    t34 = (t56 + 4);
    t36 = (t35 + 4);
    t38 = *((unsigned int *)t35);
    t39 = (t38 >> 23);
    *((unsigned int *)t56) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 >> 23);
    *((unsigned int *)t34) = t41;
    t42 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t42 & 255U);
    t48 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t48 & 255U);
    t43 = (t0 + 1528U);
    t45 = *((char **)t43);
    memset(t57, 0, 8);
    t43 = (t57 + 4);
    t46 = (t45 + 4);
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 31);
    t51 = (t50 & 1);
    *((unsigned int *)t57) = t51;
    t52 = *((unsigned int *)t46);
    t53 = (t52 >> 31);
    t58 = (t53 & 1);
    *((unsigned int *)t43) = t58;
    xsi_vlogtype_concat(t32, 33, 33, 3U, t57, 1, t56, 8, t55, 24);
    t47 = (t0 + 2248);
    xsi_vlogvar_assign_value(t47, t32, 0, 0, 33);
    goto LAB22;

}


extern void work_m_00000000004274051120_1665791165_init()
{
	static char *pe[] = {(void *)Always_45_0};
	xsi_register_didat("work_m_00000000004274051120_1665791165", "isim/test_bench_isim_beh.exe.sim/work/m_00000000004274051120_1665791165.didat");
	xsi_register_executes(pe);
}
