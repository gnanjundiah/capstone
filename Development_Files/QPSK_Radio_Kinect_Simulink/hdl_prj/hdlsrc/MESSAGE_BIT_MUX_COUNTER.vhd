-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\MESSAGE_BIT_MUX_COUNTER.vhd
-- Created: 2013-05-26 21:23:00
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: MESSAGE_BIT_MUX_COUNTER
-- Source Path: QPSK_system_v3g/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET/Message_Data/IQ_Parser/MESSAGE_BIT_MUX_COUNTER
-- Hierarchy Level: 7
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY MESSAGE_BIT_MUX_COUNTER IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        INITIALIZE_MESSAGE_BIT_MUX_COUNTER :   IN    std_logic;
        MESSAGE_BIT_MUX_COUNT             :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END MESSAGE_BIT_MUX_COUNTER;


ARCHITECTURE rtl OF MESSAGE_BIT_MUX_COUNTER IS

  -- Signals
  SIGNAL Constant1_out1                   : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Constant2_out1                   : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Switch1_out1                     : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Sum_add_temp                     : unsigned(32 DOWNTO 0);  -- ufix33
  SIGNAL Sum_out1                         : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Unit_Delay_out1                  : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Compare_To_Constant3_out1        : std_logic;
  SIGNAL INITIALIZE_MESSAGE_BIT_MUX_COUNTER_1 : std_logic;

BEGIN
  Constant1_out1 <= to_unsigned(1, 32);

  Constant2_out1 <= to_unsigned(0, 32);

  Sum_add_temp <= resize(Constant1_out1, 33) + resize(Switch1_out1, 33);
  
  Sum_out1 <= "11111111111111111111111111111111" WHEN Sum_add_temp(32) /= '0' ELSE
      Sum_add_temp(31 DOWNTO 0);

  Unit_Delay_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Unit_Delay_out1 <= to_unsigned(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Unit_Delay_out1 <= Sum_out1;
      END IF;
    END IF;
  END PROCESS Unit_Delay_process;


  
  Compare_To_Constant3_out1 <= '1' WHEN Unit_Delay_out1 >= 4 ELSE
      '0';

  INITIALIZE_MESSAGE_BIT_MUX_COUNTER_1 <= INITIALIZE_MESSAGE_BIT_MUX_COUNTER OR Compare_To_Constant3_out1;

  
  Switch1_out1 <= Unit_Delay_out1 WHEN INITIALIZE_MESSAGE_BIT_MUX_COUNTER_1 = '0' ELSE
      Constant2_out1;

  MESSAGE_BIT_MUX_COUNT <= std_logic_vector(Switch1_out1);

END rtl;

