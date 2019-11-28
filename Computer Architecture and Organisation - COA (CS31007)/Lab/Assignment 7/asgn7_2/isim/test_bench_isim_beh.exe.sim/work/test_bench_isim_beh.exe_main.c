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
    work_m_00000000002457420837_2285671583_init();
    work_m_00000000002405384224_2295145773_init();
    work_m_00000000002750686589_2578268064_init();
    work_m_00000000003924592042_4099292586_init();
    work_m_00000000001127530810_2578365841_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001127530810_2578365841");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
