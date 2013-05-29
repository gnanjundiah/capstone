LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

LIBRARY UNISIM;
USE UNISIM.VCOMPONENTS.ALL;

ENTITY RF_TX_TOP IS
  PORT (
    -- Xillybus IP to FIFO interface signals
    RESET_FROM_XILLYBUS         :IN  STD_LOGIC;
    WR_CLK                      :IN  STD_LOGIC;
    USER_W_WRITE_8_DATA         :IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
    USER_W_WRITE_8_WREN         :IN  STD_LOGIC;
    USER_W_WRITE_8_FULL         :OUT STD_LOGIC;
    -- Chilipepper interface signals
    CLK_40MHz_FROM_CP_EXT       :IN  STD_LOGIC;  -- 40 Mhz clock provided by Chilipepper
--    UART_TX_TO_CP_EXT               :OUT STD_LOGIC;                       -- Transmit to Chilipepper microcontroller
--    UART_RX_FROM_CP_EXT             :IN  STD_LOGIC;                       -- Receive to Chilipepper microcontroller
    CP_TX_EN_EXT                :OUT STD_LOGIC;                       -- Transmit enable to Chilipepper
    CP_TX_RX_SW_EXT             :OUT STD_LOGIC;                       -- Chilipepper Transmit/Receive antenna switch
    CP_RX_EN_EXT                :OUT STD_LOGIC;                       -- Receive enable to Chilipepper
    CP_PA_EN_EXT                :OUT STD_LOGIC;                       -- Power amplifier enable to Chilipepper
    CP_INIT_DONE_EXT            :IN  STD_LOGIC;                       -- Chilipepper microcontroller config complete
    CP_MCU_RESET_L_EXT          :OUT STD_LOGIC;
    CP_TX_DAC_CLK_EXT           :OUT STD_LOGIC;
    CP_TXD_EXT                  :OUT STD_LOGIC_VECTOR(11 DOWNTO 0);   -- SFIX12_EN11
    CP_TX_IQ_SEL_EXT            :OUT STD_LOGIC                        -- UFIX1
    );
END RF_TX_TOP;

ARCHITECTURE RF_TX_TOP_ARCH OF RF_TX_TOP IS

  COMPONENT CLK_RST_CTRL
    PORT (
      CLK_40MHz_FROM_CP           :IN  STD_LOGIC;  -- 40 Mhz clock provided by Chilipepper
      RESET_FROM_XILLYBUS         :IN  STD_LOGIC;
      CLK_40MHZ_0_DEG             :OUT STD_LOGIC;
      CLK_40MHZ_180_DEG           :OUT STD_LOGIC;
      CLK_20MHZ_0_DEG             :OUT STD_LOGIC;
      CLK_GEN_PLL_LOCKED          :OUT STD_LOGIC;
      CP_MCU_RESET_L              :OUT STD_LOGIC;
      CP_INIT_DONE_EXT            :IN  STD_LOGIC;  -- Chilipepper microcontroller config complete
      TX_SYSTEM_RESET             :OUT STD_LOGIC;
      NOT_CLK_GEN_PLL_LOCKED      :OUT STD_LOGIC
      );
  END COMPONENT;

  COMPONENT FIFO_8X2048_ASYNC_TK
    PORT (
      RST                         :IN  STD_LOGIC;
      WR_CLK                      :IN  STD_LOGIC;
      RD_CLK                      :IN  STD_LOGIC;
      DIN                         :IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
      WR_EN                       :IN  STD_LOGIC;
      RD_EN                       :IN  STD_LOGIC;
      DOUT                        :OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      FULL                        :OUT STD_LOGIC;
      EMPTY                       :OUT STD_LOGIC
    );
  END COMPONENT;
 
  COMPONENT TX_SYSTEM_TOP IS
    PORT( 
          CLK                     :IN  STD_LOGIC;
          RESET                   :IN  STD_LOGIC;
          CLK_ENABLE              :IN  STD_LOGIC;
          MESSAGE_DATA_BYTE       :IN  STD_LOGIC_VECTOR(7 DOWNTO 0);  -- UINT8
          FIFO_EMPTY              :IN  STD_LOGIC;
          CE_OUT                  :OUT STD_LOGIC;
          TXD                     :OUT STD_LOGIC_VECTOR(11 DOWNTO 0);  -- SFIX12_EN11
          TX_IQ_SEL               :OUT STD_LOGIC;  -- UFIX1
          FIFO_RD_EN              :OUT STD_LOGIC
          );
  END COMPONENT;
  
  -- FIFO signals
  SIGNAL  FIFO_RD_EN              :STD_LOGIC;
  SIGNAL  FIFO_DOUT               :STD_LOGIC_VECTOR(7 DOWNTO 0);
  SIGNAL  FIFO_EMPTY              :STD_LOGIC;
  
  -- Clock signals
  SIGNAL CLK_40MHz_0_DEG          :STD_LOGIC;
  SIGNAL CLK_40MHz_180_DEG        :STD_LOGIC;
  SIGNAL CLK_20MHz_0_DEG          :STD_LOGIC;
  
  -- Other signals
  SIGNAL CLK_GEN_PLL_LOCKED       :STD_LOGIC;
  SIGNAL NOT_CLK_GEN_PLL_LOCKED   :STD_LOGIC;
  
  
