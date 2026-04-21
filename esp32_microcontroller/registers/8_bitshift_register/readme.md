#   using an 8-bitshift-register (74HC595)

-   allows to control up to eight different devices with only one indepentend input (e. g.: 8 LEDs) or a 7-segment-display (up to all 8 input ports)
-   this module requires 3 input pins to be able to use
-   this module can operate up to 500,000 commands each second

>   **NOTE**:   To control a 7-segment-display with a 74HC595 module, a resistor with at least **500Ω** is recommended, otherwise this may damage your device(s), because the 74HC595 module operates with up to 50mA. The lower the resistor value, the higher the electric current flow. 

### pins

-   orientation: bottom left to right

| pin | description | additional information |
| - | - | - |
| 1 | output 2 | this is the first pin (marked with a dot) |
| 2 | output 3 | - |
| 3 | output 4 | - |
| 4 | output 5 | - |
| 5 | output 6 | - |
| 6 | output 7 | - |
| 7 | output 8 | - |
| 8 | GND | - |

-   orientation top left to right

| pin | description | additional information |
| - | - | - |
| 9 | power | requires 5V; 3.3V is too few power and too much power may damage your device |
| 10 | output 1 | - |
| 11 | data input | handles up to 8 incoming bit values (0 or 1); each remaining input value moves the first "handled" bits to the inverted output (usually discards them, if this pin is not connected) |
| 12 | enable output | GND for maximize the visibility of the LEDs; more in use, if a PWM pin shall control their visibility |
| 13 | output register clock | if active, then the incoming bits are going to handle  |
| 14 | shift register clock | defines the clock rate (depending on the used microcontroller) |
| 15 | register clean | on a LOW signal the register is going to reset; on HIGH (e. g. permanently 5V) no reset is going to use |
| 16 | inverted output | more in use, if the currently handled bits shall be handled / moved to an another register module or else; if no connection is given, then the currently, already handled bits are going to discard |