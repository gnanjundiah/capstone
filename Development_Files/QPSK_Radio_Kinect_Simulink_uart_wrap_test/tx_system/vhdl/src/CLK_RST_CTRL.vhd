LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

LIBRARY UNISIM;
USE UNISIM.VCOMPONENTS.ALL;

ENTITY CLK_RST_CTRL IS
  PORT (
    CLK_40MHz_FROM_CP           :IN  STD_LOGIC;  -- 40 Mhz clock provided by Chilipepper
    XB_RESET_8                  :IN  STD_LOGIC;
    XB_RESET_32                 :IN  STD_LOGIC;
    CLK_40MHZ_0_DEG             :OUT STD_LOGIC;
    CLK_40MHZ_180_DEG           :OUT STD_LOGIC;
    CLK_20MHZ_0_DEG             :OUT STD_LOGIC;
    CLK_GEN_PLL_LOCKED          :OUT STD_LOGIC;
    CP_MCU_RESET_L              :OUT STD_LOGIC;
    CP_INIT_DONE_EXT            :IN  STD_LOGIC;  -- Chilipepper microcontroller config complete
    TX_SYSTEM_RESET             :OUT STD_LOGIC;
    UART_SYSTEM_RESET           :OUT STD_LOGIC;
    NOT_CLK_GEN_PLL_LOCKED      :OUT STD_LOGIC
    );
END CLK_RST_CTRL;

ARCHITECTURE CLK_RST_CTRL_ARCH OF CLK_RST_CTRL IS

  COMPONENT CLK_GEN_CORE
  PORT
   (-- CLOCK IN PORTS
    CLK_40MHZ_IN      : IN     STD_LOGIC;
    CLKFB_IN          : IN     STD_LOGIC;
    -- CLOCK OUT PORTS
    CLK_40MHZ_0_DEG   : OUT    STD_LOGIC;
    CLK_40MHZ_180_DEG : OUT    STD_LOGIC;
    CLK_20MHZ_0_DEG   : OUT    STD_LOGIC;
    CLKFB_OUT         : OUT    STD_LOGIC;
    -- STATUS AND CONTROL SIGNALS
    RESET             : IN     STD_LOGIC;
    LOCKED            : OUT    STD_LOGIC
   );
  END COMPONENT;
  
  -- Clock signals
  SIGNAL CLK_40MHZ_IN             :STD_LOGIC;
  SIGNAL CLK_40MHZ_0_DEG_INT      :STD_LOGIC;
  SIGNAL CLK_40MHZ_0_DEG_UNBUF    :STD_LOGIC;
  SIGNAL CLK_40MHZ_180_DEG_UNBUF  :STD_LOGIC;
  SIGNAL CLK_20MHZ_0_DEG_UNBUF    :STD_LOGIC;
  SIGNAL CLKFB_IN                 :STD_LOGIC;
  SIGNAL CLKFB_OUT                :STD_LOGIC;
  
    -- Other signals
  SIGNAL CLK_GEN_PLL_LOCKED_INT   :STD_LOGIC;
  SIGNAL CLK_40MHZ_0_DEG_COUNTER  :STD_LOGIC_VECTOR(15 DOWNTO 0);
  SIGNAL CP_MCU_RESET_COMPLETE    :STD_LOGIC;
  
  
