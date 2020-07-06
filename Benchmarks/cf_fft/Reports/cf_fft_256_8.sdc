# ####################################################################

#  Created by Encounter(R) RTL Compiler RC13.10 - v13.10-s006_1 on Wed Sep 11 13:24:55 +0530 2019

# ####################################################################

set sdc_version 1.7

set_units -capacitance 1000.0fF
set_units -time 1000.0ps

# Set the current design
current_design cf_fft_256_8

create_clock -name "clk" -add -period 10.0 -waveform {0.0 5.0} [get_ports clock_c]
set_clock_transition 0.1 [get_clocks clk]
set_clock_gating_check -setup 0.0 
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports enable_i]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports reset_i]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports sync_i]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[15]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[14]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[13]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[12]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[11]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[10]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[9]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[8]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[7]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[6]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[5]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[4]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[3]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[2]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[1]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_i[0]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[15]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[14]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[13]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[12]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[11]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[10]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[9]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[8]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[7]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[6]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[5]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[4]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[3]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[2]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[1]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_i[0]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports sync_o]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[15]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[14]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[13]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[12]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[11]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[10]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[9]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[8]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[7]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[6]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[5]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[4]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[3]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[2]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[1]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_0_o[0]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[15]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[14]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[13]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[12]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[11]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[10]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[9]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[8]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[7]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[6]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[5]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[4]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[3]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[2]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[1]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {data_1_o[0]}]
set_wire_load_mode "enclosed"
set_dont_use [get_lib_cells slow/HOLDX1]
set_clock_uncertainty -setup 1.0 [get_ports clock_c]
set_clock_uncertainty -hold 1.0 [get_ports clock_c]
