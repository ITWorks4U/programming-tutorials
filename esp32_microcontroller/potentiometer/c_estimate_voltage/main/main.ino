/*
* Estimate the remaining voltage by using a potentiometer.
* This value will be different each time event.
*/

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define PIN_POTENTIOMETER   A0
#define VOLTAGE_VALUE       5.0
#define ADC_MAX_VALUE       1023
#else
#define PIN_POTENTIOMETER   34
#define VOLTAGE_VALUE       3.3
#define ADC_MAX_VALUE       4095
#endif

#define SERIAL_BAUD_RATE    57600

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(PIN_POTENTIOMETER, INPUT);
}

void loop() {
    int adc_value = analogRead(PIN_POTENTIOMETER);
    float voltage = (adc_value / static_cast<float>(ADC_MAX_VALUE)) * VOLTAGE_VALUE;

    String summary = "ADC value: " + String(adc_value) + " | estimated voltage: " + String(voltage) + "V";
    Serial.println(summary);

    delay(100);
}