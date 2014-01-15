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
static const char *ng0 = "C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/Control_test.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {4097U, 0U};
static unsigned int ng4[] = {1026U, 0U};
static int ng5[] = {2, 0};
static unsigned int ng6[] = {3075U, 0U};
static int ng7[] = {3, 0};
static unsigned int ng8[] = {4100U, 0U};
static int ng9[] = {4, 0};
static unsigned int ng10[] = {7173U, 0U};
static int ng11[] = {5, 0};
static unsigned int ng12[] = {5126U, 0U};
static int ng13[] = {6, 0};
static unsigned int ng14[] = {4103U, 0U};
static int ng15[] = {7, 0};
static unsigned int ng16[] = {8U, 0U};
static int ng17[] = {8, 0};
static unsigned int ng18[] = {31753U, 0U};



static void Initial_57_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

LAB0:    t1 = (t0 + 4104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);

LAB4:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3024);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3912);
    xsi_process_wait(t2, 50000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 3912);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 3184);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    goto LAB1;

}

static void Always_73_1(char *t0)
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

LAB0:    t1 = (t0 + 4352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(74, ng0);

LAB4:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 4160);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(76, ng0);
    t4 = (t0 + 2864);
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
    t24 = (t0 + 2864);
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

static void Always_79_2(char *t0)
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

LAB0:    t1 = (t0 + 4600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4920);
    *((int *)t2) = 1;
    t3 = (t0 + 4632);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(80, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4408);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(81, ng0);
    t6 = (t0 + 1344U);
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

LAB22:    t2 = ((char*)((ng15)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng17)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 11, t2, 32);
    if (t8 == 1)
        goto LAB25;

LAB26:
LAB27:    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 4408);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB9:    xsi_set_current_line(82, ng0);
    t9 = ((char*)((ng3)));
    t10 = (t0 + 3024);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 16);
    goto LAB27;

LAB11:    xsi_set_current_line(83, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB13:    xsi_set_current_line(84, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB15:    xsi_set_current_line(85, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB17:    xsi_set_current_line(86, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB19:    xsi_set_current_line(87, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB21:    xsi_set_current_line(88, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB23:    xsi_set_current_line(89, ng0);
    t3 = ((char*)((ng16)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

LAB25:    xsi_set_current_line(90, ng0);
    t3 = ((char*)((ng18)));
    t4 = (t0 + 3024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    goto LAB27;

}


extern void work_m_00000000001485097589_1283420335_init()
{
	static char *pe[] = {(void *)Initial_57_0,(void *)Always_73_1,(void *)Always_79_2};
	xsi_register_didat("work_m_00000000001485097589_1283420335", "isim/Control_test_isim_beh.exe.sim/work/m_00000000001485097589_1283420335.didat");
	xsi_register_executes(pe);
}
