-- 
-- (c) Copyright 2008 - 2011 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
------------------------------------------------------------------------------
-- User entered comments
------------------------------------------------------------------------------
-- None
--
------------------------------------------------------------------------------
-- "Output    Output      Phase     Duty      Pk-to-Pk        Phase"
-- "Clock    Freq (MHz) (degrees) Cycle (%) Jitter (ps)  Error (ps)"
------------------------------------------------------------------------------
-- CLK_OUT1____40.000______0.000______50.0______204.285____191.950
-- CLK_OUT2____40.000____180.000______50.0______204.285____191.950
-- CLK_OUT3____20.000______0.000______50.0______236.475____191.950
--
------------------------------------------------------------------------------
-- "Input Clock   Freq (MHz)    Input Jitter (UI)"
------------------------------------------------------------------------------
-- __primary______________40____________0.004


-- The following code must appear in the VHDL architecture header:
------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
component CLK_GEN_CORE
port
 (-- Clock in ports
  CLK_40MHz_IN           : in     std_logic;
  CLKFB_IN          : in     std_logic;
  -- Clock out ports
  CLK_40MHz_0_DEG          : out    std_logic;
  CLK_40MHz_180_DEG          : out    std_logic;
  CLK_20MHz_0_DEG          : out    std_logic;
  CLKFB_OUT         : out    std_logic;
  -- Status and control signals
  RESET             : in     std_logic;
  LOCKED            : out    std_logic
 );
end component;

-- COMP_TAG_END ------ End COMPONENT Declaration ------------
-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.
------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : CLK_GEN_CORE
  port map
   (-- Clock in ports
    CLK_40MHz_IN => CLK_40MHz_IN,
    CLKFB_IN => CLKFB_IN,
    -- Clock out ports
    CLK_40MHz_0_DEG => CLK_40MHz_0_DEG,
    CLK_40MHz_180_DEG => CLK_40MHz_180_DEG,
    CLK_20MHz_0_DEG => CLK_20MHz_0_DEG,
    CLKFB_OUT => CLKFB_OUT,
    -- Status and control signals
    RESET  => RESET,
    LOCKED => LOCKED);
-- INST_TAG_END ------ End INSTANTIATION Template ------------