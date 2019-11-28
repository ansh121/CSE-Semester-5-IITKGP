
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name asgn7_2 -dir "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2/planAhead_run_2" -part xc7a100tcsg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2/Mult_3.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2} }
set_property target_constrs_file "Mult_3.ucf" [current_fileset -constrset]
add_files [list {Mult_3.ucf}] -fileset [get_property constrset [current_run]]
link_design
