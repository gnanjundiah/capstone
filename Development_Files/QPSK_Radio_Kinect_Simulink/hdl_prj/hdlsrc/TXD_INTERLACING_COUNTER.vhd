-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\TXD_INTERLACING_COUNTER.vhd
-- Created: 2013-05-26 21:23:00
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: TXD_INTERLACING_COUNTER
-- Source Path: QPSK_system_v3g/TX_SYSTEM_TOP/TXD_INTERLACING_COUNTER 
-- Hierarchy Level: 1
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY TXD_INTERLACING_COUNTER IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        Enable                            :   IN    std_logic;
        TX_IQ_SEL                         :   OUT   std_logic  -- ufix1
        );
END TXD_INTERLACING_COUNTER;


ARCHITECTURE rtl OF TXD_INTERLACING_COUNTER IS

  -- Signals
  SIGNAL enb_gated                        : std_logic;
  SIGNAL Enable_out1                      : std_logic;
  SIGNAL Counter_Free_Running_count       : std_logic;  -- ufix1
  SIGNAL Counter_Free_Running_out1        : std_logic;  -- ufix1
  SIGNAL Counter_Free_Running_out1_last_value : std_logic;  -- ufix1
  SIGNAL Counter_Free_Running_out1_bypass : std_logic;  -- ufix1

BEGIN
  Enable_out1 <= Enable;

  enb_gated <= Enable_out1 AND enb;

  -- Free running, Unsigned Counter
  --  initial value   = 0
  --  step value      = 1
  Counter_Free_Running_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Counter_Free_Running_count <= '0';
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Counter_Free_Running_count <=  NOT Counter_Free_Running_count;
      END IF;
    END IF;
  END PROCESS Counter_Free_Running_process;

  Counter_Free_Running_out1 <= Counter_Free_Running_count;

  TX_IQ_SEL_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Counter_Free_Running_out1_last_value <= '0';
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Counter_Free_Running_out1_last_value <= Counter_Free_Running_out1;
      END IF;
    END IF;
  END PROCESS TX_IQ_SEL_bypass_process;


  
  Counter_Free_Running_out1_bypass <= Counter_Free_Running_out1_last_value WHEN Enable_out1 = '0' ELSE
      Counter_Free_Running_out1;

  TX_IQ_SEL <= Counter_Free_Running_out1_bypass;

END rtl;

