/*
* Control a LED with your microcontroller. The anode (long pin) uses the
* incomping power (VCC), whereas the cathode (short pin) goes to ground (GND).
*
* NOTE: By powering a LED directly with 5V or even 3.3V this drastically
*       reduces the LED's lifetime. Your LED may also be break immedeately.
*
*       Make sure to use a resistor. This can be placed between the source
*       and anode or between cathode and GND. This doesn't matter.
*       Usually, a resistor of 220Ω is in use for all kind of LEDs.
*
*       A blue / white LED requires more power in contrast red / green / yellow, ...,
*       thus those LEDs requires a smaller resistor, like 100Ω.
*/

#define PIN_LED     12              // pin address to control the LED
#define TIMEOUT_MS  1000            // 1,000ms => 1s timeout for the next event

void setup() {
    pinMode(PIN_LED, OUTPUT);       // this pin is addressed as an output pin
}

void loop() {
    static bool toggle_led = false; // toggle between ON and OFF for this single LED
    toggle_led = !toggle_led;       // switch between true and false each runtime

    digitalWrite(                   // this controls the LED with 3.3V / 5V or 0V, depending on HIGH (= ON) or LOW (= OFF)
        PIN_LED,                    // use the pin address
        toggle_led ? HIGH : LOW     // and decide what action shall be done
    );

    delay(TIMEOUT_MS);              // wait 1,000ms before the loop() function repeats
}