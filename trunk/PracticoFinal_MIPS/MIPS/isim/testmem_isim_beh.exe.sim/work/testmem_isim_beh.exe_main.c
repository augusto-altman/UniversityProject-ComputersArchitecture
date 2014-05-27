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
    xilinxcorelib_ver_m_00000000001358910285_2711597471_init();
    xilinxcorelib_ver_m_00000000001358910285_0057010046_init();
    xilinxcorelib_ver_m_00000000001687936702_1513404662_init();
    xilinxcorelib_ver_m_00000000000277421008_4152715321_init();
    xilinxcorelib_ver_m_00000000001786246093_2032648149_init();
    work_m_00000000000621624591_3749266846_init();
    work_m_00000000001016529530_3020956671_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001016529530_3020956671");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
