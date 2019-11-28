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
    work_m_00000000001993525071_2370278801_init();
    work_m_00000000003180413120_4198540551_init();
    work_m_00000000004274051120_1665791165_init();
    work_m_00000000003842439026_0843453583_init();
    work_m_00000000002093977481_2578365841_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002093977481_2578365841");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
