# Distance Measurement

A tiny handheld ultrasonic "distance radar" built on a WeMos D1 mini. The closer
you hold it to an object, the faster it blinks and beeps.

> This tiny project I made with my daughter. When she came to me asking for a
> little handheld which is peeping and blinking, I thought using an ultrasonic
> sensor could be fun.

So I sat down and designed the circuit and the PCB in KiCad:

| Schematic | PCB | 3D view |
|---|---|---|
| ![Schematic](Screenshots/STR_View.png) | ![PCB](Screenshots/PCB_View.png) | ![3D](Screenshots/3D_View.png) |

The next day we put the components together and loaded the first test sketch onto
the WeMos D1 mini. (I have to admit I didn't test it before. 🙂)

## Features

- Ultrasonic distance measurement (~2 cm … 5 m) with an HC-SR04.
- LED + buzzer feedback that speeds up as the object gets closer; **solid** when
  very close and **silent** when nothing is in range.
- Distance also printed over `Serial` at 115200 baud.

## Hardware at a glance

| Function | WeMos label | ESP8266 GPIO |
|----------|-------------|--------------|
| Ultrasonic Trigger | D7 | GPIO13 |
| Ultrasonic Echo | D6 | GPIO12 |
| LED | D1 | GPIO5 |
| Buzzer (via transistor) | D3 | GPIO0 |

Full BOM, schematic, PCB and Gerbers are in [`Hardware/`](Hardware/). Pin mapping
verified against the KiCad netlist.

## Software

The code was built up from small test sketches, then combined into the final
firmware:

- **Ultrasonic test sketch** — [`Software/Test_UltraSonic_Simple`](Software/Test_UltraSonic_Simple) — prints the measured distance.
- **LED blink test sketch** — [`Software/Test_LED_Simple`](Software/Test_LED_Simple).
- **Buzzer beep test sketch** — [`Software/Test_Buzzer_Simple`](Software/Test_Buzzer_Simple).
- **Final firmware** — [`Software/Final_Software`](Software/Final_Software) — sensor + LED + buzzer combined.

### Quick start

1. Install the Arduino IDE and add ESP8266 board support
   (`https://arduino.esp8266.com/stable/package_esp8266com_index.json`).
2. Select board **LOLIN(WEMOS) D1 R2 & mini**.
3. Open `Software/Final_Software/Final_Software.ino`, upload, and open the Serial
   Monitor at **115200 baud**.

Step-by-step instructions are in the [full documentation](docs/DOCUMENTATION.md).

## Tests

The firmware's distance/beep logic is unit-tested on the host (no hardware
needed):

```sh
cd Software/Tests
c++ -std=c++11 -Wall -Wextra test_distance_logic.cpp -o test_distance_logic
./test_distance_logic
```

## Documentation

- 📘 [Full documentation](docs/DOCUMENTATION.md) — theory, hardware, firmware,
  build & flash, troubleshooting.
- 🛠️ [Work report](WORK_REPORT.md) — bugs fixed and improvements made.
- ✅ [Tests README](Software/Tests/README.md).

## License

See [LICENSE](LICENSE).
