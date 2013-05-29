-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\GEN_MOD_SHAPED_TX_DATA_PACKET.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: GEN_MOD_SHAPED_TX_DATA_PACKET
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET
-- Hierarchy Level: 3
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY GEN_MOD_SHAPED_TX_DATA_PACKET IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        MESSAGE_DATA_BYTE                 :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        INITIALIZE_TX_CORE                :   IN    std_logic;
        Enable                            :   IN    std_logic;
        FIFO_RD_EN                        :   OUT   std_logic;
        MODULATED_SHAPED_I                :   OUT   std_logic_vector(11 DOWNTO 0);  -- sfix12_En11
        MODULATED_SHAPED_Q                :   OUT   std_logic_vector(11 DOWNTO 0)  -- sfix12_En11
        );
END GEN_MOD_SHAPED_TX_DATA_PACKET;


ARCHITECTURE rtl OF GEN_MOD_SHAPED_TX_DATA_PACKET IS

  -- Component Declarations
  COMPONENT GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          INITIALIZE_GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER :   IN    std_logic;
          GEN_MODULATED_TX_DATA_PACKET_EN_COUNT :   OUT   std_logic_vector(7 DOWNTO 0)  -- int8
          );
  END COMPONENT;

  COMPONENT GEN_MODULATED_TX_DATA_PACKET
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          MESSAGE_DATA_BYTE               :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
          INITIALIZE_TX_CORE              :   IN    std_logic;
          Enable                          :   IN    std_logic;
          MODULATED_I_DATA                :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
          MODULATED_Q_DATA                :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
          Get_New_Data_Byte_For_Mod       :   OUT   std_logic;
          Get_New_Data_Byte_For_Mod1      :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  COMPONENT qpsk_srrc
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          d_in_re                         :   IN    std_logic_vector(7 DOWNTO 0);  -- int8
          d_in_im                         :   IN    std_logic_vector(7 DOWNTO 0);  -- int8
          d_out_re                        :   OUT   std_logic_vector(11 DOWNTO 0);  -- sfix12_En11
          d_out_im                        :   OUT   std_logic_vector(11 DOWNTO 0)  -- sfix12_En11
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER
    USE ENTITY work.GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER(rtl);

  FOR ALL : GEN_MODULATED_TX_DATA_PACKET
    USE ENTITY work.GEN_MODULATED_TX_DATA_PACKET(rtl);

  FOR ALL : qpsk_srrc
    USE ENTITY work.qpsk_srrc(rtl);

  -- Signals
  SIGNAL enb_gated                        : std_logic;
  SIGNAL Enable_out3                      : std_logic;
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1 : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1_signed : signed(7 DOWNTO 0);  -- int8
  SIGNAL Compare_To_Constant5_out1        : std_logic;
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_out1 : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_out2 : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_out3 : std_logic;
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_out4 : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_out4_unsigned : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Compare_To_Constant4_out1        : std_logic;
  SIGNAL Compare_To_Constant5_out1_1      : std_logic;
  SIGNAL Compare_To_Constant5_out1_2      : std_logic;
  SIGNAL Logical_Operator1_out1           : std_logic;
  SIGNAL Logical_Operator2_out1_last_value : std_logic;
  SIGNAL Logical_Operator2_out1_bypass    : std_logic;
  SIGNAL qpsk_srrc_out1_re                : std_logic_vector(11 DOWNTO 0);  -- ufix12
  SIGNAL qpsk_srrc_out1_im                : std_logic_vector(11 DOWNTO 0);  -- ufix12
  SIGNAL qpsk_srrc_out1_re_signed         : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL qpsk_srrc_out1_im_signed         : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL Complex_to_Real_Imag_out1_last_value : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL Complex_to_Real_Imag_out1_bypass : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL Complex_to_Real_Imag_out2_last_value : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL Complex_to_Real_Imag_out2_bypass : signed(11 DOWNTO 0);  -- sfix12_En11
  SIGNAL GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1_signed_1 : signed(7 DOWNTO 0);  -- int8

