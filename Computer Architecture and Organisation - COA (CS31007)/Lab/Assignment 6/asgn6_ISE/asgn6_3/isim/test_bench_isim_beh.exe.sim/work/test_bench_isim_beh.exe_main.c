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
    work_m_00000000002286905856_0541824188_init();
    work_m_00000000003506269449_3879582996_init();
    work_m_00000000000294982761_0616594054_init();
    work_m_00000000003764334534_1536258168_init();
    work_m_00000000002816065794_2578365841_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002816065794_2578365841");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
