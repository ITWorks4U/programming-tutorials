/*
* The map() function is an universal and also powerful function
* to let to calculate whatever you want. Let's say you want to
* figure out how much the incoming value could be in a percentaual value.
*/

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//NOTE: This is an experimental way to figure out, if you're working
//      on an Arduino Board.
#define PIN_POTENTIOMETER   A0
#define MAX_VALUE           1023
#else
#define PIN_POTENTIOMETER   34
#define MAX_VALUE           4095
#endif

#define SERIAL_BAUD_RATE    57600

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(PIN_POTENTIOMETER, INPUT);
}

void loop() {
    int adc_value = analogRead(PIN_POTENTIOMETER);
    float percent = static_cast<float>((adc_value, 0, MAX_VALUE, 0, 100));

    String summary = "ADC value: " + String(adc_value) + " <=> " + String(percent) + "%";
    Serial.println(summary);

    delay(100);
}