  // Clock and quiesce
  wire  bus_clk;
  wire  quiesce;


  // Wires related to /dev/xillybus_audio
  wire  user_r_audio_rden;
  wire  user_r_audio_empty;
  wire [31:0] user_r_audio_data;
  wire  user_r_audio_eof;
  wire  user_r_audio_open;
  wire  user_w_audio_wren;
  wire  user_w_audio_full;
  wire [31:0] user_w_audio_data;
  wire  user_w_audio_open;

  // Wires related to /dev/xillybus_mem_8
  wire  user_r_mem_8_rden;
  wire  user_r_mem_8_empty;
  wire [7:0] user_r_mem_8_data;
  wire  user_r_mem_8_eof;
  wire  user_r_mem_8_open;
  wire  user_w_mem_8_wren;
  wire  user_w_mem_8_full;
  wire [7:0] user_w_mem_8_data;
  wire  user_w_mem_8_open;
  wire [4:0] user_mem_8_addr;
  wire  user_mem_8_addr_update;

  // Wires related to /dev/xillybus_read_32
  wire  user_r_read_32_rden;
  wire  user_r_read_32_empty;
  wire [31:0] user_r_read_32_data;
  wire  user_r_read_32_eof;
  wire  user_r_read_32_open;

  // Wires related to /dev/xillybus_read_8
  wire  user_r_read_8_rden;
  wire  user_r_read_8_empty;
  wire [7:0] user_r_read_8_data;
  wire  user_r_read_8_eof;
  wire  user_r_read_8_open;

  // Wires related to /dev/xillybus_smb
  wire  user_r_smb_rden;
  wire  user_r_smb_empty;
  wire [7:0] user_r_smb_data;
  wire  user_r_smb_eof;
  wire  user_r_smb_open;
  wire  user_w_smb_wren;
  wire  user_w_smb_full;
  wire [7:0] user_w_smb_data;
  wire  user_w_smb_open;

  // Wires related to /dev/xillybus_write_32
  wire  user_w_write_32_wren;
  wire  user_w_write_32_full;
  wire [31:0] user_w_write_32_data;
  wire  user_w_write_32_open;

  // Wires related to /dev/xillybus_write_8
  wire  user_w_write_8_wren;
  wire  user_w_write_8_full;
  wire [7:0] user_w_write_8_data;
  wire  user_w_write_8_open;


  xillybus xillybus_ins (

    // Ports related to /dev/xillybus_audio
    // FPGA to CPU signals:
    .user_r_audio_rden(user_r_audio_rden),
    .user_r_audio_empty(user_r_audio_empty),
    .user_r_audio_data(user_r_audio_data),
    .user_r_audio_eof(user_r_audio_eof),
    .user_r_audio_open(user_r_audio_open),

    // CPU to FPGA signals:
    .user_w_audio_wren(user_w_audio_wren),
    .user_w_audio_full(user_w_audio_full),
    .user_w_audio_data(user_w_audio_data),
    .user_w_audio_open(user_w_audio_open),


    // Ports related to /dev/xillybus_mem_8
    // FPGA to CPU signals:
    .user_r_mem_8_rden(user_r_mem_8_rden),
    .user_r_mem_8_empty(user_r_mem_8_empty),
    .user_r_mem_8_data(user_r_mem_8_data),
    .user_r_mem_8_eof(user_r_mem_8_eof),
    .user_r_mem_8_open(user_r_mem_8_open),

    // CPU to FPGA signals:
    .user_w_mem_8_wren(user_w_mem_8_wren),
    .user_w_mem_8_full(user_w_mem_8_full),
    .user_w_mem_8_data(user_w_mem_8_data),
    .user_w_mem_8_open(user_w_mem_8_open),

    // Address signals:
    .user_mem_8_addr(user_mem_8_addr),
    .user_mem_8_addr_update(user_mem_8_addr_update),


    // Ports related to /dev/xillybus_read_32
    // FPGA to CPU signals:
    .user_r_read_32_rden(user_r_read_32_rden),
    .user_r_read_32_empty(user_r_read_32_empty),
    .user_r_read_32_data(user_r_read_32_data),
    .user_r_read_32_eof(user_r_read_32_eof),
    .user_r_read_32_open(user_r_read_32_open),


    // Ports related to /dev/xillybus_read_8
    // FPGA to CPU signals:
    .user_r_read_8_rden(user_r_read_8_rden),
    .user_r_read_8_empty(user_r_read_8_empty),
    .user_r_read_8_data(user_r_read_8_data),
    .user_r_read_8_eof(user_r_read_8_eof),
    .user_r_read_8_open(user_r_read_8_open),


    // Ports related to /dev/xillybus_smb
    // FPGA to CPU signals:
    .user_r_smb_rden(user_r_smb_rden),
    .user_r_smb_empty(user_r_smb_empty),
    .user_r_smb_data(user_r_smb_data),
    .user_r_smb_eof(user_r_smb_eof),
    .user_r_smb_open(user_r_smb_open),

    // CPU to FPGA signals:
    .user_w_smb_wren(user_w_smb_wren),
    .user_w_smb_full(user_w_smb_full),
    .user_w_smb_data(user_w_smb_data),
    .user_w_smb_open(user_w_smb_open),


    // Ports related to /dev/xillybus_write_32
    // CPU to FPGA signals:
    .user_w_write_32_wren(user_w_write_32_wren),
    .user_w_write_32_full(user_w_write_32_full),
    .user_w_write_32_data(user_w_write_32_data),
    .user_w_write_32_open(user_w_write_32_open),


    // Ports related to /dev/xillybus_write_8
    // CPU to FPGA signals:
    .user_w_write_8_wren(user_w_write_8_wren),
    .user_w_write_8_full(user_w_write_8_full),
    .user_w_write_8_data(user_w_write_8_data),
    .user_w_write_8_open(user_w_write_8_open),


    // General signals
    .PS_CLK(PS_CLK),
    .PS_PORB(PS_PORB),
    .PS_SRSTB(PS_SRSTB),
    .clk_100(clk_100),
    .otg_oc(otg_oc),
    .DDR_Addr(DDR_Addr),
    .DDR_BankAddr(DDR_BankAddr),
    .DDR_CAS_n(DDR_CAS_n),
    .DDR_CKE(DDR_CKE),
    .DDR_CS_n(DDR_CS_n),
    .DDR_Clk(DDR_Clk),
    .DDR_Clk_n(DDR_Clk_n),
    .DDR_DM(DDR_DM),
    .DDR_DQ(DDR_DQ),
    .DDR_DQS(DDR_DQS),
    .DDR_DQS_n(DDR_DQS_n),
    .DDR_DRSTB(DDR_DRSTB),
    .DDR_ODT(DDR_ODT),
    .DDR_RAS_n(DDR_RAS_n),
    .DDR_VRN(DDR_VRN),
    .DDR_VRP(DDR_VRP),
    .MIO(MIO),
    .PS_GPIO(PS_GPIO),
    .DDR_WEB(DDR_WEB),
    .GPIO_LED(GPIO_LED),
    .bus_clk(bus_clk),
    .quiesce(quiesce),
    .vga4_blue(vga4_blue),
    .vga4_green(vga4_green),
    .vga4_red(vga4_red),
    .vga_hsync(vga_hsync),
    .vga_vsync(vga_vsync)
  );
