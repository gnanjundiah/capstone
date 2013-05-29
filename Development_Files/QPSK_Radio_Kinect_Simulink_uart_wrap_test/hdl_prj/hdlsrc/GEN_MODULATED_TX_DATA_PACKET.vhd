-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\GEN_MODULATED_TX_DATA_PACKET.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: GEN_MODULATED_TX_DATA_PACKET
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET
-- Hierarchy Level: 4
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY GEN_MODULATED_TX_DATA_PACKET IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        MESSAGE_DATA_BYTE                 :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        INITIALIZE_TX_CORE                :   IN    std_logic;
        Enable                            :   IN    std_logic;
        MODULATED_I_DATA                  :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
        MODULATED_Q_DATA                  :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
        Get_New_Data_Byte_For_Mod         :   OUT   std_logic;
        Get_New_Data_Byte_For_Mod1        :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END GEN_MODULATED_TX_DATA_PACKET;


ARCHITECTURE rtl OF GEN_MODULATED_TX_DATA_PACKET IS

  -- Component Declarations
  COMPONENT HEADER_MESSAGE_MUX_COUNTER
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          INITIALIZE_HEADER_MESSAGE_MUX_COUNTER :   IN    std_logic;
          HEADER_MESSAGE_MUX_COUNT        :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  COMPONENT Message_Data
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          MESSAGE_DATA_BYTE               :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
          INITIALIZE_TX_CORE              :   IN    std_logic;
          Enable                          :   IN    std_logic;
          MESSAGE_I_MODULATED             :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
          MESSAGE_Q_MODULATED             :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
          Message_I_Binary                :   OUT   std_logic;  -- ufix1
          Message_Q_Binary                :   OUT   std_logic;  -- ufix1
          Get_New_Data_Byte_For_Parser    :   OUT   std_logic;
          Data_IQ_Parser_Counter          :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  COMPONENT Header_Data
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          INITIALIZE_TX_CORE              :   IN    std_logic;
          Enable                          :   IN    std_logic;
          HEADER_I                        :   OUT   std_logic_vector(7 DOWNTO 0);  -- int8
          HEADER_Q                        :   OUT   std_logic_vector(7 DOWNTO 0)  -- int8
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : HEADER_MESSAGE_MUX_COUNTER
    USE ENTITY work.HEADER_MESSAGE_MUX_COUNTER(rtl);

  FOR ALL : Message_Data
    USE ENTITY work.Message_Data(rtl);

  FOR ALL : Header_Data
    USE ENTITY work.Header_Data(rtl);

  -- Signals
  SIGNAL enb_gated                        : std_logic;
  SIGNAL Enable_out3                      : std_logic;
  SIGNAL HEADER_MESSAGE_MUX_COUNTER_out1  : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL HEADER_MESSAGE_MUX_COUNTER_out1_unsigned : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Compare_To_Constant3_out1        : std_logic;
  SIGNAL Compare_To_Constant2_out1        : std_logic;
  SIGNAL Message_Data_out1                : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL Message_Data_out2                : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL Message_Data_out3                : std_logic;  -- ufix1
  SIGNAL Message_Data_out4                : std_logic;  -- ufix1
  SIGNAL Message_Data_out5                : std_logic;
  SIGNAL Message_Data_out6                : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL Message_Data_out1_signed         : signed(7 DOWNTO 0);  -- int8
  SIGNAL Compare_To_Constant4_out1        : std_logic;
  SIGNAL Header_Data_out1                 : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL Header_Data_out2                 : std_logic_vector(7 DOWNTO 0);  -- ufix8
  SIGNAL Header_Data_out1_signed          : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_I_out1        : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_I_out1_last_value : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_I_out1_bypass : signed(7 DOWNTO 0);  -- int8
  SIGNAL Compare_To_Constant1_out1        : std_logic;
  SIGNAL Message_Data_out2_signed         : signed(7 DOWNTO 0);  -- int8
  SIGNAL Header_Data_out2_signed          : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_Q_out1        : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_Q_out1_last_value : signed(7 DOWNTO 0);  -- int8
  SIGNAL HEADER_MESSAGE_MUX_Q_out1_bypass : signed(7 DOWNTO 0);  -- int8
  SIGNAL Message_Data_out5_last_value     : std_logic;
  SIGNAL Message_Data_out5_bypass         : std_logic;
  SIGNAL HEADER_MESSAGE_MUX_COUNTER_out1_last_value : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL HEADER_MESSAGE_MUX_COUNTER_out1_bypass : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL MESSAGE_DATA_BYTE_unsigned       : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Message_Data_out6_unsigned       : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Message_Data_out1_signed_1       : signed(7 DOWNTO 0);  -- int8
  SIGNAL Message_Data_out2_signed_1       : signed(7 DOWNTO 0);  -- int8
  SIGNAL Header_Data_out1_signed_1        : signed(7 DOWNTO 0);  -- int8
  SIGNAL Header_Data_out2_signed_1        : signed(7 DOWNTO 0);  -- int8

