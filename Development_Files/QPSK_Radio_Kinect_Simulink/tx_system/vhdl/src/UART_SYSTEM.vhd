LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;


ENTITY UART_SYSTEM IS
  PORT (
      CLK_40MHZ_0_DEG           :IN  STD_LOGIC;  -- System clock
      UART_SYSTEM_RESET         :IN  STD_LOGIC;  -- Reset input
      XB_BUS_CLK                :IN  STD_LOGIC;
      XB_USER_W_WRITE_32_DATA   :IN  STD_LOGIC_VECTOR(31 DOWNTO 0);
      XB_USER_W_WRITE_32_WREN   :IN  STD_LOGIC;
      XB_USER_W_WRITE_32_FULL   :OUT STD_LOGIC;
      XB_USER_R_READ_32_RDEN    :IN  STD_LOGIC;
      XB_USER_R_READ_32_EMPTY   :OUT STD_LOGIC;
      XB_USER_R_READ_32_DATA    :OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      CP_UART_RX_FROM_CP        :IN  STD_LOGIC;
      CP_UART_TX_TO_CP          :OUT STD_LOGIC
      );
END UART_SYSTEM;

ARCHITECTURE UART_SYSTEM_ARCH OF UART_SYSTEM IS

  COMPONENT MINIUART IS
    PORT(
       SYSCLK   : IN  STD_LOGIC;  -- System clock
       RESET    : IN  STD_LOGIC;  -- Reset input
       CS_N     : IN  STD_LOGIC;
       RD_N     : IN  STD_LOGIC;
       WR_N     : IN  STD_LOGIC;
       RXD      : IN  STD_LOGIC;
       TXD      : OUT STD_LOGIC;
       INTRX_N  : OUT STD_LOGIC;  -- Receive interrupt
       INTTX_N  : OUT STD_LOGIC;  -- Transmit interrupt
       ADDR     : IN  STD_LOGIC_VECTOR(1 DOWNTO 0);
       DATAIN   : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
       DATAOUT  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
       );
  END COMPONENT;

  COMPONENT FIFO_32X512_ASYNC
    PORT (
      RST     :IN STD_LOGIC;
      WR_CLK  :IN STD_LOGIC;
      RD_CLK  :IN STD_LOGIC;
      DIN     :IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      WR_EN   :IN STD_LOGIC;
      RD_EN   :IN STD_LOGIC;
      DOUT    :OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      FULL    :OUT STD_LOGIC;
      EMPTY   :OUT STD_LOGIC
    );
  END COMPONENT;

  -- Signals
  SIGNAL INTRX_N      	             :STD_LOGIC;
  SIGNAL INTTX_N      	             :STD_LOGIC;
  --SIGNAL UART_DATA_IN_NEXT_BYTE     :STD_LOGIC;
  SIGNAL USER_W_EMPTY               :STD_LOGIC;
  SIGNAL UART_CS_L                  :STD_LOGIC;
  SIGNAL UART_RX_L                  :STD_LOGIC;
  SIGNAL UART_TX_L                  :STD_LOGIC;
  SIGNAL UART_DATA_IN_8             :STD_LOGIC_VECTOR(7 DOWNTO 0);
  SIGNAL UART_DATA_IN_32            :STD_LOGIC_VECTOR(31 DOWNTO 0);
  SIGNAL UART_DATA_IN_MUX_COUNTER   :STD_LOGIC_VECTOR(1 DOWNTO 0);
  SIGNAL UART_TX_RDEN               :STD_LOGIC;
  --SIGNAL UART_INTTX_LAST_VALUE      :STD_LOGIC;
  --SIGNAL USER_W_EMPTY_LAST_VALUE    :STD_LOGIC;
  SIGNAL UART_RESET                 :STD_LOGIC;
  SIGNAL UART_TX_PIPELINE_COUNTER   :STD_LOGIC_VECTOR(2 DOWNTO 0);
  SIGNAL UART_RX_BYTE_COUNTER       :STD_LOGIC_VECTOR(1 DOWNTO 0);
  SIGNAL UART_DATA_OUT_32           :STD_LOGIC_VECTOR(31 DOWNTO 0);
  SIGNAL UART_DATA_OUT_8            :STD_LOGIC_VECTOR(7 DOWNTO 0);
  SIGNAL UART_RX_FIFO_WREN          :STD_LOGIC;
  
  
BEGIN
    
  -- Signal Assignments
