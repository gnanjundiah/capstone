library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity tb_xillydemo is
end tb_xillydemo;

architecture tb_xillydemo_arch of tb_xillydemo is
  
--   component fifo_8x2048
--    port (
--      clk: IN std_logic;
--      srst: IN std_logic;
--      din: IN std_logic_VECTOR(7 downto 0);
--      wr_en: IN std_logic;
--      rd_en: IN std_logic;
--      dout: OUT std_logic_VECTOR(7 downto 0);
--      full: OUT std_logic;
--      empty: OUT std_logic);
--  end component;

  COMPONENT fifo_8x2048_async_tk
    PORT (
      rst : IN STD_LOGIC;
      wr_clk : IN STD_LOGIC;
      rd_clk : IN STD_LOGIC;
      din : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
      wr_en : IN STD_LOGIC;
      rd_en : IN STD_LOGIC;
      dout : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
      full : OUT STD_LOGIC;
      empty : OUT STD_LOGIC
    );
  END COMPONENT;
 
  component TX_CORE_TOP IS
  PORT(
        clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        clk_enable                        :   IN    std_logic;
        FIFO_DOUT                         :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        FIFO_EMPTY                        :   IN    std_logic;
        ce_out                            :   OUT   std_logic;
        FIFO_RD_EN                        :   OUT   std_logic
        );
  END component;

  signal  tb_bus_clk_counter  :  std_logic_vector(31 downto 0);

  signal  tb_PS_CLK   :  std_logic:='0';
  signal  tb_PS_PORB  :  std_logic:='1';
  signal  tb_PS_SRSTB :  std_logic:='1';
  signal  tb_clk_100  :  std_logic:='0';
  signal  tb_bus_clk  :  std_logic:='0';
  
  signal  tb_user_w_write_8_data  :  std_logic_vector(7 downto 0);
  signal  tb_user_w_write_8_wren  :  std_logic:='0';
  signal  tb_user_r_read_8_rden   :  std_logic;
  signal  tb_user_r_read_8_data   :  std_logic_vector(7 downto 0);
  signal  tb_user_w_write_8_full  :  std_logic;
  signal  tb_user_r_read_8_empty  :  std_logic;
  
  
begin
  
  tb_PS_CLK  <= not tb_PS_CLK  after 5 ns;
  tb_clk_100 <= not tb_clk_100 after 5 ns;
  tb_bus_clk <= not tb_bus_clk after 5 ns;
  
  tb_PS_PORB  <= '0' after 50 ns;
  tb_PS_SRSTB <= '0' after 75 ns;
  
  
  tb_bus_clk_counter_proc : PROCESS (tb_bus_clk, tb_PS_SRSTB)
  BEGIN
    IF tb_PS_SRSTB = '1' THEN
      tb_bus_clk_counter <= (OTHERS => '0');
    ELSIF tb_bus_clk'EVENT AND tb_bus_clk = '1' THEN
      tb_bus_clk_counter <= tb_bus_clk_counter + '1';
    END IF;
  END PROCESS tb_bus_clk_counter_proc;
  
  
  xilly_data_model_proc : PROCESS (tb_bus_clk, tb_PS_SRSTB)
  BEGIN
    IF tb_PS_SRSTB = '1' THEN
      tb_user_w_write_8_data <= (OTHERS => '0');
    ELSIF tb_bus_clk'EVENT AND tb_bus_clk = '1' THEN
      IF tb_bus_clk_counter = "00000000000000000000000111110011" THEN
        tb_user_w_write_8_data <= tb_user_w_write_8_data + '1';
      END IF;
    END IF;
  END PROCESS xilly_data_model_proc;
  
    
  xilly_wren_model_proc : PROCESS (tb_bus_clk, tb_PS_SRSTB)
  BEGIN
    IF tb_PS_SRSTB = '1' THEN
      tb_user_w_write_8_wren <= '0';
    ELSIF tb_bus_clk'EVENT AND tb_bus_clk = '1' THEN
      IF tb_bus_clk_counter = "00000000000000000000000111110011" THEN
        tb_user_w_write_8_wren <= '1';
      ELSE
        tb_user_w_write_8_wren <= '0';
      END IF;
    END IF;
  END PROCESS xilly_wren_model_proc;
  
  
--   FIFO_8x2048_INST : fifo_8x2048
--    port map(
--      clk        => tb_bus_clk,
----      srst       => tb_reset_8,
--      srst       => tb_PS_SRSTB,
--      din        => tb_user_w_write_8_data,
--      wr_en      => tb_user_w_write_8_wren,
--      rd_en      => tb_user_r_read_8_rden,
--      dout       => tb_user_r_read_8_data,
--      full       => tb_user_w_write_8_full,
--      empty      => tb_user_r_read_8_empty
--      );

    --tb_reset_8 <= not (user_w_write_8_open or user_r_read_8_open);

  fifo_8x2048_async_tk_inst : fifo_8x2048_async_tk
    PORT MAP (
      rst     => tb_PS_SRSTB,
      wr_clk  => tb_bus_clk,
      rd_clk  => tb_bus_clk,             -- CHANGE TO CHILIPEPPER CLOCK
      din     => tb_user_w_write_8_data,
      wr_en   => tb_user_w_write_8_wren,
      rd_en   => tb_user_r_read_8_rden,  -- CHANGE TO TX_CORE
      dout    => tb_user_r_read_8_data,  -- CHANGE TO TX_CORE
      full    => tb_user_w_write_8_full,
      empty   => tb_user_r_read_8_empty  -- CHANGE TO TX_CORE
    );
    
  TX_CORE_TOP_INST : TX_CORE_TOP
    PORT MAP(
        clk           => tb_bus_clk,
        reset         => tb_PS_SRSTB,
        clk_enable    => '1',
        FIFO_DOUT     => tb_user_r_read_8_data,
        FIFO_EMPTY    => tb_user_r_read_8_empty,
        ce_out        => open,
        FIFO_RD_EN    => tb_user_r_read_8_rden
        );
  
  
end tb_xillydemo_arch;


