
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name MIPS -dir "D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/planAhead_run_2" -part xc6slx16csg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/uart.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS} {ipcore_dir} }
add_files [list {ipcore_dir/pmem.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/rammemory.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "Nexys3_Master.ucf" [current_fileset -constrset]
add_files [list {Nexys3_Master.ucf}] -fileset [get_property constrset [current_run]]
link_design
