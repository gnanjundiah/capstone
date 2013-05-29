onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider TB
add wave -noupdate /uarttest/Reset
add wave -noupdate /uarttest/Clk
add wave -noupdate /uarttest/DataIn
add wave -noupdate /uarttest/DataOut
add wave -noupdate /uarttest/RxD
add wave -noupdate /uarttest/TxD
add wave -noupdate /uarttest/CS_N
add wave -noupdate /uarttest/RD_N
add wave -noupdate /uarttest/WR_N
add wave -noupdate /uarttest/IntRx_N
add wave -noupdate /uarttest/IntTx_N
add wave -noupdate /uarttest/Addr
add wave -noupdate -divider miniuart
add wave -noupdate /uarttest/miniUARTDev/SysClk
add wave -noupdate /uarttest/miniUARTDev/Reset
add wave -noupdate /uarttest/miniUARTDev/CS_N
add wave -noupdate /uarttest/miniUARTDev/RD_N
add wave -noupdate /uarttest/miniUARTDev/WR_N
add wave -noupdate /uarttest/miniUARTDev/RxD
add wave -noupdate /uarttest/miniUARTDev/TxD
add wave -noupdate /uarttest/miniUARTDev/IntRx_N
add wave -noupdate /uarttest/miniUARTDev/IntTx_N
add wave -noupdate /uarttest/miniUARTDev/Addr
add wave -noupdate /uarttest/miniUARTDev/DataIn
add wave -noupdate /uarttest/miniUARTDev/DataOut
add wave -noupdate /uarttest/miniUARTDev/RxData
add wave -noupdate /uarttest/miniUARTDev/TxData
add wave -noupdate /uarttest/miniUARTDev/CSReg
add wave -noupdate /uarttest/miniUARTDev/EnabRx
add wave -noupdate /uarttest/miniUARTDev/EnabTx
add wave -noupdate /uarttest/miniUARTDev/DRdy
add wave -noupdate /uarttest/miniUARTDev/TRegE
add wave -noupdate /uarttest/miniUARTDev/TBufE
add wave -noupdate /uarttest/miniUARTDev/FErr
add wave -noupdate /uarttest/miniUARTDev/OErr
add wave -noupdate /uarttest/miniUARTDev/Read
add wave -noupdate /uarttest/miniUARTDev/Load
add wave -noupdate -divider UART_CLK
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/SysClk
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/EnableRx
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/EnableTx
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/Reset
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/ClkDiv26
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/tmpEnRX
add wave -noupdate /uarttest/miniUARTDev/ClkDiv/tmpEnTX
add wave -noupdate -divider UART_RX
add wave -noupdate /uarttest/miniUARTDev/RxDev/Clk
add wave -noupdate /uarttest/miniUARTDev/RxDev/Reset
add wave -noupdate /uarttest/miniUARTDev/RxDev/Enable
add wave -noupdate /uarttest/miniUARTDev/RxDev/RxD
add wave -noupdate /uarttest/miniUARTDev/RxDev/RD
add wave -noupdate /uarttest/miniUARTDev/RxDev/FErr
add wave -noupdate /uarttest/miniUARTDev/RxDev/OErr
add wave -noupdate /uarttest/miniUARTDev/RxDev/DRdy
add wave -noupdate /uarttest/miniUARTDev/RxDev/DataIn
add wave -noupdate /uarttest/miniUARTDev/RxDev/Start
add wave -noupdate /uarttest/miniUARTDev/RxDev/tmpRxD
add wave -noupdate /uarttest/miniUARTDev/RxDev/tmpDRdy
add wave -noupdate /uarttest/miniUARTDev/RxDev/outErr
add wave -noupdate /uarttest/miniUARTDev/RxDev/frameErr
add wave -noupdate /uarttest/miniUARTDev/RxDev/BitCnt
add wave -noupdate /uarttest/miniUARTDev/RxDev/SampleCnt
add wave -noupdate /uarttest/miniUARTDev/RxDev/ShtReg
add wave -noupdate /uarttest/miniUARTDev/RxDev/DOut
add wave -noupdate -divider UART_TX
add wave -noupdate /uarttest/miniUARTDev/TxDev/Clk
add wave -noupdate /uarttest/miniUARTDev/TxDev/Reset
add wave -noupdate /uarttest/miniUARTDev/TxDev/Enable
add wave -noupdate /uarttest/miniUARTDev/TxDev/Load
add wave -noupdate /uarttest/miniUARTDev/TxDev/TxD
add wave -noupdate /uarttest/miniUARTDev/TxDev/TRegE
add wave -noupdate /uarttest/miniUARTDev/TxDev/TBufE
add wave -noupdate /uarttest/miniUARTDev/TxDev/DataO
add wave -noupdate /uarttest/miniUARTDev/TxDev/TBuff
add wave -noupdate /uarttest/miniUARTDev/TxDev/TReg
add wave -noupdate /uarttest/miniUARTDev/TxDev/BitCnt
add wave -noupdate /uarttest/miniUARTDev/TxDev/tmpTRegE
add wave -noupdate /uarttest/miniUARTDev/TxDev/tmpTBufE
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1241874664 ps} 0} {{Cursor 2} {97874760 ps} 0}
quietly wave cursor active 2
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {1999840745 ps} {2000008382 ps}