BEGIN
  u_HEADER_MESSAGE_MUX_COUNTER : HEADER_MESSAGE_MUX_COUNTER
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              INITIALIZE_HEADER_MESSAGE_MUX_COUNTER => INITIALIZE_TX_CORE,
              HEADER_MESSAGE_MUX_COUNT => HEADER_MESSAGE_MUX_COUNTER_out1  -- uint32
              );

  u_Message_Data : Message_Data
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              MESSAGE_DATA_BYTE => MESSAGE_DATA_BYTE,  -- uint8
              INITIALIZE_TX_CORE => INITIALIZE_TX_CORE,
              Enable => Compare_To_Constant2_out1,
              MESSAGE_I_MODULATED => Message_Data_out1,  -- int8
              MESSAGE_Q_MODULATED => Message_Data_out2,  -- int8
              Message_I_Binary => Message_Data_out3,  -- ufix1
              Message_Q_Binary => Message_Data_out4,  -- ufix1
              Get_New_Data_Byte_For_Parser => Message_Data_out5,
              Data_IQ_Parser_Counter => Message_Data_out6  -- uint32
              );

  u_Header_Data : Header_Data
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb_gated,
              INITIALIZE_TX_CORE => INITIALIZE_TX_CORE,
              Enable => Compare_To_Constant4_out1,
              HEADER_I => Header_Data_out1,  -- int8
              HEADER_Q => Header_Data_out2  -- int8
              );

  Enable_out3 <= Enable;

  enb_gated <= Enable_out3 AND enb;

  HEADER_MESSAGE_MUX_COUNTER_out1_unsigned <= unsigned(HEADER_MESSAGE_MUX_COUNTER_out1);

  
  Compare_To_Constant3_out1 <= '1' WHEN HEADER_MESSAGE_MUX_COUNTER_out1_unsigned <= 88 ELSE
      '0';

  
  Compare_To_Constant2_out1 <= '1' WHEN HEADER_MESSAGE_MUX_COUNTER_out1_unsigned >= 89 ELSE
      '0';

  Message_Data_out1_signed <= signed(Message_Data_out1);

  
  Compare_To_Constant4_out1 <= '1' WHEN HEADER_MESSAGE_MUX_COUNTER_out1_unsigned <= 89 ELSE
      '0';

  Header_Data_out1_signed <= signed(Header_Data_out1);

  
  HEADER_MESSAGE_MUX_I_out1 <= Message_Data_out1_signed WHEN Compare_To_Constant3_out1 = '0' ELSE
      Header_Data_out1_signed;

  MODULATED_I_DATA_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      HEADER_MESSAGE_MUX_I_out1_last_value <= to_signed(0, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        HEADER_MESSAGE_MUX_I_out1_last_value <= HEADER_MESSAGE_MUX_I_out1;
      END IF;
    END IF;
  END PROCESS MODULATED_I_DATA_bypass_process;


  
  HEADER_MESSAGE_MUX_I_out1_bypass <= HEADER_MESSAGE_MUX_I_out1_last_value WHEN Enable_out3 = '0' ELSE
      HEADER_MESSAGE_MUX_I_out1;

  MODULATED_I_DATA <= std_logic_vector(HEADER_MESSAGE_MUX_I_out1_bypass);

  
  Compare_To_Constant1_out1 <= '1' WHEN HEADER_MESSAGE_MUX_COUNTER_out1_unsigned <= 88 ELSE
      '0';

  Message_Data_out2_signed <= signed(Message_Data_out2);

  Header_Data_out2_signed <= signed(Header_Data_out2);

  
  HEADER_MESSAGE_MUX_Q_out1 <= Message_Data_out2_signed WHEN Compare_To_Constant1_out1 = '0' ELSE
      Header_Data_out2_signed;

  MODULATED_Q_DATA_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      HEADER_MESSAGE_MUX_Q_out1_last_value <= to_signed(0, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        HEADER_MESSAGE_MUX_Q_out1_last_value <= HEADER_MESSAGE_MUX_Q_out1;
      END IF;
    END IF;
  END PROCESS MODULATED_Q_DATA_bypass_process;


  
  HEADER_MESSAGE_MUX_Q_out1_bypass <= HEADER_MESSAGE_MUX_Q_out1_last_value WHEN Enable_out3 = '0' ELSE
      HEADER_MESSAGE_MUX_Q_out1;

  MODULATED_Q_DATA <= std_logic_vector(HEADER_MESSAGE_MUX_Q_out1_bypass);

  Get_New_Data_Byte_For_Mod_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Message_Data_out5_last_value <= '0';
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        Message_Data_out5_last_value <= Message_Data_out5;
      END IF;
    END IF;
  END PROCESS Get_New_Data_Byte_For_Mod_bypass_process;


  
  Message_Data_out5_bypass <= Message_Data_out5_last_value WHEN Enable_out3 = '0' ELSE
      Message_Data_out5;

  Get_New_Data_Byte_For_Mod1_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      HEADER_MESSAGE_MUX_COUNTER_out1_last_value <= to_unsigned(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_gated = '1' THEN
        HEADER_MESSAGE_MUX_COUNTER_out1_last_value <= HEADER_MESSAGE_MUX_COUNTER_out1_unsigned;
      END IF;
    END IF;
  END PROCESS Get_New_Data_Byte_For_Mod1_bypass_process;


  
  HEADER_MESSAGE_MUX_COUNTER_out1_bypass <= HEADER_MESSAGE_MUX_COUNTER_out1_last_value WHEN Enable_out3 = '0' ELSE
      HEADER_MESSAGE_MUX_COUNTER_out1_unsigned;

  Get_New_Data_Byte_For_Mod1 <= std_logic_vector(HEADER_MESSAGE_MUX_COUNTER_out1_bypass);


  MESSAGE_DATA_BYTE_unsigned <= unsigned(MESSAGE_DATA_BYTE);

  Message_Data_out6_unsigned <= unsigned(Message_Data_out6);


  Message_Data_out1_signed_1 <= signed(Message_Data_out1);

  Message_Data_out2_signed_1 <= signed(Message_Data_out2);


  Header_Data_out1_signed_1 <= signed(Header_Data_out1);

  Header_Data_out2_signed_1 <= signed(Header_Data_out2);


  Get_New_Data_Byte_For_Mod <= Message_Data_out5_bypass;

END rtl;
