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

/* This file is designed for use with ISim build 0xc3576ebc */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/CPU_softwareTest4.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {6145U, 0U};
static unsigned int ng4[] = {2048U, 0U};
static int ng5[] = {2, 0};
static unsigned int ng6[] = {6146U, 0U};
static int ng7[] = {3, 0};
static unsigned int ng8[] = {2049U, 0U};
static int ng9[] = {4, 0};
static unsigned int ng10[] = {4096U, 0U};
static int ng11[] = {5, 0};
static unsigned int ng12[] = {8193U, 0U};
static int ng13[] = {6, 0};
static unsigned int ng14[] = {2050U, 0U};



static void Initial_53_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

LAB0:    t1 = (t0 + 4240U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);

LAB4:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, 50000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(64, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 3160);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    goto LAB1;

}

static void Always_68_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);

LAB4:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(71, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 3000);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

}

static void Always_92_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 5304);
    *((int *)t2) = 1;
    t3 = (t0 + 4768);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(93, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4544);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(94, ng0);
    t6 = (t0 + 1640U);
    t7 = *((char **)t6);

LAB8:    t6 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t6, 32);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB21;

LAB22:
LAB23:    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 4544);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB9:    xsi_set_current_line(95, ng0);
    t9 = ((char*)((ng3)));
    t10 = (t0 + 2680);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 16);
    goto LAB23;

LAB11:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

LAB13:    xsi_set_current_line(97, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

LAB15:    xsi_set_current_line(98, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

LAB17:    xsi_set_current_line(99, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

LAB19:    xsi_set_current_line(100, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

LAB21:    xsi_set_current_line(101, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB23;

}

static void Always_108_3(char *t0)
{
    char t18[8];
    char t19[8];
    char t46[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    int t29;
    char *t30;
    unsigned int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;

LAB0:    t1 = (t0 + 4984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 5320);
    *((int *)t2) = 1;
    t3 = (t0 + 5016);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(109, ng0);

LAB5:    t4 = (t0 + 576);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4792);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(110, ng0);
    t6 = (t0 + 4792);
    xsi_process_wait(t6, 10000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB6:    t3 = (t0 + 4792);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB8:    xsi_set_current_line(111, ng0);
    t7 = (t0 + 3160);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t9);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t18, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t2);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t28 = (t14 ^ t15);
    t31 = (t13 | t28);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t5);
    t38 = (t34 | t35);
    t39 = (~(t38));
    t40 = (t31 & t39);
    if (t40 != 0)
        goto LAB22;

LAB19:    if (t38 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t18) = 1;

LAB22:    t7 = (t18 + 4);
    t41 = *((unsigned int *)t7);
    t42 = (~(t41));
    t43 = *((unsigned int *)t18);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t18, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t2);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t28 = (t14 ^ t15);
    t31 = (t13 | t28);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t5);
    t38 = (t34 | t35);
    t39 = (~(t38));
    t40 = (t31 & t39);
    if (t40 != 0)
        goto LAB30;

LAB27:    if (t38 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t18) = 1;

LAB30:    t7 = (t18 + 4);
    t41 = *((unsigned int *)t7);
    t42 = (~(t41));
    t43 = *((unsigned int *)t18);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB31;

LAB32:
LAB33:
LAB25:
LAB11:    t2 = (t0 + 576);
    xsi_vlog_namedbase_popprocess(t2);
    goto LAB6;

LAB9:    xsi_set_current_line(112, ng0);

LAB12:    xsi_set_current_line(113, ng0);
    t16 = ((char*)((ng1)));
    t17 = (t0 + 3320);
    t20 = (t0 + 3320);
    t21 = (t20 + 72U);
    t22 = *((char **)t21);
    t23 = (t0 + 3320);
    t24 = (t23 + 64U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlog_generic_convert_array_indices(t18, t19, t22, t25, 2, 1, t26, 32, 1);
    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (!(t28));
    t30 = (t19 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = (t29 && t32);
    if (t33 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    t4 = (t0 + 3320);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 3320);
    t8 = (t7 + 64U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t18, t19, t6, t9, 2, 1, t10, 32, 1);
    t16 = (t18 + 4);
    t11 = *((unsigned int *)t16);
    t29 = (!(t11));
    t17 = (t19 + 4);
    t12 = *((unsigned int *)t17);
    t32 = (!(t12));
    t33 = (t29 && t32);
    if (t33 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    t4 = (t0 + 3320);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 3320);
    t8 = (t7 + 64U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t18, t19, t6, t9, 2, 1, t10, 32, 1);
    t16 = (t18 + 4);
    t11 = *((unsigned int *)t16);
    t29 = (!(t11));
    t17 = (t19 + 4);
    t12 = *((unsigned int *)t17);
    t32 = (!(t12));
    t33 = (t29 && t32);
    if (t33 == 1)
        goto LAB17;

LAB18:    goto LAB11;

LAB13:    t34 = *((unsigned int *)t18);
    t35 = *((unsigned int *)t19);
    t36 = (t34 - t35);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, *((unsigned int *)t19), t37, 0LL);
    goto LAB14;

LAB15:    t13 = *((unsigned int *)t18);
    t14 = *((unsigned int *)t19);
    t36 = (t13 - t14);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t19), t37, 0LL);
    goto LAB16;

LAB17:    t13 = *((unsigned int *)t18);
    t14 = *((unsigned int *)t19);
    t36 = (t13 - t14);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t19), t37, 0LL);
    goto LAB18;

LAB21:    t6 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(118, ng0);

LAB26:    xsi_set_current_line(119, ng0);
    t8 = (t0 + 3320);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t16 = (t0 + 3320);
    t17 = (t16 + 72U);
    t20 = *((char **)t17);
    t21 = (t0 + 3320);
    t22 = (t21 + 64U);
    t23 = *((char **)t22);
    t24 = (t0 + 2120U);
    t25 = *((char **)t24);
    xsi_vlog_generic_get_array_select_value(t19, 16, t10, t20, t23, 2, 1, t25, 11, 2);
    t24 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t24, t19, 0, 0, 16, 0LL);
    goto LAB25;

LAB29:    t6 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(122, ng0);

LAB34:    xsi_set_current_line(123, ng0);
    t8 = (t0 + 2280U);
    t9 = *((char **)t8);
    t8 = (t0 + 3320);
    t10 = (t0 + 3320);
    t16 = (t10 + 72U);
    t17 = *((char **)t16);
    t20 = (t0 + 3320);
    t21 = (t20 + 64U);
    t22 = *((char **)t21);
    t23 = (t0 + 2120U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_array_indices(t19, t46, t17, t22, 2, 1, t24, 11, 2);
    t23 = (t19 + 4);
    t47 = *((unsigned int *)t23);
    t29 = (!(t47));
    t25 = (t46 + 4);
    t48 = *((unsigned int *)t25);
    t32 = (!(t48));
    t33 = (t29 && t32);
    if (t33 == 1)
        goto LAB35;

LAB36:    goto LAB33;

LAB35:    t49 = *((unsigned int *)t19);
    t50 = *((unsigned int *)t46);
    t36 = (t49 - t50);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t8, t9, 0, *((unsigned int *)t46), t37, 0LL);
    goto LAB36;

}


extern void work_m_00000000002141689127_3602823924_init()
{
	static char *pe[] = {(void *)Initial_53_0,(void *)Always_68_1,(void *)Always_92_2,(void *)Always_108_3};
	xsi_register_didat("work_m_00000000002141689127_3602823924", "isim/CPU_softwareTest4_isim_beh.exe.sim/work/m_00000000002141689127_3602823924.didat");
	xsi_register_executes(pe);
}