UART_RESET <= NOT UART_SYSTEM_RESET;
  
  -- Component Instantiations  
  MINIUART_INST : MINIUART
    PORT MAP(
       SYSCLK   => CLK_40MHZ_0_DEG,  -- System clock
       RESET    => UART_RESET,  -- Reset input
       --RESET    => '1',  -- Reset input
       CS_N     => UART_CS_L,
       RD_N     => UART_RX_L,
       WR_N     => UART_TX_L,
       RXD      => CP_UART_RX_FROM_CP,
       TXD      => CP_UART_TX_TO_CP,
       INTRX_N  => INTRX_N,  -- Receive interrupt
       INTTX_N  => INTTX_N,  -- Transmit interrupt
       ADDR     => "00",
       DATAIN   => UART_DATA_IN_8,
       DATAOUT  => UART_DATA_OUT_8
       );

  -- FIFO passes data from Xillybus IP to UART logic
  FIFO_32X512_ASYNC_USER_W_INST : FIFO_32X512_ASYNC
    PORT MAP (
      RST     => UART_SYSTEM_RESET,
      WR_CLK  => XB_BUS_CLK,
      RD_CLK  => CLK_40MHZ_0_DEG,
      DIN     => XB_USER_W_WRITE_32_DATA,
      WR_EN   => XB_USER_W_WRITE_32_WREN,
      RD_EN   => UART_TX_RDEN,
      DOUT    => UART_DATA_IN_32,
      FULL    => XB_USER_W_WRITE_32_FULL,
      EMPTY   => USER_W_EMPTY
    );
  
    -- FIFO passes data from UART logic to Xillybus IP
    FIFO_32X512_ASYNC_USER_R_INST : FIFO_32X512_ASYNC
    PORT MAP (
      RST     => UART_SYSTEM_RESET,
      WR_CLK  => CLK_40MHZ_0_DEG,
      RD_CLK  => XB_BUS_CLK,
      DIN     => UART_DATA_OUT_32,
      WR_EN   => UART_RX_FIFO_WREN,
      RD_EN   => XB_USER_R_READ_32_RDEN,
      DOUT    => XB_USER_R_READ_32_DATA,
      FULL    => open,
      EMPTY   => XB_USER_R_READ_32_EMPTY
    );
    
  -- Process statements
  
  -- Rising edge detect of UART IntTX signal, rising edge indicates UART is ready for another byte, part 1
--  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
--  BEGIN
--    IF UART_SYSTEM_RESET = '1' THEN
--      UART_INTTX_LAST_VALUE <= '1';
--    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
--      UART_INTTX_LAST_VALUE <= INTTX_N;
--    END IF;
--  END PROCESS;
  
  -- Rising edge detect of UART IntTX signal, rising edge indicates UART is ready for another byte, part 2
  -- Signal to increment FIFO to UART transmitter data counter
  --PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
--  BEGIN
--    IF UART_SYSTEM_RESET = '1' THEN
--      UART_DATA_IN_NEXT_BYTE <= '0';
--    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
--      IF INTTX_N = '1' AND UART_INTTX_LAST_VALUE = '0' THEN -- Rising edge
--        UART_DATA_IN_NEXT_BYTE <= '1';
--      ELSE
--        UART_DATA_IN_NEXT_BYTE <= '0';
--      END IF;
--    END IF;
--  END PROCESS;
  
  -- Select counter for user write FIFO to UART transmitter data
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_DATA_IN_MUX_COUNTER <= "00";
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_TX_L = '0' AND INTTX_N = '1' THEN
        
        UART_DATA_IN_MUX_COUNTER <= UART_DATA_IN_MUX_COUNTER + '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- Mux data from user write FIFO to UART transmitter, 32-bits to 8-bit
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_DATA_IN_8 <= "10100101";
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_DATA_IN_MUX_COUNTER = "00" THEN                   -- MSB first
        UART_DATA_IN_8 <= UART_DATA_IN_32(31 DOWNTO 24);
      ELSIF UART_DATA_IN_MUX_COUNTER = "01" THEN
        UART_DATA_IN_8 <= UART_DATA_IN_32(23 DOWNTO 16);
      ELSIF UART_DATA_IN_MUX_COUNTER = "10" THEN
        UART_DATA_IN_8 <= UART_DATA_IN_32(15 DOWNTO 8);
      ELSIF UART_DATA_IN_MUX_COUNTER = "11" THEN
        UART_DATA_IN_8 <= UART_DATA_IN_32(7 DOWNTO 0);
      END IF;
    END IF;
  END PROCESS;
  
  -- Falling edge detect of user write FIFO empty signal, part 1