BEGIN
    
  -- Signal Assignments
  CP_TX_EN_EXT <= '1';
  CP_TX_RX_SW_EXT <= '1';   -- VERIFY!!!!
  CP_RX_EN_EXT <= '1';      -- VERIFY!!!!
  CP_PA_EN_EXT <= '1';
  
  -- Component Instantiations  
  CP_TX_DAC_CLK_ODDR_INST : ODDR
    generic map(
      DDR_CLK_EDGE => "OPPOSITE_EDGE",  -- "OPPOSITE_EDGE" or "SAME_EDGE"
      INIT => '0',                      -- Initial value for Q port ('1' or '0')
      SRTYPE => "ASYNC")                -- Reset Type ("ASYNC" or "SYNC")
    port map (
      Q  => CP_TX_DAC_CLK_EXT,      -- 1-bit DDR output
      C  => CLK_40MHZ_180_DEG,      -- 1-bit clock input
      CE => '1',                    -- 1-bit clock enable input
      D1 => '1',                    -- 1-bit data input (positive edge)
      D2 => '0',                    -- 1-bit data input (negative edge)
      R  => NOT_CLK_GEN_PLL_LOCKED, -- 1-bit reset input
      S  => '0'                     -- 1-bit set input
    );
    
  CLK_RST_CTRL_INST : CLK_RST_CTRL
    PORT MAP (
      CLK_40MHz_FROM_CP           =>  CLK_40MHz_FROM_CP_EXT,
      RESET_FROM_XILLYBUS         =>  RESET_FROM_XILLYBUS,
      CLK_40MHZ_0_DEG             =>  CLK_40MHZ_0_DEG,
      CLK_40MHZ_180_DEG           =>  CLK_40MHZ_180_DEG,
      CLK_20MHZ_0_DEG             =>  CLK_20MHZ_0_DEG,
      CLK_GEN_PLL_LOCKED          =>  CLK_GEN_PLL_LOCKED,
      CP_MCU_RESET_L              =>  CP_MCU_RESET_L_EXT,
      CP_INIT_DONE_EXT            =>  CP_INIT_DONE_EXT,
      TX_SYSTEM_RESET             =>  TX_SYSTEM_RESET,
      NOT_CLK_GEN_PLL_LOCKED      =>  NOT_CLK_GEN_PLL_LOCKED
      );
      
  FIFO_8X2048_ASYNC_TK_INST : FIFO_8X2048_ASYNC_TK
    PORT MAP (
      RST     => RESET_FROM_XILLYBUS,
      WR_CLK  => WR_CLK,
      RD_CLK  => CLK_40MHZ_0_DEG,
      DIN     => USER_W_WRITE_8_DATA,
      WR_EN   => USER_W_WRITE_8_WREN,
      RD_EN   => FIFO_RD_EN,          -- CHANGE TO TX_CORE
      DOUT    => FIFO_DOUT,           -- CHANGE TO TX_CORE
      FULL    => USER_W_WRITE_8_FULL,
      EMPTY   => FIFO_EMPTY           -- CHANGE TO TX_CORE
      );
    
  TX_SYSTEM_TOP_INST : TX_SYSTEM_TOP
  PORT MAP( 
        CLK                 => CLK_40MHZ_0_DEG,
        RESET               => TX_SYSTEM_RESET,
        CLK_ENABLE          => '1',                     -- PROBLEM???????
        MESSAGE_DATA_BYTE   => FIFO_DOUT,
        FIFO_EMPTY          => FIFO_EMPTY,
        CE_OUT              => OPEN,
        TXD                 => CP_TXD_EXT,
        TX_IQ_SEL           => CP_TX_IQ_SEL_EXT,
        FIFO_RD_EN          => FIFO_RD_EN
        );
 
  
END RF_TX_TOP_ARCH;



