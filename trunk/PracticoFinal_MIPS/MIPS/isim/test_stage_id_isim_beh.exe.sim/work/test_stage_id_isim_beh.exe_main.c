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
    work_m_00000000000234373765_3245280214_init();
    work_m_00000000000650576988_2415336395_init();
    work_m_00000000000440839185_3093772975_init();
    work_m_00000000004138400041_1093138604_init();
    work_m_00000000004035239418_2489259343_init();
    work_m_00000000004059813684_4288937017_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004059813684_4288937017");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