--  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
--  BEGIN
--    IF UART_SYSTEM_RESET = '1' THEN
--      USER_W_EMPTY_LAST_VALUE <= '1';
--    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
--      USER_W_EMPTY_LAST_VALUE <= USER_W_EMPTY;
--    END IF;
--  END PROCESS;
  
  -- UART chip select logic, active low, has to stay low until rising edge of IntTX
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_CS_L <= '1';
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_TX_PIPELINE_COUNTER = "010" OR (INTTX_N = '0' AND UART_TX_L = '1' AND UART_DATA_IN_MUX_COUNTER /= "00") OR INTRX_N = '0' THEN
        UART_CS_L <= '0';
      ELSIF (UART_TX_L = '0' AND INTTX_N = '1' AND UART_RX_L = '1') OR 
            (UART_RX_L = '0' AND INTRX_N = '1' AND UART_TX_L = '1') THEN
        UART_CS_L <= '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- UART transmit enable logic, active low, has to stay low until rising edge of IntTX
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_TX_L <= '1';
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_TX_PIPELINE_COUNTER = "010" OR (INTTX_N = '0' AND UART_TX_L = '1' AND UART_DATA_IN_MUX_COUNTER /= "00") THEN
        UART_TX_L <= '0';
      --ELSIF INTTX_N = '1' AND UART_INTTX_LAST_VALUE = '0' THEN
      ELSIF INTTX_N = '1' AND UART_TX_L = '0' THEN
        UART_TX_L <= '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- UART transmit FIFO read enable
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_TX_RDEN <= '0';
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_TX_RDEN = '0' AND USER_W_EMPTY = '0' AND INTTX_N = '0' AND 
         UART_TX_PIPELINE_COUNTER = "100" AND UART_DATA_IN_MUX_COUNTER = "00" THEN -- Data in FIFO and UART TX logic can accept 32-bit data word
        UART_TX_RDEN <= '1';
      ELSE
        UART_TX_RDEN <= '0';
      END IF;
    END IF;
  END PROCESS;
  
  -- UART transmit FIFO output pipeline delay counter
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_TX_PIPELINE_COUNTER <= "100";
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_TX_RDEN = '1' THEN
        UART_TX_PIPELINE_COUNTER <= "000";
      ELSIF UART_TX_PIPELINE_COUNTER /= "100" THEN
        UART_TX_PIPELINE_COUNTER <= UART_TX_PIPELINE_COUNTER + '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- Generate read signal to UART module
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_RX_L <= '1';
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF INTRX_N = '0' THEN
        UART_RX_L <= '0';
      ELSE
        UART_RX_L <= '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- Demux data from UART to user read FIFO, 8-bit to 32-bit using shift register
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_DATA_OUT_32 <= "10100101101001011010010110100101";
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_RX_L = '0' AND INTRX_N = '1' THEN
        UART_DATA_OUT_32 <= UART_DATA_OUT_32(23 DOWNTO 0) & UART_DATA_OUT_8(7 DOWNTO 0);
      END IF;
    END IF;
  END PROCESS;
  
  -- Count bytes received from UART
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_RX_BYTE_COUNTER <= "11";
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF UART_RX_L = '0' AND INTRX_N = '1' THEN
        UART_RX_BYTE_COUNTER <= UART_RX_BYTE_COUNTER + '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- Once a 32-bit word has been received by the UART module from the serial interface, write it to the FIFO for access by software.  At the
  -- same time that the last byte of the 32-bits is shifted out of the UART module assert the WREN
  PROCESS(UART_SYSTEM_RESET, CLK_40MHZ_0_DEG)
  BEGIN
    IF UART_SYSTEM_RESET = '1' THEN
      UART_RX_FIFO_WREN <= '0';
    ELSIF CLK_40MHZ_0_DEG'EVENT AND CLK_40MHZ_0_DEG = '1' THEN
      IF INTRX_N = '1' AND UART_RX_L = '0' AND UART_RX_BYTE_COUNTER = "10" THEN
        UART_RX_FIFO_WREN <= '1';
      ELSE
        UART_RX_FIFO_WREN <= '0';
      END IF;
    END IF;
  END PROCESS;
    
  
END UART_SYSTEM_ARCH;




