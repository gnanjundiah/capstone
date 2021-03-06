-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\IQ_Parser.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: IQ_Parser
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET/Message_Data/IQ_Parser
-- Hierarchy Level: 6
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY IQ_Parser IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        MESSAGE_DATA_BYTE                 :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        INITIALIZE_TX_CORE                :   IN    std_logic;
        MESSAGE_I_BINARY                  :   OUT   std_logic;  -- ufix1
        MESSAGE_Q_BINARY                  :   OUT   std_logic;  -- ufix1
        Get_New_Data_Byte_For_Mod         :   OUT   std_logic;
        Data_IQ_Parser_Counter_Copy       :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
        );
END IQ_Parser;


ARCHITECTURE rtl OF IQ_Parser IS

  -- Component Declarations
  COMPONENT MESSAGE_BIT_MUX_COUNTER
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          INITIALIZE_MESSAGE_BIT_MUX_COUNTER :   IN    std_logic;
          MESSAGE_BIT_MUX_COUNT           :   OUT   std_logic_vector(31 DOWNTO 0)  -- uint32
          );
  END COMPONENT;

  COMPONENT Int2Bits
    PORT( u                               :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
          y                               :   OUT   std_logic_vector(0 TO 7)  -- ufix1 [8]
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : MESSAGE_BIT_MUX_COUNTER
    USE ENTITY work.MESSAGE_BIT_MUX_COUNTER(rtl);

  FOR ALL : Int2Bits
    USE ENTITY work.Int2Bits(rtl);

  -- Signals
  SIGNAL MESSAGE_BIT_MUX_COUNTER_out1     : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL MESSAGE_BIT_MUX_COUNTER_out1_unsigned : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL Int2Bits_out1                    : std_logic_vector(0 TO 7);  -- ufix1 [8]
  SIGNAL Int2Bits_out1_7                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_5                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_3                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_1                  : std_logic;  -- ufix1
  SIGNAL MESSAGE_I_BIT_MUX_out1           : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_6                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_4                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_2                  : std_logic;  -- ufix1
  SIGNAL Int2Bits_out1_0                  : std_logic;  -- ufix1
  SIGNAL MESSAGE_Q_BIT_MUX_out1           : std_logic;  -- ufix1
  SIGNAL Compare_To_Constant_out1         : std_logic;

BEGIN
  u_MESSAGE_BIT_MUX_COUNTER : MESSAGE_BIT_MUX_COUNTER
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb,
              INITIALIZE_MESSAGE_BIT_MUX_COUNTER => INITIALIZE_TX_CORE,
              MESSAGE_BIT_MUX_COUNT => MESSAGE_BIT_MUX_COUNTER_out1  -- uint32
              );

  u_Int2Bits : Int2Bits
    PORT MAP( u => MESSAGE_DATA_BYTE,  -- uint8
              y => Int2Bits_out1  -- ufix1 [8]
              );

  MESSAGE_BIT_MUX_COUNTER_out1_unsigned <= unsigned(MESSAGE_BIT_MUX_COUNTER_out1);

  Int2Bits_out1_7 <= Int2Bits_out1(7);

  Int2Bits_out1_5 <= Int2Bits_out1(5);

  Int2Bits_out1_3 <= Int2Bits_out1(3);

  Int2Bits_out1_1 <= Int2Bits_out1(1);

  
  MESSAGE_I_BIT_MUX_out1 <= Int2Bits_out1_7 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 0 ELSE
      Int2Bits_out1_5 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 1 ELSE
      Int2Bits_out1_3 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 2 ELSE
      Int2Bits_out1_1;

  Int2Bits_out1_6 <= Int2Bits_out1(6);

  Int2Bits_out1_4 <= Int2Bits_out1(4);

  Int2Bits_out1_2 <= Int2Bits_out1(2);

  Int2Bits_out1_0 <= Int2Bits_out1(0);

  
  MESSAGE_Q_BIT_MUX_out1 <= Int2Bits_out1_6 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 0 ELSE
      Int2Bits_out1_4 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 1 ELSE
      Int2Bits_out1_2 WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 2 ELSE
      Int2Bits_out1_0;

  
  Compare_To_Constant_out1 <= '1' WHEN MESSAGE_BIT_MUX_COUNTER_out1_unsigned = 0 ELSE
      '0';

  MESSAGE_I_BINARY <= MESSAGE_I_BIT_MUX_out1;

  MESSAGE_Q_BINARY <= MESSAGE_Q_BIT_MUX_out1;

  Get_New_Data_Byte_For_Mod <= Compare_To_Constant_out1;

  Data_IQ_Parser_Counter_Copy <= MESSAGE_BIT_MUX_COUNTER_out1;

END rtl;

