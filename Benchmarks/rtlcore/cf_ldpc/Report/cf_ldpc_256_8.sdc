# ####################################################################

#  Created by Encounter(R) RTL Compiler RC13.10 - v13.10-s006_1 on Wed Sep 11 13:43:20 +0530 2019

# ####################################################################

set sdc_version 1.7

set_units -capacitance 1000.0fF
set_units -time 1000.0ps

# Set the current design
current_design cf_ldpc

create_clock -name "clk" -add -period 10.0 -waveform {0.0 5.0} [get_ports clock_c]
set_clock_transition 0.1 [get_clocks clk]
set_clock_gating_check -setup 0.0 
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports start_i]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[19]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[18]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[17]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[16]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[15]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[14]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[13]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[12]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[11]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[10]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[9]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[8]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[7]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[6]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[5]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[4]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[3]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[2]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[1]}]
set_input_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_i[0]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports valid_o]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[19]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[18]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[17]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[16]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[15]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[14]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[13]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[12]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[11]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[10]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[9]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[8]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[7]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[6]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[5]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[4]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[3]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[2]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[1]}]
set_output_delay -clock [get_clocks clk] -add_delay -max 1.0 [get_ports {message_o[0]}]
set_wire_load_mode "enclosed"
set_dont_use [get_lib_cells slow/HOLDX1]
set_clock_uncertainty -setup 1.0 [get_ports clock_c]
set_clock_uncertainty -hold 1.0 [get_ports clock_c]
