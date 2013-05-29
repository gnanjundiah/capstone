-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\Header_Data.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: Header_Data
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET/Header_Data
-- Hierarchy Level: 5
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE work.TX_SYSTEM_TOP_pkg.ALL;

ENTITY Header_Data IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        INITIALIZE_TX_CORE                :   IN    std_logic;
        Enable                            :   IN    std_logic;
        HEADER_I                          :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
        HEADER_Q                          :   OUT   std_logic_vector(7 DOWNTO 0)  -- int8
        );
END Header_Data;


ARCHITECTURE rtl OF Header_Data IS

  -- Component Declarations
  COMPONENT HEADER_SYMBOL_COUNTER
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          INITIALIZE_HEADER_SYMBOL_COUNTER :   IN    std_logic;
          HEADER_SYMBOL_COUNT             :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : HEADER_SYMBOL_COUNTER
    USE ENTITY work.HEADER_SYMBOL_COUNTER(rtl);

  -- Constants
  CONSTANT table_data                     : vector_of_signed8(0 TO 88) := ( to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8) );  -- sfix8 [89]
  CONSTANT table_data_2                   : vector_of_signed8(0 TO 88) := ( to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(-1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(1, 8), to_signed(1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), to_signed(-1, 8), 
                                                                          to_signed(1, 8), to_signed(-1, 8), to_signed(1, 8), to_signed(-1, 8) );  -- sfix8 [89]

  -- Signals
  SIGNAL enb_gated                        : std_logic;
  SIGNAL Enable_out2                      : std_logic;
  SIGNAL HEADER_SYMBOL_COUNTER_out1       : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL HEADER_SYMBOL_COUNTER_out1_unsigned : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Pad_Training_LUT_I_out1          : signed(7 DOWNTO 0);  -- int8
  SIGNAL Pad_Training_LUT_I_out1_last_value : signed(7 DOWNTO 0);  -- int8
  SIGNAL Pad_Training_LUT_I_out1_bypass   : signed(7 DOWNTO 0);  -- int8
  SIGNAL Pad_Training_LUT_Q_out1          : signed(7 DOWNTO 0);  -- int8
  SIGNAL Pad_Training_LUT_Q_out1_last_value : signed(7 DOWNTO 0);  -- int8
  SIGNAL Pad_Training_LUT_Q_out1_bypass   : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_SYMBOL_COUNTER_out1_unsigned_1 : unsigned(31 DOWNTO 0);  -- uint32

BEGIN
  u_HEADER_SYMBOL_COUNTER : HEADER_SYMBOL_COUNTER
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              INITIALIZE_HEADER_SYMBOL_COUNTER => INITIALIZE_TX_CORE,
              HEADER_SYMBOL_COUNT => HEADER_SYMBOL_COUNTER_out1  -- uint32
              );

  Enable_out2 <= Enable;

  enb_gated <= Enable_out2 AND enb;

  HEADER_SYMBOL_COUNTER_out1_unsigned <= unsigned(HEADER_SYMBOL_COUNTER_out1);

  Pad_Training_LUT_I_out1 <= table_data(to_integer(HEADER_SYMBOL_COUNTER_out1_unsigned));

  HEADER_I_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Pad_Training_LUT_I_out1_last_value <= to_signed(0, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Pad_Training_LUT_I_out1_last_value <= Pad_Training_LUT_I_out1;
      END IF;
    END IF;
  END PROCESS HEADER_I_bypass_process;


  
  Pad_Training_LUT_I_out1_bypass <= Pad_Training_LUT_I_out1_last_value WHEN Enable_out2 = '0' ELSE
      Pad_Training_LUT_I_out1;

  HEADER_I <= std_logic_vector(Pad_Training_LUT_I_out1_bypass);

  Pad_Training_LUT_Q_out1 <= table_data_2(to_integer(HEADER_SYMBOL_COUNTER_out1_unsigned));

  HEADER_Q_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Pad_Training_LUT_Q_out1_last_value <= to_signed(0, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Pad_Training_LUT_Q_out1_last_value <= Pad_Training_LUT_Q_out1;
      END IF;
    END IF;
  END PROCESS HEADER_Q_bypass_process;


  
  Pad_Training_LUT_Q_out1_bypass <= Pad_Training_LUT_Q_out1_last_value WHEN Enable_out2 = '0' ELSE
      Pad_Training_LUT_Q_out1;

  HEADER_Q <= std_logic_vector(Pad_Training_LUT_Q_out1_bypass);

  HEADER_SYMBOL_COUNTER_out1_unsigned_1 <= unsigned(HEADER_SYMBOL_COUNTER_out1);


END rtl;

