-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\TX_CORE_ENABLE_COUNTER.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: TX_CORE_ENABLE_COUNTER
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_ENABLE_COUNTER
-- Hierarchy Level: 1
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY TX_CORE_ENABLE_COUNTER IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        INITIALIZE_TX_CORE_ENABLE_COUNTER :   IN    std_logic;
        TX_CORE_ENABLE_COUNT              :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END TX_CORE_ENABLE_COUNTER;


ARCHITECTURE rtl OF TX_CORE_ENABLE_COUNTER IS

  -- Signals
  SIGNAL Constant1_out1                   : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Constant2_out1                   : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Unit_Delay1_out1                 : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Sum_add_temp                     : unsigned(32 DOWNTO 0);  -- ufix33
  SIGNAL Sum_out1                         : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Compare_To_Constant_out1         : std_logic;
  SIGNAL INITIALIZE_TX_CORE_ENABLE_COUNTER_1 : std_logic;
  SIGNAL Logical_Operator_out1            : std_logic;
  SIGNAL Switch1_out1                     : unsigned(31 DOWNTO 0);  -- uint32

BEGIN
  Constant1_out1 <= to_unsigned(1, 32);

  Constant2_out1 <= to_unsigned(0, 32);

  Sum_add_temp <= resize(Constant1_out1, 33) + resize(Unit_Delay1_out1, 33);
  
  Sum_out1 <= "11111111111111111111111111111111" WHEN Sum_add_temp(32) /= '0' ELSE
      Sum_add_temp(31 DOWNTO 0);

  
  Compare_To_Constant_out1 <= '1' WHEN Unit_Delay1_out1 = 4 ELSE
      '0';

  INITIALIZE_TX_CORE_ENABLE_COUNTER_1 <= INITIALIZE_TX_CORE_ENABLE_COUNTER OR Compare_To_Constant_out1;

  Logical_Operator_out1 <= INITIALIZE_TX_CORE_ENABLE_COUNTER_1;

  
  Switch1_out1 <= Sum_out1 WHEN Logical_Operator_out1 = '0' ELSE
      Constant2_out1;

  Unit_Delay1_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Unit_Delay1_out1 <= to_unsigned(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Unit_Delay1_out1 <= Switch1_out1;
      END IF;
    END IF;
  END PROCESS Unit_Delay1_process;


  TX_CORE_ENABLE_COUNT <= std_logic_vector(Unit_Delay1_out1);

END rtl;
