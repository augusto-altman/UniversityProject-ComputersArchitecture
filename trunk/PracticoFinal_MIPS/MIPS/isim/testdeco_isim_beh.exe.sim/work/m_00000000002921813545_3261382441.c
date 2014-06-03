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
static const char *ng0 = "D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/StallHandler.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};



static void Cont_36_0(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;

LAB0:    t1 = (t0 + 3968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1688U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t22, 8);

LAB16:    t16 = (t0 + 4632);
    t23 = (t16 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memset(t26, 0, 8);
    t27 = 31U;
    t28 = t27;
    t29 = (t3 + 4);
    t30 = *((unsigned int *)t3);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t29);
    t28 = (t28 & t31);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 | t27);
    t34 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t34 | t28);
    xsi_driver_vfirst_trans(t16, 0, 4);
    t35 = (t0 + 4536);
    *((int *)t35) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 2168U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 2328U);
    t22 = *((char **)t16);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 5, t17, 5, t22, 5);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void Always_38_1(char *t0)
{
    char t13[8];
    char t30[8];
    char t45[8];
    char t61[8];
    char t76[8];
    char t84[8];
    char t112[8];
    char t124[8];
    char t145[8];
    char t153[8];
    char t192[8];
    char t204[8];
    char t223[8];
    char t231[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    char *t60;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t125;
    char *t126;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    char *t152;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    char *t157;
    char *t158;
    char *t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    int t177;
    int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    char *t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    char *t191;
    char *t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    char *t199;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t205;
    char *t206;
    unsigned int t207;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    char *t212;
    char *t213;
    char *t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    char *t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    char *t230;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    char *t235;
    char *t236;
    char *t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    char *t245;
    char *t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    int t255;
    int t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    char *t263;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 4552);
    *((int *)t2) = 1;
    t3 = (t0 + 4248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB13;

LAB11:    if (*((unsigned int *)t2) == 0)
        goto LAB10;

LAB12:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;

LAB13:    t5 = (t13 + 4);
    t11 = (t3 + 4);
    t14 = *((unsigned int *)t3);
    t15 = (~(t14));
    *((unsigned int *)t13) = t15;
    *((unsigned int *)t5) = 0;
    if (*((unsigned int *)t11) != 0)
        goto LAB15;

LAB14:    t20 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t20 & 1U);
    t21 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t21 & 1U);
    t12 = (t13 + 4);
    t22 = *((unsigned int *)t12);
    t23 = (~(t22));
    t24 = *((unsigned int *)t13);
    t25 = (t24 & t23);
    t26 = (t25 != 0);
    if (t26 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(41, ng0);

LAB9:    xsi_set_current_line(42, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2888);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

LAB10:    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB15:    t16 = *((unsigned int *)t13);
    t17 = *((unsigned int *)t11);
    *((unsigned int *)t13) = (t16 | t17);
    t18 = *((unsigned int *)t5);
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t5) = (t18 | t19);
    goto LAB14;

LAB16:    xsi_set_current_line(46, ng0);

LAB19:    xsi_set_current_line(47, ng0);
    t27 = (t0 + 1848U);
    t28 = *((char **)t27);
    t27 = (t0 + 2008U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    t27 = (t28 + 4);
    t31 = (t29 + 4);
    t32 = *((unsigned int *)t28);
    t33 = *((unsigned int *)t29);
    t34 = (t32 ^ t33);
    t35 = *((unsigned int *)t27);
    t36 = *((unsigned int *)t31);
    t37 = (t35 ^ t36);
    t38 = (t34 | t37);
    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t31);
    t41 = (t39 | t40);
    t42 = (~(t41));
    t43 = (t38 & t42);
    if (t43 != 0)
        goto LAB23;

LAB20:    if (t41 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB23:    memset(t45, 0, 8);
    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 & 1U);
    if (t51 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t46) != 0)
        goto LAB26;

LAB27:    t53 = (t45 + 4);
    t54 = *((unsigned int *)t45);
    t55 = (!(t54));
    t56 = *((unsigned int *)t53);
    t57 = (t55 || t56);
    if (t57 > 0)
        goto LAB28;

LAB29:    memcpy(t84, t45, 8);

