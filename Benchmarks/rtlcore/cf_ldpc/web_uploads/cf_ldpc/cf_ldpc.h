//
//  Copyright (c) 2003 Launchbird Design Systems, Inc.
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
//  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  
//  
//  Overview:
//  
//    Low-density parity-check (LDPC) codes are forward error correction codes invented
//    by Robert Gallager in the early 60's.  Like turbo codes, LDPC codes approach Shannon's
//    limit for channel capacity, but have reduced decoding complexity.
//  
//  Architecture:
//  
//    This LDPC error corrector implements Gallager's "A" algorithm: an iterative,
//    hard-decision decoder that opts for simplicity over performance.  The architecture
//    elaborates all logic required to implement the message-passing algorithm from
//    message nodes, to check nodes, then back to message nodes -- one iteration occurs
//    every clock cycle.
//  
//    The core is primarily meant as an LDPC evaluation platform, as the fully parallel
//    architecture may be inappropriate for synthesizing large block length LDPC decoders.
//  
//    The LDPC code is defined by a parity check matrix, and is specified from the Confluence source.
//    This LDPC corrector has been generated for the following parity check matrix:
//  
//  1 1 1 1 . . . . . . . . . . . . . . . . 
//  . . . . 1 1 1 1 . . . . . . . . . . . . 
//  . . . . . . . . 1 1 1 1 . . . . . . . . 
//  . . . . . . . . . . . . 1 1 1 1 . . . . 
//  . . . . . . . . . . . . . . . . 1 1 1 1 
//  1 . . . 1 . . . 1 . . . 1 . . . . . . . 
//  . 1 . . . 1 . . . 1 . . . . . . 1 . . . 
//  . . 1 . . . 1 . . . . . . 1 . . . 1 . . 
//  . . . 1 . . . . . . 1 . . . 1 . . . 1 . 
//  . . . . . . . 1 . . . 1 . . . 1 . . . 1 
//  1 . . . . 1 . . . . . 1 . . . . . 1 . . 
//  . 1 . . . . 1 . . . 1 . . . . 1 . . . . 
//  . . 1 . . . . 1 . . . . 1 . . . . . 1 . 
//  . . . 1 . . . . 1 . . . . 1 . . 1 . . . 
//  . . . . 1 . . . . 1 . . . . 1 . . . . 1 
//  
//  
//  Interface:
//  
//    Synchronization:
//      clock_c      : Clock.
//  
//    Inputs:
//      start_i      : Start signal pulse.  Aligned with input message.
//      message_i    : Input message.
//  
//    Outputs:
//      valid_o      : High if output message meets parity checking.
//      message_o    : Output message.
//  
//  
//  
//  
//  
//  Generated by Confluence 0.6.3  --  Launchbird Design Systems, Inc.  --  www.launchbird.com
//  
//  Build Date : Fri Aug 22 09:48:55 CDT 2003
//  
//  Interface
//  
//    Build Name    : cf_ldpc
//    Clock Domains : clock_c  
//    Vector Input  : start_i(1)
//    Vector Input  : message_i(20)
//    Vector Output : valid_o(1)
//    Vector Output : message_o(20)
//  
//  
//  

#ifdef __cplusplus
extern "C" {
#endif

void cf_ldpc_ports(unsigned char* port_start_i, unsigned char* port_message_i, unsigned char* port_valid_o, unsigned char* port_message_o);
void cf_ldpc_init();
void cf_ldpc_calc();
void cf_ldpc_cycle_clock();
void cf_ldpc_sim_init(const char* file);
void cf_ldpc_sim_end();
void cf_ldpc_sim_sample();

#ifdef __cplusplus
}
#endif
