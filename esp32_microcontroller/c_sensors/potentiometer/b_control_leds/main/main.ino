/*
* Control leds, when a certain value returns.
*
* NOTE: The macro conditions are experimental and may
*       differ on your used microcontroller. When an
*       Arduino (Uno) has been detected, then the values
*       may return a different range.
*/

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define PIN_POTENTIOMETER   A0
#else
#define PIN_POTENTIOMETER   34
#endif

#define PIN_RED             13
#define PIN_YELLOW          12
#define PIN_GREEN           14

static int pot_val = -1;

void check_value(void) {
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    //NOTE: This is an experimental way to figure out, if you're working
    //      on an Arduino Board. An Arduino (Uno) comes with a smaller
    //      number range instead of an ESP32. => 0..1023 instead of 0..4095
    if (pot_val >= 0 && pot_val < 128) {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, LOW);
    } else if (pot_val >= 128 && pot_val < 256) {
        digitalWrite(PIN_RED, HIGH);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, LOW);
    } else if (pot_val >= 256 && pot_val < 512) {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, HIGH);
        digitalWrite(PIN_GREEN, LOW);
    } else {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, HIGH);
    }
    #else
    if (pot_val >= 0 && pot_val < 1023) {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, LOW);
    } else if (pot_val >= 1024 && pot_val < 2048) {
        digitalWrite(PIN_RED, HIGH);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, LOW);
    } else if (pot_val >= 2048 && pot_val < 3712) {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, HIGH);
        digitalWrite(PIN_GREEN, LOW);
    } else {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_YELLOW, LOW);
        digitalWrite(PIN_GREEN, HIGH);
    }
    #endif
}

void setup() {
    pinMode(PIN_POTENTIOMETER, INPUT);
    pinMode(PIN_RED, INPUT);
    pinMode(PIN_YELLOW, INPUT);
    pinMode(PIN_GREEN, INPUT);
}

void loop() {
    pot_val = analogRead(PIN_POTENTIOMETER);
    check_value();

    delay(100);
}