LAB30:    memset(t112, 0, 8);
    t113 = (t84 + 4);
    t114 = *((unsigned int *)t113);
    t115 = (~(t114));
    t116 = *((unsigned int *)t84);
    t117 = (t116 & t115);
    t118 = (t117 & 1U);
    if (t118 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t113) != 0)
        goto LAB44;

LAB45:    t120 = (t112 + 4);
    t121 = *((unsigned int *)t112);
    t122 = *((unsigned int *)t120);
    t123 = (t121 || t122);
    if (t123 > 0)
        goto LAB46;

LAB47:    memcpy(t153, t112, 8);

LAB48:    t185 = (t153 + 4);
    t186 = *((unsigned int *)t185);
    t187 = (~(t186));
    t188 = *((unsigned int *)t153);
    t189 = (t188 & t187);
    t190 = (t189 != 0);
    if (t190 > 0)
        goto LAB62;

LAB63:    xsi_set_current_line(53, ng0);

LAB86:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB64:    goto LAB18;

LAB22:    t44 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB23;

LAB24:    *((unsigned int *)t45) = 1;
    goto LAB27;

LAB26:    t52 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB27;

LAB28:    t58 = (t0 + 1848U);
    t59 = *((char **)t58);
    t58 = (t0 + 2488U);
    t60 = *((char **)t58);
    memset(t61, 0, 8);
    t58 = (t59 + 4);
    t62 = (t60 + 4);
    t63 = *((unsigned int *)t59);
    t64 = *((unsigned int *)t60);
    t65 = (t63 ^ t64);
    t66 = *((unsigned int *)t58);
    t67 = *((unsigned int *)t62);
    t68 = (t66 ^ t67);
    t69 = (t65 | t68);
    t70 = *((unsigned int *)t58);
    t71 = *((unsigned int *)t62);
    t72 = (t70 | t71);
    t73 = (~(t72));
    t74 = (t69 & t73);
    if (t74 != 0)
        goto LAB34;

LAB31:    if (t72 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t61) = 1;

LAB34:    memset(t76, 0, 8);
    t77 = (t61 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t61);
    t81 = (t80 & t79);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t77) != 0)
        goto LAB37;

LAB38:    t85 = *((unsigned int *)t45);
    t86 = *((unsigned int *)t76);
    t87 = (t85 | t86);
    *((unsigned int *)t84) = t87;
    t88 = (t45 + 4);
    t89 = (t76 + 4);
    t90 = (t84 + 4);
    t91 = *((unsigned int *)t88);
    t92 = *((unsigned int *)t89);
    t93 = (t91 | t92);
    *((unsigned int *)t90) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB39;

LAB40:
LAB41:    goto LAB30;

LAB33:    t75 = (t61 + 4);
    *((unsigned int *)t61) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB34;

LAB35:    *((unsigned int *)t76) = 1;
    goto LAB38;

LAB37:    t83 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB38;

LAB39:    t96 = *((unsigned int *)t84);
    t97 = *((unsigned int *)t90);
    *((unsigned int *)t84) = (t96 | t97);
    t98 = (t45 + 4);
    t99 = (t76 + 4);
    t100 = *((unsigned int *)t98);
    t101 = (~(t100));
    t102 = *((unsigned int *)t45);
    t103 = (t102 & t101);
    t104 = *((unsigned int *)t99);
    t105 = (~(t104));
    t106 = *((unsigned int *)t76);
    t107 = (t106 & t105);
    t108 = (~(t103));
    t109 = (~(t107));
    t110 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t110 & t108);
    t111 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t111 & t109);
    goto LAB41;

LAB42:    *((unsigned int *)t112) = 1;
    goto LAB45;

LAB44:    t119 = (t112 + 4);
    *((unsigned int *)t112) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB45;

LAB46:    t125 = (t0 + 3048);
    t126 = (t125 + 56U);
    t127 = *((char **)t126);
    memset(t124, 0, 8);
    t128 = (t127 + 4);
    t129 = *((unsigned int *)t128);
    t130 = (~(t129));
    t131 = *((unsigned int *)t127);
    t132 = (t131 & t130);
    t133 = (t132 & 1U);
    if (t133 != 0)
        goto LAB52;

LAB50:    if (*((unsigned int *)t128) == 0)
        goto LAB49;

