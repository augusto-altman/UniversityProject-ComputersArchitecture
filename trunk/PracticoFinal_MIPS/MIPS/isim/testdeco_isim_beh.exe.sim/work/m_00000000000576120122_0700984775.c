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
static const char *ng0 = "D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/debuger_decodificator.v";
static unsigned int ng1[] = {56U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {63U, 0U};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {1U, 0U};
static unsigned int ng6[] = {34U, 0U};
static unsigned int ng7[] = {2U, 0U};
static unsigned int ng8[] = {3U, 0U};
static unsigned int ng9[] = {4U, 0U};
static unsigned int ng10[] = {5U, 0U};
static unsigned int ng11[] = {6U, 0U};
static unsigned int ng12[] = {7U, 0U};
static unsigned int ng13[] = {9U, 0U};
static unsigned int ng14[] = {10U, 0U};
static unsigned int ng15[] = {11U, 0U};
static unsigned int ng16[] = {12U, 0U};
static unsigned int ng17[] = {13U, 0U};
static unsigned int ng18[] = {14U, 0U};
static unsigned int ng19[] = {15U, 0U};
static unsigned int ng20[] = {16U, 0U};
static unsigned int ng21[] = {17U, 0U};
static unsigned int ng22[] = {18U, 0U};
static unsigned int ng23[] = {19U, 0U};
static unsigned int ng24[] = {20U, 0U};
static unsigned int ng25[] = {21U, 0U};
static unsigned int ng26[] = {22U, 0U};
static unsigned int ng27[] = {23U, 0U};
static unsigned int ng28[] = {24U, 0U};
static unsigned int ng29[] = {25U, 0U};
static unsigned int ng30[] = {26U, 0U};
static unsigned int ng31[] = {27U, 0U};
static unsigned int ng32[] = {28U, 0U};
static unsigned int ng33[] = {29U, 0U};
static unsigned int ng34[] = {30U, 0U};
static unsigned int ng35[] = {31U, 0U};
static unsigned int ng36[] = {85U, 0U};
static unsigned int ng37[] = {255U, 0U};



static void Always_148_0(char *t0)
{
    char t4[8];
    char t18[8];
    char t19[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 7968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(148, ng0);
    t2 = (t0 + 8288);
    *((int *)t2) = 1;
    t3 = (t0 + 8000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(149, ng0);

LAB5:    xsi_set_current_line(150, ng0);
    t5 = (t0 + 1048U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t4 + 4);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (t8 >> 0);
    *((unsigned int *)t4) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 63U);
    t13 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t13 & 63U);

LAB6:    t14 = ((char*)((ng1)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 6, t14, 6);
    if (t15 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t15 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB13:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t18, 0, 8);
    t2 = (t18 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    *((unsigned int *)t18) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 0);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t12 & 63U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 63U);

LAB14:    t6 = ((char*)((ng5)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t6, 6);
    if (t15 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng9)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng10)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng11)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng12)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng13)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng14)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng15)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng16)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng17)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng18)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng19)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng20)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng21)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng22)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng23)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng24)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng25)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB55;

LAB56:    t2 = ((char*)((ng26)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng27)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng28)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng29)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB63;

