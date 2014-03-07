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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002597597510_3383896982_init();
    xilinxcorelib_ver_m_00000000001358910285_1255613365_init();
    xilinxcorelib_ver_m_00000000001687936702_4216483150_init();
    xilinxcorelib_ver_m_00000000000277421008_0230905955_init();
    xilinxcorelib_ver_m_00000000001786246093_2779389101_init();
    work_m_00000000002489990758_2413555135_init();
    work_m_00000000001697717315_3960456194_init();
    work_m_00000000002606762175_2052158563_init();
    work_m_00000000004164045976_0258016765_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004164045976_0258016765");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
