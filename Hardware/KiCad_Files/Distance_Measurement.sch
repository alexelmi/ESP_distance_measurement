EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "WemosD1 mini Distance Measurement"
Date "2021-11-11"
Rev "Rev. 02"
Comp "Emilia & Papa"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:WeMos_D1_mini U1
U 1 1 616C4280
P 5750 3400
F 0 "U1" V 5600 3100 50  0000 C CNN
F 1 "WeMos_D1_mini" V 5525 3050 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 5750 2250 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 3900 2250 50  0001 C CNN
	1    5750 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 616C95CA
P 7100 3100
F 0 "D1" V 7047 3180 50  0000 L CNN
F 1 "LED" V 7138 3180 50  0000 L CNN
F 2 "LED_THT:LED_D3.0mm" H 7100 3100 50  0001 C CNN
F 3 "~" H 7100 3100 50  0001 C CNN
	1    7100 3100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 616CA45D
P 4325 3800
F 0 "R2" V 4225 3750 50  0000 L CNN
F 1 "1k" V 4425 3750 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4255 3800 50  0001 C CNN
F 3 "~" H 4325 3800 50  0001 C CNN
	1    4325 3800
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 616CA772
P 6800 3100
F 0 "R1" V 6700 3050 50  0000 L CNN
F 1 "220" V 6900 3025 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6730 3100 50  0001 C CNN
F 3 "~" H 6800 3100 50  0001 C CNN
	1    6800 3100
	0    1    1    0   
$EndComp
$Comp
L Device:Speaker_Crystal LS1
U 1 1 616CE39B
P 4300 2175
F 0 "LS1" H 4500 2075 50  0000 L CNN
F 1 "Speaker_Crystal" H 4475 2200 50  0000 L CNN
F 2 "digikey-footprints:Piezo_Transducer_THT_PS1240P02BT" H 4265 2125 50  0001 C CNN
F 3 "~" H 4265 2125 50  0001 C CNN
	1    4300 2175
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 616C480C
P 6500 1975
F 0 "J2" H 6580 1967 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6580 1876 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 6500 1975 50  0001 C CNN
F 3 "~" H 6500 1975 50  0001 C CNN
	1    6500 1975
	1    0    0    -1  
$EndComp
Text GLabel 6300 1975 0    50   Input ~ 0
+5V
Text GLabel 6300 2075 0    50   Input ~ 0
GND
$Comp
L power:PWR_FLAG #FLG01
U 1 1 616CBB59
P 6300 1975
F 0 "#FLG01" H 6300 2050 50  0001 C CNN
F 1 "PWR_FLAG" H 6300 2148 50  0000 C CNN
F 2 "" H 6300 1975 50  0001 C CNN
F 3 "~" H 6300 1975 50  0001 C CNN
	1    6300 1975
	1    0    0    -1  
$EndComp
Text GLabel 5650 2600 1    50   Input ~ 0
+5V
NoConn ~ 5350 3000
NoConn ~ 5350 3300
NoConn ~ 5350 3400
NoConn ~ 6150 3800
NoConn ~ 6150 2900
NoConn ~ 6150 3000
NoConn ~ 6150 3200
NoConn ~ 6150 3400
NoConn ~ 6150 3500
Text GLabel 5750 4200 2    50   Input ~ 0
GND
Text Notes 4625 3700 0    50   ~ 0
VCC
Text Notes 4625 3800 0    50   ~ 0
Trig
Text Notes 4625 3900 0    50   ~ 0
Echo
Text Notes 4625 4000 0    50   ~ 0
GND
Text GLabel 5025 3675 2    50   Input ~ 0
+5V
Text GLabel 5025 3975 2    50   Input ~ 0
GND
Wire Wire Line
	6375 3600 6375 4625
Wire Wire Line
	6375 4625 5250 4625
Wire Wire Line
	5250 4625 5250 3875
Wire Wire Line
	5250 3875 5025 3875
Wire Wire Line
	5025 3775 5350 3775
Wire Wire Line
	5350 3775 5350 4525
Wire Wire Line
	6275 4525 6275 3700
Wire Wire Line
	6275 3700 6150 3700
Wire Wire Line
	5350 4525 6275 4525