BEGIN
  -- Signal assignments
  CLK_40MHz_0_DEG <= CLK_40MHZ_0_DEG_INT;
  
  -- Clock Buffers
  CLK_40MHZ_FROM_CHILIPEPPER_BUFG_INST : BUFG
    PORT MAP(
      O =>  CLK_40MHZ_IN,                 --1-bit output: clock output
      I =>  CLK_40MHz_FROM_CP             --1-bit input: clock input
    );
    
  CLK_40MHZ_0_DEG_BUFG_INST : BUFG
    PORT MAP(
      O =>  CLK_40MHZ_0_DEG_INT,          --1-bit output: clock output
      I =>  CLK_40MHZ_0_DEG_UNBUF         --1-bit input: clock input
    );
  
  CLK_40MHZ_180_DEG_BUFG_INST : BUFG
    PORT MAP(
      O =>  CLK_40MHZ_180_DEG,            --1-bit output: clock output
      I =>  CLK_40MHZ_180_DEG_UNBUF       --1-bit input: clock input
    );
  
  CLK_20MHZ_0_DEG_BUFG_INST : BUFG
    PORT MAP(
      O =>  CLK_20MHZ_0_DEG,              --1-bit output: clock output
      I =>  CLK_20MHZ_0_DEG_UNBUF         --1-bit input: clock input
    );
  
  CLKFB_BUFG_INST : BUFG
    PORT MAP(
      O =>  CLKFB_IN,                     --1-bit output: clock output
      I =>  CLKFB_OUT                     --1-bit input: clock input
    );
  
  -- DCM/PLL      
  CLK_GEN_CORE_INST : CLK_GEN_CORE
    PORT MAP
     (-- clock in ports
      CLK_40MHZ_IN      => CLK_40MHZ_IN,
      CLKFB_IN          => CLKFB_IN,
      -- clock out ports
      CLK_40MHZ_0_DEG   => CLK_40MHZ_0_DEG_UNBUF,
      CLK_40MHZ_180_DEG => CLK_40MHZ_180_DEG_UNBUF,
      CLK_20MHZ_0_DEG   => CLK_20MHZ_0_DEG_UNBUF,
      CLKFB_OUT         => CLKFB_OUT,
      -- status and control signals
      RESET             => '0',   -- CHANGE??
      LOCKED            => CLK_GEN_PLL_LOCKED_INT
      );
  
  -- PLL based reset logic
  NOT_CLK_GEN_PLL_LOCKED  <=  NOT CLK_GEN_PLL_LOCKED_INT;
  CLK_GEN_PLL_LOCKED      <=  CLK_GEN_PLL_LOCKED_INT;
  
  -- Transmitter system reset logic
  TX_SYSTEM_RESET <= NOT CLK_GEN_PLL_LOCKED_INT OR NOT CP_INIT_DONE_EXT;
  
  -- UART system reset logic
  UART_SYSTEM_RESET <= NOT CLK_GEN_PLL_LOCKED_INT OR NOT CP_INIT_DONE_EXT OR XB_RESET_32;
  
  -- System clock counter for reset logic timing
  PROCESS(CLK_GEN_PLL_LOCKED_INT, CLK_40MHZ_0_DEG_INT)
  BEGIN
    IF CLK_GEN_PLL_LOCKED_INT = '0' THEN
      CLK_40MHZ_0_DEG_COUNTER <= (OTHERS => '0');
    ELSIF CLK_40MHZ_0_DEG_INT'EVENT AND CLK_40MHZ_0_DEG_INT = '1' THEN
      CLK_40MHZ_0_DEG_COUNTER <= CLK_40MHZ_0_DEG_COUNTER + '1';
    END IF;
  END PROCESS;
  
  -- Chilipepper MCU reset logic
  PROCESS(CLK_GEN_PLL_LOCKED_INT, CLK_40MHZ_0_DEG_INT)
  BEGIN
    IF CLK_GEN_PLL_LOCKED_INT = '0' THEN
      CP_MCU_RESET_L <= '1';
    ELSIF CLK_40MHZ_0_DEG_INT'EVENT AND CLK_40MHZ_0_DEG_INT = '1' THEN
      IF CP_MCU_RESET_COMPLETE = '0' AND CLK_40MHZ_0_DEG_COUNTER = "0000111110100000" THEN
        CP_MCU_RESET_L <= '0';
      ELSIF CLK_40MHZ_0_DEG_COUNTER = "0101110111000000" THEN
        CP_MCU_RESET_L <= '1';
      END IF;
    END IF;
  END PROCESS;
  
  -- Indicate Chilipepper MCU has been reset
  PROCESS(CLK_GEN_PLL_LOCKED_INT, CLK_40MHZ_0_DEG_INT)
  BEGIN
    IF CLK_GEN_PLL_LOCKED_INT = '0' THEN
      CP_MCU_RESET_COMPLETE <= '0';
    ELSIF CLK_40MHZ_0_DEG_INT'EVENT AND CLK_40MHZ_0_DEG_INT = '1' THEN
      IF CLK_40MHZ_0_DEG_COUNTER = "0101110111000000" THEN
        CP_MCU_RESET_COMPLETE <= '1';
      END IF;
    END IF;
  END PROCESS;


END CLK_RST_CTRL_ARCH;




