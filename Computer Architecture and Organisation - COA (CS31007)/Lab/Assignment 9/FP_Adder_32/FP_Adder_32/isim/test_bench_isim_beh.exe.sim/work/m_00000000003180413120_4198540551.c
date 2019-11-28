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



static void Always_75_0(char *t0)
{
    char t6[8];
    char t30[8];
    char t31[8];
    char t46[16];
    char t47[8];
    char t57[8];
    char t67[8];
    char t68[8];
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
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t69;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;

LAB0:    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 3488);
    *((int *)t2) = 1;
    t3 = (t0 + 3200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(75, ng0);

LAB5:    xsi_set_current_line(76, ng0);
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

LAB11:    xsi_set_current_line(79, ng0);

LAB14:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 8);
    t5 = (t3 + 12);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t2) = t14;
    t7 = (t0 + 1688U);
    t8 = *((char **)t7);
    memset(t30, 0, 8);
    t7 = (t30 + 4);
    t21 = (t8 + 8);
    t22 = (t8 + 12);
    t15 = *((unsigned int *)t21);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t30) = t17;
    t18 = *((unsigned int *)t22);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t7) = t20;
    memset(t31, 0, 8);
    t28 = (t6 + 4);
    t29 = (t30 + 4);
    t23 = *((unsigned int *)t6);
    t24 = *((unsigned int *)t30);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t28);
    t27 = *((unsigned int *)t29);
    t32 = (t26 ^ t27);
    t33 = (t25 | t32);
    t34 = *((unsigned int *)t28);
    t35 = *((unsigned int *)t29);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB18;

LAB15:    if (t36 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t31) = 1;

LAB18:    t40 = (t31 + 4);
    t41 = *((unsigned int *)t40);
    t42 = (~(t41));
    t43 = *((unsigned int *)t31);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(82, ng0);
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
    *((unsigned int *)t6) = (t13 & 16777215U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 16777215U);
    t5 = (t0 + 1688U);
    t7 = *((char **)t5);
    memset(t30, 0, 8);
    t5 = (t30 + 4);
    t8 = (t7 + 4);
    t15 = *((unsigned int *)t7);
    t16 = (t15 >> 0);
    *((unsigned int *)t30) = t16;
    t17 = *((unsigned int *)t8);
    t18 = (t17 >> 0);
    *((unsigned int *)t5) = t18;
    t19 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t19 & 16777215U);
    t20 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t20 & 16777215U);
    memset(t31, 0, 8);
    t21 = (t6 + 4);
    if (*((unsigned int *)t21) != 0)
        goto LAB23;

LAB22:    t22 = (t30 + 4);
    if (*((unsigned int *)t22) != 0)
        goto LAB23;

LAB26:    if (*((unsigned int *)t6) > *((unsigned int *)t30))
        goto LAB24;

LAB25:    t29 = (t31 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t31);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1688U);
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
    *((unsigned int *)t6) = (t13 & 16777215U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 16777215U);
    t5 = (t0 + 1528U);
    t7 = *((char **)t5);
    memset(t30, 0, 8);
    t5 = (t30 + 4);
    t8 = (t7 + 4);
    t15 = *((unsigned int *)t7);
    t16 = (t15 >> 0);
    *((unsigned int *)t30) = t16;
    t17 = *((unsigned int *)t8);
    t18 = (t17 >> 0);
    *((unsigned int *)t5) = t18;
    t19 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t19 & 16777215U);
    t20 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t20 & 16777215U);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_minus(t31, 24, t6, 24, t30, 24);
    t21 = (t0 + 1688U);
    t22 = *((char **)t21);
    memset(t47, 0, 8);
    t21 = (t47 + 4);
    t28 = (t22 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (t23 >> 24);
    *((unsigned int *)t47) = t24;
    t25 = *((unsigned int *)t28);
    t26 = (t25 >> 24);
    *((unsigned int *)t21) = t26;
    t29 = (t22 + 8);
    t39 = (t22 + 12);
    t27 = *((unsigned int *)t29);
    t32 = (t27 << 8);
    t33 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t33 | t32);
    t34 = *((unsigned int *)t39);
    t35 = (t34 << 8);
    t36 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t36 | t35);
    t37 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t37 & 511U);
    t38 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t38 & 511U);
    xsi_vlogtype_concat(t46, 34, 33, 2U, t47, 9, t31, 24);
    t40 = (t0 + 2248);
    xsi_vlogvar_assign_value(t40, t46, 0, 0, 34);

LAB29:
LAB21:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(76, ng0);

LAB13:    xsi_set_current_line(77, ng0);
    t28 = ((char*)((ng2)));
    t29 = (t0 + 2248);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 34);
    goto LAB12;

