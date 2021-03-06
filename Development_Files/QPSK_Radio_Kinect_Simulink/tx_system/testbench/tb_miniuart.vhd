LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY TB_MINIUART IS
END TB_MINIUART;

ARCHITECTURE TB_MINIUART_ARCH OF TB_MINIUART IS

  COMPONENT MINIUART IS
    PORT (
       SYSCLK   : IN  STD_LOGIC;  -- System clock
       RESET    : IN  STD_LOGIC;  -- Reset input
       CS_N     : IN  STD_LOGIC;
       RD_N     : IN  STD_LOGIC;
       WR_N     : IN  STD_LOGIC;
       RXD      : IN  STD_LOGIC;
       TXD      : OUT STD_LOGIC;
       INTRX_N  : OUT STD_LOGIC;  -- Receive interrupt
       INTTX_N  : OUT STD_LOGIC;  -- Transmit interrupt
       ADDR     : IN  STD_LOGIC_VECTOR(1 DOWNTO 0); -- 
       DATAIN   : IN  STD_LOGIC_VECTOR(7 DOWNTO 0); -- 
       DATAOUT  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)); -- 
  END COMPONENT;

  --SIGNAL  TB_BUS_CLK_COUNTER      :  STD_LOGIC_VECTOR(31 DOWNTO 0);
  SIGNAL  TB_RESET_8              :  STD_LOGIC:='1';
  SIGNAL  TB_CLK_40MHZ_FROM_CP    :  STD_LOGIC:='0';
  SIGNAL  TB_DATAIN  :  STD_LOGIC;
  SIGNAL  TB_TXD    :  STD_LOGIC;
  SIGNAL  TB_INTRX_N     :  STD_LOGIC;
  SIGNAL  TB_INTTX_N   :  STD_LOGIC;
  
  
BEGIN
  
  TB_CLK_40MHZ_FROM_CP  <= NOT TB_CLK_40MHZ_FROM_CP AFTER 12.5 NS;
  
  TB_RESET_8  <= '0' AFTER 75 NS;
  
  
--  TB_BUS_CLK_COUNTER_PROC : PROCESS (TB_BUS_CLK, TB_RESET_8)
--  BEGIN
--    IF TB_RESET_8 = '1' THEN
--      TB_BUS_CLK_COUNTER <= (OTHERS => '0');
--    ELSIF TB_BUS_CLK'EVENT AND TB_BUS_CLK = '1' THEN
--      TB_BUS_CLK_COUNTER <= TB_BUS_CLK_COUNTER + '1';
--    END IF;
--  END PROCESS TB_BUS_CLK_COUNTER_PROC;
  
  -- Generate TX data
  XILLY_DATA_MODEL_PROC : PROCESS (TB_BUS_CLK, TB_RESET_8)
  BEGIN
    IF TB_RESET_8 = '1' THEN
      TB_DATAIN <= (OTHERS => '0');
    ELSIF TB_BUS_CLK'EVENT AND TB_BUS_CLK = '1' THEN
      IF TB_WR_N = '1' THEN
        TB_DATAIN <= TB_DATAIN + '1';
      END IF;
    END IF;
  END PROCESS XILLY_DATA_MODEL_PROC;
  
  -- Write enable
  TB_WR_N_PROC : PROCESS (TB_BUS_CLK, TB_RESET_8)
  BEGIN
    IF TB_RESET_8 = '1' THEN
      TB_WR_N <= '1';
    ELSIF TB_BUS_CLK'EVENT AND TB_BUS_CLK = '1' THEN
      IF TB_BUS_CLK_COUNTER = "00000000000000000000000111110011" THEN
        TB_WR_N <= '0';
      ELSE
        TB_WR_N <= '1';
      END IF;
    END IF;
  END PROCESS XILLY_WREN_MODEL_PROC;

  MINIUART_INST : MINIUART
    PORT MAP (
       SYSCLK   => TB_CLK_40MHZ_FROM_CP,
       RESET    => TB_RESET_8,    -- Reset input
       CS_N     => '0',
       RD_N     => '1',
       WR_N     => TB_WR_N,
       RXD      => '1',
       TXD      => TB_TXD,
       INTRX_N  => TB_INTRX_N,    -- Receive interrupt
       INTTX_N  => TB_INTTX_N,    -- Transmit interrupt
       ADDR     => "00",
       DATAIN   => TB_DATAIN,
       DATAOUT  => TB_DATAOUT
       );

  
END TB_MINIUART_ARCH;