LAB64:    t2 = ((char*)((ng30)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng31)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB67;

LAB68:    t2 = ((char*)((ng32)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB69;

LAB70:    t2 = ((char*)((ng33)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB71;

LAB72:    t2 = ((char*)((ng34)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB73;

LAB74:    t2 = ((char*)((ng35)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB75;

LAB76:    t2 = ((char*)((ng1)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB77;

LAB78:    t2 = ((char*)((ng3)));
    t15 = xsi_vlog_unsigned_case_compare(t18, 6, t2, 6);
    if (t15 == 1)
        goto LAB79;

LAB80:
LAB82:
LAB81:    xsi_set_current_line(196, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB83:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t19, 0, 8);
    t2 = (t19 + 4);
    t5 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 6);
    *((unsigned int *)t19) = t9;
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 6);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t12 & 3U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 3U);
    t6 = (t0 + 6888);
    xsi_vlogvar_assign_value(t6, t19, 0, 0, 2);
    goto LAB2;

LAB7:    xsi_set_current_line(151, ng0);
    t16 = ((char*)((ng2)));
    t17 = (t0 + 7048);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 1);
    goto LAB13;

LAB9:    xsi_set_current_line(152, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 7048);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    goto LAB13;

LAB15:    xsi_set_current_line(158, ng0);
    t7 = (t0 + 2168U);
    t14 = *((char **)t7);
    t7 = (t0 + 6728);
    xsi_vlogvar_assign_value(t7, t14, 0, 0, 32);
    goto LAB83;

LAB17:    xsi_set_current_line(159, ng0);
    t3 = (t0 + 2488U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB19:    xsi_set_current_line(161, ng0);
    t3 = (t0 + 3608U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB21:    xsi_set_current_line(162, ng0);
    t3 = (t0 + 4088U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB23:    xsi_set_current_line(163, ng0);
    t3 = (t0 + 4408U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB25:    xsi_set_current_line(164, ng0);
    t3 = (t0 + 4248U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB27:    xsi_set_current_line(165, ng0);
    t3 = (t0 + 5048U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB29:    xsi_set_current_line(166, ng0);
    t3 = (t0 + 4888U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB31:    xsi_set_current_line(168, ng0);
    t3 = (t0 + 3768U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB33:    xsi_set_current_line(169, ng0);
    t3 = (t0 + 2968U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB35:    xsi_set_current_line(170, ng0);
    t3 = (t0 + 3128U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB37:    xsi_set_current_line(171, ng0);
    t3 = (t0 + 3288U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB39:    xsi_set_current_line(172, ng0);
    t3 = (t0 + 4568U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB41:    xsi_set_current_line(173, ng0);
    t3 = (t0 + 4728U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB43:    xsi_set_current_line(174, ng0);
    t3 = (t0 + 3928U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB45:    xsi_set_current_line(176, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB47:    xsi_set_current_line(177, ng0);
    t3 = (t0 + 1528U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB49:    xsi_set_current_line(178, ng0);
    t3 = (t0 + 1688U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB51:    xsi_set_current_line(179, ng0);
    t3 = (t0 + 1848U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB53:    xsi_set_current_line(180, ng0);
    t3 = (t0 + 2008U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB55:    xsi_set_current_line(181, ng0);
    t3 = (t0 + 5688U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB57:    xsi_set_current_line(182, ng0);
    t3 = (t0 + 5208U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB59:    xsi_set_current_line(183, ng0);
    t3 = (t0 + 5848U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB61:    xsi_set_current_line(184, ng0);
    t3 = (t0 + 5368U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB63:    xsi_set_current_line(185, ng0);
    t3 = (t0 + 5528U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB65:    xsi_set_current_line(187, ng0);
    t3 = (t0 + 6008U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB67:    xsi_set_current_line(188, ng0);
    t3 = (t0 + 6168U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB69:    xsi_set_current_line(189, ng0);
    t3 = (t0 + 2648U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB71:    xsi_set_current_line(190, ng0);
    t3 = (t0 + 6328U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB73:    xsi_set_current_line(192, ng0);
    t3 = (t0 + 2328U);
    t5 = *((char **)t3);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    goto LAB83;

LAB75:    xsi_set_current_line(193, ng0);
    t3 = (t0 + 2808U);
    t5 = *((char **)t3);
    memcpy(t19, t5, 8);
    t3 = (t0 + 6728);
    xsi_vlogvar_assign_value(t3, t19, 0, 0, 32);
    goto LAB83;

LAB77:    xsi_set_current_line(194, ng0);
    t3 = ((char*)((ng36)));
    t5 = (t0 + 6728);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 32);
    goto LAB83;

LAB79:    xsi_set_current_line(195, ng0);
    t3 = ((char*)((ng37)));
    t5 = (t0 + 6728);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 32);
    goto LAB83;

}


extern void work_m_00000000000576120122_0700984775_init()
{
	static char *pe[] = {(void *)Always_148_0};
	xsi_register_didat("work_m_00000000000576120122_0700984775", "isim/testdeco_isim_beh.exe.sim/work/m_00000000000576120122_0700984775.didat");
	xsi_register_executes(pe);
}