LAB17:    t39 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(81, ng0);
    t48 = (t0 + 1528U);
    t49 = *((char **)t48);
    memset(t47, 0, 8);
    t48 = (t47 + 4);
    t50 = (t49 + 4);
    t51 = *((unsigned int *)t49);
    t52 = (t51 >> 0);
    *((unsigned int *)t47) = t52;
    t53 = *((unsigned int *)t50);
    t54 = (t53 >> 0);
    *((unsigned int *)t48) = t54;
    t55 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t55 & 16777215U);
    t56 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t56 & 16777215U);
    t58 = (t0 + 1688U);
    t59 = *((char **)t58);
    memset(t57, 0, 8);
    t58 = (t57 + 4);
    t60 = (t59 + 4);
    t61 = *((unsigned int *)t59);
    t62 = (t61 >> 0);
    *((unsigned int *)t57) = t62;
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 0);
    *((unsigned int *)t58) = t64;
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 16777215U);
    t66 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t66 & 16777215U);
    memset(t67, 0, 8);
    xsi_vlog_unsigned_add(t67, 24, t47, 24, t57, 24);
    t69 = (t0 + 1528U);
    t70 = *((char **)t69);
    memset(t68, 0, 8);
    t69 = (t68 + 4);
    t71 = (t70 + 4);
    t72 = *((unsigned int *)t70);
    t73 = (t72 >> 24);
    *((unsigned int *)t68) = t73;
    t74 = *((unsigned int *)t71);
    t75 = (t74 >> 24);
    *((unsigned int *)t69) = t75;
    t76 = (t70 + 8);
    t77 = (t70 + 12);
    t78 = *((unsigned int *)t76);
    t79 = (t78 << 8);
    t80 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t80 | t79);
    t81 = *((unsigned int *)t77);
    t82 = (t81 << 8);
    t83 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t83 | t82);
    t84 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t84 & 511U);
    t85 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t85 & 511U);
    xsi_vlogtype_concat(t46, 34, 33, 2U, t68, 9, t67, 24);
    t86 = (t0 + 2248);
    xsi_vlogvar_assign_value(t86, t46, 0, 0, 34);
    goto LAB21;

LAB23:    t28 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB25;

LAB24:    *((unsigned int *)t31) = 1;
    goto LAB25;

LAB27:    xsi_set_current_line(83, ng0);
    t39 = (t0 + 1528U);
    t40 = *((char **)t39);
    memset(t47, 0, 8);
    t39 = (t47 + 4);
    t48 = (t40 + 4);
    t32 = *((unsigned int *)t40);
    t33 = (t32 >> 0);
    *((unsigned int *)t47) = t33;
    t34 = *((unsigned int *)t48);
    t35 = (t34 >> 0);
    *((unsigned int *)t39) = t35;
    t36 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t36 & 16777215U);
    t37 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t37 & 16777215U);
    t49 = (t0 + 1688U);
    t50 = *((char **)t49);
    memset(t57, 0, 8);
    t49 = (t57 + 4);
    t58 = (t50 + 4);
    t38 = *((unsigned int *)t50);
    t41 = (t38 >> 0);
    *((unsigned int *)t57) = t41;
    t42 = *((unsigned int *)t58);
    t43 = (t42 >> 0);
    *((unsigned int *)t49) = t43;
    t44 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t44 & 16777215U);
    t45 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t45 & 16777215U);
    memset(t67, 0, 8);
    xsi_vlog_unsigned_minus(t67, 24, t47, 24, t57, 24);
    t59 = (t0 + 1528U);
    t60 = *((char **)t59);
    memset(t68, 0, 8);
    t59 = (t68 + 4);
    t69 = (t60 + 4);
    t51 = *((unsigned int *)t60);
    t52 = (t51 >> 24);
    *((unsigned int *)t68) = t52;
    t53 = *((unsigned int *)t69);
    t54 = (t53 >> 24);
    *((unsigned int *)t59) = t54;
    t70 = (t60 + 8);
    t71 = (t60 + 12);
    t55 = *((unsigned int *)t70);
    t56 = (t55 << 8);
    t61 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t61 | t56);
    t62 = *((unsigned int *)t71);
    t63 = (t62 << 8);
    t64 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t64 | t63);
    t65 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t65 & 511U);
    t66 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t66 & 511U);
    xsi_vlogtype_concat(t46, 34, 33, 2U, t68, 9, t67, 24);
    t76 = (t0 + 2248);
    xsi_vlogvar_assign_value(t76, t46, 0, 0, 34);
    goto LAB29;

}


extern void work_m_00000000003180413120_4198540551_init()
{
	static char *pe[] = {(void *)Always_75_0};
	xsi_register_didat("work_m_00000000003180413120_4198540551", "isim/test_bench_isim_beh.exe.sim/work/m_00000000003180413120_4198540551.didat");
	xsi_register_executes(pe);
}