LAB51:    t134 = (t124 + 4);
    *((unsigned int *)t124) = 1;
    *((unsigned int *)t134) = 1;

LAB52:    t135 = (t124 + 4);
    t136 = (t127 + 4);
    t137 = *((unsigned int *)t127);
    t138 = (~(t137));
    *((unsigned int *)t124) = t138;
    *((unsigned int *)t135) = 0;
    if (*((unsigned int *)t136) != 0)
        goto LAB54;

LAB53:    t143 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t143 & 1U);
    t144 = *((unsigned int *)t135);
    *((unsigned int *)t135) = (t144 & 1U);
    memset(t145, 0, 8);
    t146 = (t124 + 4);
    t147 = *((unsigned int *)t146);
    t148 = (~(t147));
    t149 = *((unsigned int *)t124);
    t150 = (t149 & t148);
    t151 = (t150 & 1U);
    if (t151 != 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t146) != 0)
        goto LAB57;

LAB58:    t154 = *((unsigned int *)t112);
    t155 = *((unsigned int *)t145);
    t156 = (t154 & t155);
    *((unsigned int *)t153) = t156;
    t157 = (t112 + 4);
    t158 = (t145 + 4);
    t159 = (t153 + 4);
    t160 = *((unsigned int *)t157);
    t161 = *((unsigned int *)t158);
    t162 = (t160 | t161);
    *((unsigned int *)t159) = t162;
    t163 = *((unsigned int *)t159);
    t164 = (t163 != 0);
    if (t164 == 1)
        goto LAB59;

LAB60:
LAB61:    goto LAB48;

LAB49:    *((unsigned int *)t124) = 1;
    goto LAB52;

LAB54:    t139 = *((unsigned int *)t124);
    t140 = *((unsigned int *)t136);
    *((unsigned int *)t124) = (t139 | t140);
    t141 = *((unsigned int *)t135);
    t142 = *((unsigned int *)t136);
    *((unsigned int *)t135) = (t141 | t142);
    goto LAB53;

LAB55:    *((unsigned int *)t145) = 1;
    goto LAB58;

LAB57:    t152 = (t145 + 4);
    *((unsigned int *)t145) = 1;
    *((unsigned int *)t152) = 1;
    goto LAB58;

LAB59:    t165 = *((unsigned int *)t153);
    t166 = *((unsigned int *)t159);
    *((unsigned int *)t153) = (t165 | t166);
    t167 = (t112 + 4);
    t168 = (t145 + 4);
    t169 = *((unsigned int *)t112);
    t170 = (~(t169));
    t171 = *((unsigned int *)t167);
    t172 = (~(t171));
    t173 = *((unsigned int *)t145);
    t174 = (~(t173));
    t175 = *((unsigned int *)t168);
    t176 = (~(t175));
    t177 = (t170 & t172);
    t178 = (t174 & t176);
    t179 = (~(t177));
    t180 = (~(t178));
    t181 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t181 & t179);
    t182 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t182 & t180);
    t183 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t183 & t179);
    t184 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t184 & t180);
    goto LAB61;

LAB62:    xsi_set_current_line(48, ng0);

LAB65:    xsi_set_current_line(49, ng0);
    t191 = ((char*)((ng2)));
    memset(t192, 0, 8);
    t193 = (t191 + 4);
    t194 = *((unsigned int *)t193);
    t195 = (~(t194));
    t196 = *((unsigned int *)t191);
    t197 = (t196 & t195);
    t198 = (t197 & 4294967295U);
    if (t198 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t193) != 0)
        goto LAB68;

LAB69:    t200 = (t192 + 4);
    t201 = *((unsigned int *)t192);
    t202 = *((unsigned int *)t200);
    t203 = (t201 || t202);
    if (t203 > 0)
        goto LAB70;

LAB71:    memcpy(t231, t192, 8);