Wire Wire Line
	6150 3600 6375 3600
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 616C96B1
P 4825 3875
F 0 "J1" H 4717 3450 50  0000 C CNN
F 1 "Conn_01x04_Female" H 4717 3541 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 4825 3875 50  0001 C CNN
F 3 "~" H 4825 3875 50  0001 C CNN
	1    4825 3875
	-1   0    0    1   
$EndComp
Wire Wire Line
	6475 4725 6475 3300
Wire Wire Line
	6475 3300 6150 3300
Wire Wire Line
	4325 3650 4325 3450
Wire Wire Line
	4325 3950 4325 4725
Wire Wire Line
	4325 4725 6475 4725
$Comp
L power:GNDPWR #PWR0101
U 1 1 616FD5B6
P 6300 2225
F 0 "#PWR0101" H 6300 2025 50  0001 C CNN
F 1 "GNDPWR" H 6304 2071 50  0000 C CNN
F 2 "" H 6300 2175 50  0001 C CNN
F 3 "" H 6300 2175 50  0001 C CNN
	1    6300 2225
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2225 6300 2200
$Comp
L power:GND #PWR0102
U 1 1 616FF170
P 6300 2200
F 0 "#PWR0102" H 6300 1950 50  0001 C CNN
F 1 "GND" V 6305 2072 50  0000 R CNN
F 2 "" H 6300 2200 50  0001 C CNN
F 3 "" H 6300 2200 50  0001 C CNN
	1    6300 2200
	0    -1   -1   0   
$EndComp
Connection ~ 6300 2200
Wire Wire Line
	6300 2200 6300 2075
$Comp
L power:GND #PWR0103
U 1 1 616FFAE5
P 5750 4200
F 0 "#PWR0103" H 5750 3950 50  0001 C CNN
F 1 "GND" V 5755 4072 50  0000 R CNN
F 2 "" H 5750 4200 50  0001 C CNN
F 3 "" H 5750 4200 50  0001 C CNN
	1    5750 4200
	0    1    1    0   
$EndComp
$Comp
L power:GNDPWR #PWR0104
U 1 1 617003F6
P 5750 4200
F 0 "#PWR0104" H 5750 4000 50  0001 C CNN
F 1 "GNDPWR" H 5754 4046 50  0000 C CNN
F 2 "" H 5750 4150 50  0001 C CNN
F 3 "" H 5750 4150 50  0001 C CNN
	1    5750 4200
	1    0    0    -1  
$EndComp
Connection ~ 5750 4200
Text GLabel 7250 3100 2    50   Input ~ 0
GND
Wire Wire Line
	5850 2600 6575 2600
Wire Wire Line
	6575 2600 6575 4825
Wire Wire Line
	6575 4825 4100 4825
Wire Wire Line
	4100 4825 4100 3100
Wire Wire Line
	4500 2175 4700 2175
Text GLabel 4500 2075 2    50   Input ~ 0
GND
$Comp
L dk_Transistors-Bipolar-BJT-RF:2N5109 Q1
U 1 1 616E3576
P 4325 3100
F 0 "Q1" H 4413 3153 60  0000 L CNN
F 1 "2N5109" H 4413 3047 60  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 4525 3300 60  0001 L CNN
F 3 "https://my.centralsemi.com/get_document.php?cmp=1&mergetype=pd&mergepath=pd&pdf_id=2N5109.PDF" H 4525 3400 60  0001 L CNN
F 4 "2N5109CS-ND" H 4525 3500 60  0001 L CNN "Digi-Key_PN"
F 5 "2N5109" H 4525 3600 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4525 3700 60  0001 L CNN "Category"
F 7 "Transistors - Bipolar (BJT) - RF" H 4525 3800 60  0001 L CNN "Family"
F 8 "https://my.centralsemi.com/get_document.php?cmp=1&mergetype=pd&mergepath=pd&pdf_id=2N5109.PDF" H 4525 3900 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/central-semiconductor-corp/2N5109/2N5109CS-ND/4806909" H 4525 4000 60  0001 L CNN "DK_Detail_Page"
F 10 "RF TRANS NPN 20V 1.2GHZ TO39" H 4525 4100 60  0001 L CNN "Description"
F 11 "Central Semiconductor Corp" H 4525 4200 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4525 4300 60  0001 L CNN "Status"
	1    4325 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4700 2175 4700 3100
Wire Wire Line
	4125 3100 4100 3100
Wire Wire Line
	4525 3100 4700 3100
Wire Wire Line
	6650 3100 6150 3100
$EndSCHEMATC
