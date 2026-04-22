/*
* A potentiometer is a scalable resistor, which is almost everywhere included.
* The remaining voltage doesn't return a value of "0" or "1", because this is
* not a digital value. This is an analog value instead.
*
* On an analog pin, depending on which microcontroller you're using,
* usually a value between [0..1023] (2^10) returns. For an ESP32 this value
* comes with a range of [0..4095] (2^12).
*
* NOTE: If you're using a microcontroller, like an ESP32, which comes with
*       an operation voltage of 3.3V, you should NOT use 5V or more for any
*       GPIO pin, otherwise this leads into any undefined behavior and also
*       may damage your microcontroller and possible physically connected devices.
*/

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//NOTE: This is an experimental way to figure out, if you're working
//      on an Arduino Board.
#define PIN_POTENTIOMETER   A0
#else
#define PIN_POTENTIOMETER   34
#endif

#define SERIAL_BAUD_RATE    57600

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(PIN_POTENTIOMETER, INPUT);
}

void loop() {
    int pot_val = analogRead(PIN_POTENTIOMETER);              // comes with a range of 0..4095 (ESP32) or "just" 0..1023 (Arduino Uno)
    Serial.println(pot_val);

    delay(100);
}