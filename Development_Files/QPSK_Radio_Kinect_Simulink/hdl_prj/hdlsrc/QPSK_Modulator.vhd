-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\QPSK_Modulator.vhd
-- Created: 2013-05-26 21:23:00
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: QPSK_Modulator
-- Source Path: QPSK_system_v3g/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET/Message_Data/QPSK_Modulator
-- Hierarchy Level: 6
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY QPSK_Modulator IS
  PORT( MESSAGE_I_BINARY                  :   IN    std_logic;  -- ufix1
        MESSAGE_Q_BINARY                  :   IN    std_logic;  -- ufix1
        MESSAGE_I_MODULATED               :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
        MESSAGE_Q_MODULATED               :   OUT   std_logic_vector(7 DOWNTO 0)  -- int8
        );
END QPSK_Modulator;


ARCHITECTURE rtl OF QPSK_Modulator IS

  -- Signals
  SIGNAL Constant2_out1                   : signed(7 DOWNTO 0);  -- int8
  SIGNAL Constant1_out1                   : signed(7 DOWNTO 0);  -- int8
  SIGNAL MODULATOR_SWITCH_I_out1          : signed(7 DOWNTO 0);  -- int8
  SIGNAL Constant4_out1                   : signed(7 DOWNTO 0);  -- int8
  SIGNAL Constant3_out1                   : signed(7 DOWNTO 0);  -- int8
  SIGNAL MODULATOR_SWITCH_Q_out1          : signed(7 DOWNTO 0);  -- int8

BEGIN
  Constant2_out1 <= to_signed(-1, 8);

  Constant1_out1 <= to_signed(1, 8);

  
  MODULATOR_SWITCH_I_out1 <= Constant2_out1 WHEN MESSAGE_I_BINARY = '0' ELSE
      Constant1_out1;

  MESSAGE_I_MODULATED <= std_logic_vector(MODULATOR_SWITCH_I_out1);

  Constant4_out1 <= to_signed(-1, 8);

  Constant3_out1 <= to_signed(1, 8);

  
  MODULATOR_SWITCH_Q_out1 <= Constant4_out1 WHEN MESSAGE_Q_BINARY = '0' ELSE
      Constant3_out1;

  MESSAGE_Q_MODULATED <= std_logic_vector(MODULATOR_SWITCH_Q_out1);

END rtl;

