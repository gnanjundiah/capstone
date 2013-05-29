README file for a custom Xillybus IP core bundle
================================================

Core ID: 1181 ("QPSK_Transmit_v10" by carlstone4@gmail.com)
Target: Xilinx Zynq-7000

This is a kit for modifying the demo bundle into the custom configuration
(which is detailed below). Please follow the three steps below.

(1) Replace the existing xillybus.v and xillybus_core.v files with the ones
    in this bundle.

(2) Replace the xillybus_core.ngc file in the demo bundle's core/ subdirectory
    with the one in this bundle.

(3) Edit xillydemo.v (or xillydemo.vhd) to reflect the desired application
    of this custom IP core. The template.v (or template.vhd) file in the
    "instantiation templates" directory of this bundle contains the signal
    outline and instantion format. Note that unlike its xillydemo.*
    counterpart, there is no application logic (e.g. loopback FIFOs) in
    the instantiation templates. It's however recommended to follow the
    spirit of the xillydemo.* examples when attaching the application logic
    to the core.

To modify a design other than the demo bundle, equivalent actions should be
taken on the design's hierarchy. It's recommended to first delete the
xillybus_core.ngc file, and attempt to build the project, just to verify
that the build fails as the file is missing. Only then add the new
replacement.

The device files and their attributes are listed below.

NOTE: The DMA buffers mentioned are allocated on the host's RAM, not from
      resources on the FPGA.

------- /dev/xillybus_read_32

  Upstream (FPGA to host):
    Data width: 32 bits
    DMA buffers: 32 x 128 kB = 4 MB
    Flow control: Asynchronous, select() and non-blocking read() supported
    Seekable: No

------- /dev/xillybus_write_32

  Downstream (host to FPGA):
    Data width: 32 bits
    DMA buffers: 32 x 128 kB = 4 MB
    Flow control: Asynchronous
    Seekable: No
    FPGA RAM for DMA acceleration: None

------- /dev/xillybus_read_8

  Upstream (FPGA to host):
    Data width: 8 bits
    DMA buffers: 8 x 32 kB = 256 kB
    Flow control: Asynchronous, select() and non-blocking read() supported
    Seekable: No

------- /dev/xillybus_write_8

  Downstream (host to FPGA):
    Data width: 8 bits
    DMA buffers: 8 x 16 kB = 128 kB
    Flow control: Asynchronous
    Seekable: No
    FPGA RAM for DMA acceleration: None

------- /dev/xillybus_mem_8

  Upstream (FPGA to host):
    Data width: 8 bits
    DMA buffers: 4 x 4 kB = 16 kB
    Flow control: Synchronous
    Seekable: Yes, with 5 address bits

  Downstream (host to FPGA):
    Data width: 8 bits
    DMA buffers: 4 x 4 kB = 16 kB
    Flow control: Synchronous
    Seekable: Yes, with 5 address bits
    FPGA RAM for DMA acceleration: None

------- /dev/xillybus_audio

  Upstream (FPGA to host):
    Data width: 32 bits
    DMA buffers: 4 x 8 kB = 32 kB
    Flow control: Asynchronous, select() and non-blocking read() supported
    Seekable: No

  Downstream (host to FPGA):
    Data width: 32 bits
    DMA buffers: 4 x 8 kB = 32 kB
    Flow control: Asynchronous
    Seekable: No
    FPGA RAM for DMA acceleration: None

------- /dev/xillybus_smb

  Upstream (FPGA to host):
    Data width: 8 bits
    DMA buffers: 4 x 4 kB = 16 kB
    Flow control: Synchronous
    Seekable: No

  Downstream (host to FPGA):
    Data width: 8 bits
    DMA buffers: 4 x 4 kB = 16 kB
    Flow control: Synchronous
    Seekable: No
    FPGA RAM for DMA acceleration: None

