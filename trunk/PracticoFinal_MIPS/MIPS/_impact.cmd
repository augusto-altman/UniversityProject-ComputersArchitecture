setMode -bs
setMode -bs
setMode -bs
setCable -port auto
Identify -inferir 
identifyMPM 
assignFile -p 1 -file "D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/uarthandler.bit"
Program -p 1 
setMode -bs
setMode -bs
deleteDevice -position 1
setMode -bs
setMode -ss
setMode -sm
setMode -hw140
setMode -spi
setMode -acecf
setMode -acempm
setMode -pff
