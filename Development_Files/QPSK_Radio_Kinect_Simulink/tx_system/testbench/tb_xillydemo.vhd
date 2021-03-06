library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity tb_xillydemo is
end tb_xillydemo;

architecture tb_xillydemo_arch of tb_xillydemo is

  COMPONENT RF_TX_TOP IS
    PORT (
      -- Xillybus IP to FIFO interface signals
      XB_RESET_8                  :IN  STD_LOGIC;
      XB_RESET_32                 :IN  STD_LOGIC;
      XB_BUS_CLK                  :IN  STD_LOGIC;
      XB_USER_W_WRITE_8_DATA      :IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
      XB_USER_W_WRITE_8_WREN      :IN  STD_LOGIC;
      XB_USER_W_WRITE_8_FULL      :OUT STD_LOGIC;
      XB_USER_W_WRITE_32_DATA     :IN  STD_LOGIC_VECTOR(31 DOWNTO 0);
      XB_USER_W_WRITE_32_WREN     :IN  STD_LOGIC;
      XB_USER_W_WRITE_32_FULL     :OUT STD_LOGIC;
      XB_USER_R_READ_32_RDEN      :IN  STD_LOGIC;
      XB_USER_R_READ_32_EMPTY     :OUT STD_LOGIC;
      XB_USER_R_READ_32_DATA      :OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      -- Chilipepper interface signals
      CP_CLK_40MHz_FROM_CP_EXT    :IN  STD_LOGIC;  -- 40 Mhz clock provided by Chilipepper
      CP_UART_TX_TO_CP_EXT        :OUT STD_LOGIC;  -- Transmit to Chilipepper microcontroller
      CP_UART_RX_FROM_CP_EXT      :IN  STD_LOGIC;  -- Receive to Chilipepper microcontroller
      CP_TX_EN_EXT                :OUT STD_LOGIC;  -- Transmit enable to Chilipepper
      CP_TX_RX_SW_EXT             :OUT STD_LOGIC;  -- Chilipepper Transmit/Receive antenna switch
      CP_RX_EN_EXT                :OUT STD_LOGIC;  -- Receive enable to Chilipepper
      CP_PA_EN_EXT                :OUT STD_LOGIC;  -- Power amplifier enable to Chilipepper
      CP_INIT_DONE_EXT            :IN  STD_LOGIC;  -- Chilipepper microcontroller config complete
      CP_MCU_RESET_L_EXT          :OUT STD_LOGIC;
      CP_TX_DAC_CLK_EXT           :OUT STD_LOGIC;
      CP_TXD_EXT                  :OUT STD_LOGIC_VECTOR(11 DOWNTO 0);   -- SFIX12_EN11
      CP_TX_IQ_SEL_EXT            :OUT STD_LOGIC                        -- UFIX1
      );
  END COMPONENT;


  SIGNAL  TB_XB_BUS_CLK_COUNTER      :  STD_LOGIC_VECTOR(31 DOWNTO 0);

  SIGNAL  TB_PS_CLK               :  STD_LOGIC:='0';
  SIGNAL  TB_PS_PORB              :  STD_LOGIC:='1';
  SIGNAL  TB_XB_RESET_8              :  STD_LOGIC:='1';
  SIGNAL  TB_XB_RESET_32             :  STD_LOGIC:='1';
  SIGNAL  TB_CLK_100              :  STD_LOGIC:='0';
  SIGNAL  TB_XB_BUS_CLK              :  STD_LOGIC:='0';
  SIGNAL  TB_CLK_40MHZ_FROM_CP    :  STD_LOGIC:='0';
  
  SIGNAL  TB_XB_USER_W_WRITE_8_DATA  :  STD_LOGIC_VECTOR(7 DOWNTO 0);
  SIGNAL  TB_XB_USER_W_WRITE_8_WREN  :  STD_LOGIC:='0';
  SIGNAL  TB_XB_USER_W_WRITE_8_FULL  :  STD_LOGIC;
  
  SIGNAL  TB_XB_USER_W_WRITE_32_DATA  :STD_LOGIC_VECTOR(31 DOWNTO 0);
  SIGNAL  TB_XB_USER_W_WRITE_32_WREN  :STD_LOGIC:='0';
  SIGNAL  TB_XB_USER_W_WRITE_32_FULL         :  STD_LOGIC;
  
  SIGNAL  TB_XB_USER_R_READ_32_EMPTY         :  STD_LOGIC;
  SIGNAL  TB_XB_USER_R_READ_32_DATA         :  STD_LOGIC_VECTOR(31 DOWNTO 0);
  
  SIGNAL  TB_CP_TX_DAC_CLK_EXT    :  STD_LOGIC;
  SIGNAL  TB_CP_TXD_EXT           :  STD_LOGIC_VECTOR(11 DOWNTO 0);
  SIGNAL  TB_CP_TX_IQ_SEL_EXT     :  STD_LOGIC;
  SIGNAL  TB_CP_MCU_RESET_L_EXT   :  STD_LOGIC;
  
  SIGNAL  TB_CP_TX_EN_EXT         :  STD_LOGIC;
  SIGNAL  TB_CP_TX_RX_SW_EXT      :  STD_LOGIC;
  SIGNAL  TB_CP_RX_EN_EXT         :  STD_LOGIC;
  SIGNAL  TB_CP_PA_EN_EXT         :  STD_LOGIC;

  SIGNAL  TB_CP_UART_TX_TO_CP_EXT :  STD_LOGIC;
  SIGNAL  TB_WRAP                 :  STD_LOGIC;
  
  
