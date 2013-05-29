
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name xillydemo -dir "C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/tx_system/vhdl/planAhead_run_1" -part xc7z020clg484-1
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/tx_system/vhdl/xillydemo.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/tx_system/vhdl} {ipcore_dir} {../system/implementation} {../cores} {../runonce} }
add_files [list {ipcore_dir/FIFO_32x512_ASYNC.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/fifo_8x2048_async_tk.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../system/implementation/system_axi4lite_0_wrapper.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../system/implementation/system_axi_interconnect_0_wrapper.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../system/implementation/system_axi_interconnect_1_wrapper.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../system/implementation/system_processing_system7_0_wrapper.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/tx_system/vhdl/src/xillydemo.ucf" [current_fileset -constrset]
add_files [list {C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/tx_system/vhdl/src/xillydemo.ucf}] -fileset [get_property constrset [current_run]]
link_design
