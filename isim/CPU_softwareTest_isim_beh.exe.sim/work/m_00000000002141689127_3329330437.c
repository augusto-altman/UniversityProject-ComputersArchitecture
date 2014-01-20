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
static const char *ng0 = "C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/CPU_softwareTest.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {6145U, 0U};
static unsigned int ng4[] = {2048U, 0U};
static int ng5[] = {2, 0};
static unsigned int ng6[] = {4096U, 0U};
static int ng7[] = {3, 0};
static unsigned int ng8[] = {10241U, 0U};
static int ng9[] = {4, 0};



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

static void Always_89_2(char *t0)
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

LAB2:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 5304);
    *((int *)t2) = 1;
    t3 = (t0 + 4768);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(90, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4544);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(91, ng0);
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

LAB18:
LAB19:    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 4544);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB9:    xsi_set_current_line(92, ng0);
    t9 = ((char*)((ng3)));
    t10 = (t0 + 2680);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 16);
    goto LAB19;

LAB11:    xsi_set_current_line(93, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB19;

LAB13:    xsi_set_current_line(94, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB19;

LAB15:    xsi_set_current_line(95, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB19;

LAB17:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2680);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB19;

}

static void Always_102_3(char *t0)
{
    char t17[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;

LAB0:    t1 = (t0 + 4984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 5320);
    *((int *)t2) = 1;
    t3 = (t0 + 5016);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(103, ng0);

LAB5:    t4 = (t0 + 576);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4792);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(104, ng0);
    t6 = (t0 + 3160);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB19;

LAB20:
LAB21:
LAB18:
LAB10:    t2 = (t0 + 576);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 4792);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB8:    xsi_set_current_line(105, ng0);

LAB11:    xsi_set_current_line(106, ng0);
    t15 = ((char*)((ng1)));
    t16 = (t0 + 3320);
    t19 = (t0 + 3320);
    t20 = (t19 + 72U);
    t21 = *((char **)t20);
    t22 = (t0 + 3320);
    t23 = (t22 + 64U);
    t24 = *((char **)t23);
    t25 = ((char*)((ng1)));
    xsi_vlog_generic_convert_array_indices(t17, t18, t21, t24, 2, 1, t25, 32, 1);
    t26 = (t17 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t18 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB12;

LAB13:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    t4 = (t0 + 3320);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 3320);
    t8 = (t7 + 64U);
    t9 = *((char **)t8);
    t15 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t17, t18, t6, t9, 2, 1, t15, 32, 1);
    t16 = (t17 + 4);
    t10 = *((unsigned int *)t16);
    t28 = (!(t10));
    t19 = (t18 + 4);
    t11 = *((unsigned int *)t19);
    t31 = (!(t11));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB14;

LAB15:    goto LAB10;

LAB12:    t33 = *((unsigned int *)t17);
    t34 = *((unsigned int *)t18);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t16, t15, 0, *((unsigned int *)t18), t36);
    goto LAB13;

LAB14:    t12 = *((unsigned int *)t17);
    t13 = *((unsigned int *)t18);
    t35 = (t12 - t13);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t18), t36);
    goto LAB15;

LAB16:    xsi_set_current_line(110, ng0);
    t4 = (t0 + 3320);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3320);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t15 = (t0 + 3320);
    t16 = (t15 + 64U);
    t19 = *((char **)t16);
    t20 = (t0 + 2120U);
    t21 = *((char **)t20);
    xsi_vlog_generic_get_array_select_value(t17, 16, t6, t9, t19, 2, 1, t21, 11, 2);
    t20 = (t0 + 2840);
    xsi_vlogvar_assign_value(t20, t17, 0, 0, 16);
    goto LAB18;

LAB19:    xsi_set_current_line(112, ng0);
    t4 = (t0 + 2280U);
    t5 = *((char **)t4);
    t4 = (t0 + 3320);
    t6 = (t0 + 3320);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3320);
    t15 = (t9 + 64U);
    t16 = *((char **)t15);
    t19 = (t0 + 2120U);
    t20 = *((char **)t19);
    xsi_vlog_generic_convert_array_indices(t17, t18, t8, t16, 2, 1, t20, 11, 2);
    t19 = (t17 + 4);
    t27 = *((unsigned int *)t19);
    t28 = (!(t27));
    t21 = (t18 + 4);
    t30 = *((unsigned int *)t21);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB22;

LAB23:    goto LAB21;

LAB22:    t33 = *((unsigned int *)t17);
    t34 = *((unsigned int *)t18);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t4, t5, 0, *((unsigned int *)t18), t36);
    goto LAB23;

}


extern void work_m_00000000002141689127_3329330437_init()
{
	static char *pe[] = {(void *)Initial_53_0,(void *)Always_68_1,(void *)Always_89_2,(void *)Always_102_3};
	xsi_register_didat("work_m_00000000002141689127_3329330437", "isim/CPU_softwareTest_isim_beh.exe.sim/work/m_00000000002141689127_3329330437.didat");
	xsi_register_executes(pe);
}