BEGIN
  
  TB_PS_CLK             <= NOT TB_PS_CLK            AFTER 5 NS;
  TB_CLK_100            <= NOT TB_CLK_100           AFTER 5 NS;
  TB_XB_BUS_CLK         <= NOT TB_XB_BUS_CLK        AFTER 5 NS;
  TB_CLK_40MHZ_FROM_CP  <= NOT TB_CLK_40MHZ_FROM_CP AFTER 12.5 NS;
  
  TB_PS_PORB      <= '0' AFTER 50 NS;
  TB_XB_RESET_8   <= '0' AFTER 75 NS;
  TB_XB_RESET_32  <= '0' AFTER 75 NS;
  
  
  TB_XB_BUS_CLK_COUNTER_PROC : PROCESS (TB_XB_BUS_CLK, TB_XB_RESET_8)
  BEGIN
    IF TB_XB_RESET_8 = '1' THEN
      TB_XB_BUS_CLK_COUNTER <= (OTHERS => '0');
    ELSIF TB_XB_BUS_CLK'EVENT AND TB_XB_BUS_CLK = '1' THEN
      TB_XB_BUS_CLK_COUNTER <= TB_XB_BUS_CLK_COUNTER + '1';
    END IF;
  END PROCESS TB_XB_BUS_CLK_COUNTER_PROC;
  
  
  XILLY_8_DATA_MODEL_PROC : PROCESS (TB_XB_BUS_CLK, TB_XB_RESET_8)
  BEGIN
    IF TB_XB_RESET_8 = '1' THEN
      TB_XB_USER_W_WRITE_8_DATA <= (OTHERS => '0');
    ELSIF TB_XB_BUS_CLK'EVENT AND TB_XB_BUS_CLK = '1' THEN
      IF TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111110011" THEN
        TB_XB_USER_W_WRITE_8_DATA <= TB_XB_USER_W_WRITE_8_DATA + '1';
      END IF;
    END IF;
  END PROCESS XILLY_8_DATA_MODEL_PROC;
  
    
  XILLY_8_WREN_MODEL_PROC : PROCESS (TB_XB_BUS_CLK, TB_XB_RESET_8)
  BEGIN
    IF TB_XB_RESET_8 = '1' THEN
      TB_XB_USER_W_WRITE_8_WREN <= '0';
    ELSIF TB_XB_BUS_CLK'EVENT AND TB_XB_BUS_CLK = '1' THEN
      IF TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111110011" THEN
        TB_XB_USER_W_WRITE_8_WREN <= '1';
      ELSE
        TB_XB_USER_W_WRITE_8_WREN <= '0';
      END IF;
    END IF;
  END PROCESS XILLY_8_WREN_MODEL_PROC;
  
  
  XILLY_32_DATA_MODEL_PROC : PROCESS (TB_XB_BUS_CLK, TB_XB_RESET_32)
  BEGIN
    IF TB_XB_RESET_32 = '1' THEN
      --TB_XB_USER_W_WRITE_32_DATA <= (OTHERS => '0');
      TB_XB_USER_W_WRITE_32_DATA <= "11111111000000000000000111111110";
    ELSIF TB_XB_BUS_CLK'EVENT AND TB_XB_BUS_CLK = '1' THEN
      IF TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111111100" THEN -- Next clock
      --IF TB_XB_BUS_CLK_COUNTER = "00000000000010001110010110001100" THEN -- Time for FIFO to empty before subsequent write
        TB_XB_USER_W_WRITE_32_DATA <= "11111111000000010001100111111110";
      ELSIF TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111111101" THEN -- Next clock
        TB_XB_USER_W_WRITE_32_DATA <= "11111111000000100000000111111110";
      END IF;
    END IF;
  END PROCESS XILLY_32_DATA_MODEL_PROC;
  
    
  XILLY_32_WREN_MODEL_PROC : PROCESS (TB_XB_BUS_CLK, TB_XB_RESET_32)
  BEGIN
    IF TB_XB_RESET_32 = '1' THEN
      TB_XB_USER_W_WRITE_32_WREN <= '0';
    ELSIF TB_XB_BUS_CLK'EVENT AND TB_XB_BUS_CLK = '1' THEN
      IF TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111111011" OR 
         TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111111100" OR
         TB_XB_BUS_CLK_COUNTER = "00000000000000000000000111111101" THEN   -- Next clock
         --TB_XB_BUS_CLK_COUNTER = "00000000000010001110010110001100" THEN   -- Time for FIFO to empty before subsequent write
        TB_XB_USER_W_WRITE_32_WREN <= '1';
      ELSE
        TB_XB_USER_W_WRITE_32_WREN <= '0';
      END IF;
    END IF;
  END PROCESS XILLY_32_WREN_MODEL_PROC;

      
  RF_TX_TOP_INST : RF_TX_TOP
  PORT MAP( 
      -- Xillybus IP to FIFO interface signals
      XB_RESET_8                  => TB_XB_RESET_8,
      XB_RESET_32                 => TB_XB_RESET_32,
      XB_BUS_CLK                  => TB_XB_BUS_CLK,
      XB_USER_W_WRITE_8_DATA      => TB_XB_USER_W_WRITE_8_DATA,
      XB_USER_W_WRITE_8_WREN      => TB_XB_USER_W_WRITE_8_WREN,
      XB_USER_W_WRITE_8_FULL      => TB_XB_USER_W_WRITE_8_FULL,
      XB_USER_W_WRITE_32_DATA     => TB_XB_USER_W_WRITE_32_DATA,
      XB_USER_W_WRITE_32_WREN     => TB_XB_USER_W_WRITE_32_WREN,
      XB_USER_W_WRITE_32_FULL     => TB_XB_USER_W_WRITE_32_FULL,
      XB_USER_R_READ_32_RDEN      => '0',
      XB_USER_R_READ_32_EMPTY     => TB_XB_USER_R_READ_32_EMPTY,
      XB_USER_R_READ_32_DATA      => TB_XB_USER_R_READ_32_DATA,
      -- Chilipepper interface signals
      CP_CLK_40MHz_FROM_CP_EXT    => TB_CLK_40MHz_FROM_CP,   -- 40 Mhz clock provided by Chilipepper
      --CP_UART_TX_TO_CP_EXT        => TB_WRAP,                      -- Transmit to Chilipepper microcontroller
      CP_UART_TX_TO_CP_EXT        => TB_CP_UART_TX_TO_CP_EXT,                      -- Transmit to Chilipepper microcontroller
      CP_UART_RX_FROM_CP_EXT      => TB_WRAP,                      -- Receive to Chilipepper microcontroller
      --CP_UART_RX_FROM_CP_EXT      => '1',                      -- Receive to Chilipepper microcontroller
      CP_TX_EN_EXT                => TB_CP_TX_EN_EXT,                       -- Transmit enable to Chilipepper
      CP_TX_RX_SW_EXT             => TB_CP_TX_RX_SW_EXT,                       -- Chilipepper Transmit/Receive antenna switch
      CP_RX_EN_EXT                => TB_CP_RX_EN_EXT,                      -- Receive enable to Chilipepper
      CP_PA_EN_EXT                => TB_CP_PA_EN_EXT,                      -- Power amplifier enable to Chilipepper
      CP_INIT_DONE_EXT            => '1',                     -- Chilipepper microcontroller config complete
      CP_MCU_RESET_L_EXT          => TB_CP_MCU_RESET_L_EXT,
      CP_TX_DAC_CLK_EXT           => TB_CP_TX_DAC_CLK_EXT,
      CP_TXD_EXT                  => TB_CP_TXD_EXT,                            -- SFIX12_EN11
      CP_TX_IQ_SEL_EXT            => TB_CP_TX_IQ_SEL_EXT                       -- UFIX1
      );
  
  -- One clock delay on wrap
  PROCESS (TB_CLK_40MHz_FROM_CP, TB_XB_RESET_32)
  BEGIN
    IF TB_XB_RESET_32 = '1' THEN
      TB_WRAP <= '1';
    ELSIF TB_CLK_40MHz_FROM_CP'EVENT AND TB_CLK_40MHz_FROM_CP = '1' THEN
      TB_WRAP <= TB_CP_UART_TX_TO_CP_EXT;
    END IF;
  END PROCESS;
  
  
end tb_xillydemo_arch;