BEGIN
  u_GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER : GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              INITIALIZE_GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER => INITIALIZE_TX_CORE,
              GEN_MODULATED_TX_DATA_PACKET_EN_COUNT => GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1  -- int8
              );

  u_GEN_MODULATED_TX_DATA_PACKET : GEN_MODULATED_TX_DATA_PACKET
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              MESSAGE_DATA_BYTE => MESSAGE_DATA_BYTE,  -- uint8
              INITIALIZE_TX_CORE => INITIALIZE_TX_CORE,
              Enable => Compare_To_Constant5_out1,
              MODULATED_I_DATA => GEN_MODULATED_TX_DATA_PACKET_out1,  -- int8
              MODULATED_Q_DATA => GEN_MODULATED_TX_DATA_PACKET_out2,  -- int8
              Get_New_Data_Byte_For_Mod => GEN_MODULATED_TX_DATA_PACKET_out3,
              Get_New_Data_Byte_For_Mod1 => GEN_MODULATED_TX_DATA_PACKET_out4  -- uint32
              );

  u_qpsk_srrc : qpsk_srrc
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              d_in_re => GEN_MODULATED_TX_DATA_PACKET_out1,  -- int8
              d_in_im => GEN_MODULATED_TX_DATA_PACKET_out2,  -- int8
              d_out_re => qpsk_srrc_out1_re,  -- sfix12_En11
              d_out_im => qpsk_srrc_out1_im  -- sfix12_En11
              );

  Enable_out3 <= Enable;

  enb_gated <= Enable_out3 AND enb;

  GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1_signed <= signed(GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1);

  
  Compare_To_Constant5_out1 <= '1' WHEN GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1_signed = 0 ELSE
      '0';

  GEN_MODULATED_TX_DATA_PACKET_out4_unsigned <= unsigned(GEN_MODULATED_TX_DATA_PACKET_out4);

  
  Compare_To_Constant4_out1 <= '1' WHEN GEN_MODULATED_TX_DATA_PACKET_out4_unsigned = 85 ELSE
      '0';

  Compare_To_Constant5_out1_1 <= Compare_To_Constant5_out1 AND Compare_To_Constant4_out1;

  Compare_To_Constant5_out1_2 <= Compare_To_Constant5_out1 AND GEN_MODULATED_TX_DATA_PACKET_out3;

  Logical_Operator1_out1 <= Compare_To_Constant5_out1_1 OR Compare_To_Constant5_out1_2;

  FIFO_RD_EN_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Logical_Operator2_out1_last_value <= '0';
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Logical_Operator2_out1_last_value <= Logical_Operator1_out1;
      END IF;
    END IF;
  END PROCESS FIFO_RD_EN_bypass_process;


  
  Logical_Operator2_out1_bypass <= Logical_Operator2_out1_last_value WHEN Enable_out3 = '0' ELSE
      Logical_Operator1_out1;

  qpsk_srrc_out1_re_signed <= signed(qpsk_srrc_out1_re);

  MODULATED_SHAPED_I_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Complex_to_Real_Imag_out1_last_value <= to_signed(0, 12);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Complex_to_Real_Imag_out1_last_value <= qpsk_srrc_out1_re_signed;
      END IF;
    END IF;
  END PROCESS MODULATED_SHAPED_I_bypass_process;


  
  Complex_to_Real_Imag_out1_bypass <= Complex_to_Real_Imag_out1_last_value WHEN Enable_out3 = '0' ELSE
      qpsk_srrc_out1_re_signed;

  MODULATED_SHAPED_I <= std_logic_vector(Complex_to_Real_Imag_out1_bypass);

  qpsk_srrc_out1_im_signed <= signed(qpsk_srrc_out1_im);

  MODULATED_SHAPED_Q_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Complex_to_Real_Imag_out2_last_value <= to_signed(0, 12);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Complex_to_Real_Imag_out2_last_value <= qpsk_srrc_out1_im_signed;
      END IF;
    END IF;
  END PROCESS MODULATED_SHAPED_Q_bypass_process;


  
  Complex_to_Real_Imag_out2_bypass <= Complex_to_Real_Imag_out2_last_value WHEN Enable_out3 = '0' ELSE
      qpsk_srrc_out1_im_signed;

  MODULATED_SHAPED_Q <= std_logic_vector(Complex_to_Real_Imag_out2_bypass);

  GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1_signed_1 <= signed(GEN_MODULATED_TX_DATA_PACKET_EN_COUNTER_out1);


  FIFO_RD_EN <= Logical_Operator2_out1_bypass;

END rtl;