LAB72:    t263 = (t0 + 2888);
    xsi_vlogvar_assign_value(t263, t231, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB64;

LAB66:    *((unsigned int *)t192) = 1;
    goto LAB69;

LAB68:    t199 = (t192 + 4);
    *((unsigned int *)t192) = 1;
    *((unsigned int *)t199) = 1;
    goto LAB69;

LAB70:    t205 = (t0 + 1528U);
    t206 = *((char **)t205);
    memset(t204, 0, 8);
    t205 = (t206 + 4);
    t207 = *((unsigned int *)t205);
    t208 = (~(t207));
    t209 = *((unsigned int *)t206);
    t210 = (t209 & t208);
    t211 = (t210 & 1U);
    if (t211 != 0)
        goto LAB76;

LAB74:    if (*((unsigned int *)t205) == 0)
        goto LAB73;

LAB75:    t212 = (t204 + 4);
    *((unsigned int *)t204) = 1;
    *((unsigned int *)t212) = 1;

LAB76:    t213 = (t204 + 4);
    t214 = (t206 + 4);
    t215 = *((unsigned int *)t206);
    t216 = (~(t215));
    *((unsigned int *)t204) = t216;
    *((unsigned int *)t213) = 0;
    if (*((unsigned int *)t214) != 0)
        goto LAB78;

LAB77:    t221 = *((unsigned int *)t204);
    *((unsigned int *)t204) = (t221 & 1U);
    t222 = *((unsigned int *)t213);
    *((unsigned int *)t213) = (t222 & 1U);
    memset(t223, 0, 8);
    t224 = (t204 + 4);
    t225 = *((unsigned int *)t224);
    t226 = (~(t225));
    t227 = *((unsigned int *)t204);
    t228 = (t227 & t226);
    t229 = (t228 & 1U);
    if (t229 != 0)
        goto LAB79;

LAB80:    if (*((unsigned int *)t224) != 0)
        goto LAB81;

LAB82:    t232 = *((unsigned int *)t192);
    t233 = *((unsigned int *)t223);
    t234 = (t232 & t233);
    *((unsigned int *)t231) = t234;
    t235 = (t192 + 4);
    t236 = (t223 + 4);
    t237 = (t231 + 4);
    t238 = *((unsigned int *)t235);
    t239 = *((unsigned int *)t236);
    t240 = (t238 | t239);
    *((unsigned int *)t237) = t240;
    t241 = *((unsigned int *)t237);
    t242 = (t241 != 0);
    if (t242 == 1)
        goto LAB83;

LAB84:
LAB85:    goto LAB72;

LAB73:    *((unsigned int *)t204) = 1;
    goto LAB76;

LAB78:    t217 = *((unsigned int *)t204);
    t218 = *((unsigned int *)t214);
    *((unsigned int *)t204) = (t217 | t218);
    t219 = *((unsigned int *)t213);
    t220 = *((unsigned int *)t214);
    *((unsigned int *)t213) = (t219 | t220);
    goto LAB77;

LAB79:    *((unsigned int *)t223) = 1;
    goto LAB82;

LAB81:    t230 = (t223 + 4);
    *((unsigned int *)t223) = 1;
    *((unsigned int *)t230) = 1;
    goto LAB82;

LAB83:    t243 = *((unsigned int *)t231);
    t244 = *((unsigned int *)t237);
    *((unsigned int *)t231) = (t243 | t244);
    t245 = (t192 + 4);
    t246 = (t223 + 4);
    t247 = *((unsigned int *)t192);
    t248 = (~(t247));
    t249 = *((unsigned int *)t245);
    t250 = (~(t249));
    t251 = *((unsigned int *)t223);
    t252 = (~(t251));
    t253 = *((unsigned int *)t246);
    t254 = (~(t253));
    t255 = (t248 & t250);
    t256 = (t252 & t254);
    t257 = (~(t255));
    t258 = (~(t256));
    t259 = *((unsigned int *)t237);
    *((unsigned int *)t237) = (t259 & t257);
    t260 = *((unsigned int *)t237);
    *((unsigned int *)t237) = (t260 & t258);
    t261 = *((unsigned int *)t231);
    *((unsigned int *)t231) = (t261 & t257);
    t262 = *((unsigned int *)t231);
    *((unsigned int *)t231) = (t262 & t258);
    goto LAB85;

}


extern void work_m_00000000002921813545_3261382441_init()
{
	static char *pe[] = {(void *)Cont_36_0,(void *)Always_38_1};
	xsi_register_didat("work_m_00000000002921813545_3261382441", "isim/testdeco_isim_beh.exe.sim/work/m_00000000002921813545_3261382441.didat");
	xsi_register_executes(pe);
}
