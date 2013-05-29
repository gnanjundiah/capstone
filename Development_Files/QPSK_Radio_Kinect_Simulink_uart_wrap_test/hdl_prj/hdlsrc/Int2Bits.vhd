-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\Int2Bits.vhd
-- Created: 2013-05-14 21:08:20
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: Int2Bits
-- Source Path: QPSK_Transmit_v12a/TX_SYSTEM_TOP/TX_CORE_DELAYED_SUBSYSTEM/TX_CORE/GEN_MOD_SHAPED_TX_DATA_PACKET/GEN_MODULATED_TX_DATA_PACKET/Message_Data/IQ_Parser/Int2Bits
-- Hierarchy Level: 7
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE work.TX_SYSTEM_TOP_pkg.ALL;

ENTITY Int2Bits IS
  PORT( u                                 :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        y                                 :   OUT   std_logic_vector(0 TO 7)  -- ufix1 [8]
        );
END Int2Bits;


ARCHITECTURE rtl OF Int2Bits IS

  -- Signals
  SIGNAL u_unsigned                       : unsigned(7 DOWNTO 0);  -- uint8

BEGIN
  u_unsigned <= unsigned(u);

  Int2Bits_1_output : PROCESS (u_unsigned)
    VARIABLE c : std_logic_vector(0 TO 7);
    VARIABLE bit1 : signed(31 DOWNTO 0);
    VARIABLE bit_idx : unsigned(7 DOWNTO 0);
    VARIABLE sub_temp : vector_of_signed32(0 TO 7);
  BEGIN
    -- Converts Integer(8bits) to a 1-D array Bits

    FOR k IN 0 TO 7 LOOP
      bit1 := to_signed(8 - k, 32);
      sub_temp(k) := bit1 - 1;
      bit_idx := unsigned(sub_temp(k)(7 DOWNTO 0));
      c(k) := u_unsigned(to_integer(bit_idx));
    END LOOP;

    y <= c;
  END PROCESS Int2Bits_1_output;


END rtl;

