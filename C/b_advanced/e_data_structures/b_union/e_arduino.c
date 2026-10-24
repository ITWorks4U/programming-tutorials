/*  Imagine, you're running this for a microcontroller, like an Arduino.
*
*   NOTE:   This shows an example only for microcontrollers, which supports
*           the Arduino enviroment. Other frameworks, like ESP-IDF,
*           HAL (STM32), ... may not use this.
*
*   NOTE:   Outside of an Arduino enviroment this is not able to build.
*
*   NOTE:   Those sensors were in use:
*           temperature sensor = TMP36
*           moisture sensor = a default moisture sensor without a specific name
*/

//  NOTE:   more in use, if you don't use the Arduino IDE (e. g. Visual Studio Code with PlatformIO)
#include <Arduino.h>

#define ADDRESS_SENSOR_MOISTURE     A0
#define ADDRESS_SENSOR_TEMPERATURE  A1
#define TIMEOUT_IN_MS               1000
#define TIMEOUT_SENS_MOISTURE_IN_MS 3500
#define TIMEOUT_SENS_TEMP_IN_MS     2000
#define SERIAL_BAUD_RATE            9600

typedef unsigned long ulong_t;

typedef union {
    int sens_temperature;
    int sens_moisuture;
} SensorData;

void setup() {
    pinMode(ADDRESS_SENSOR_MOISTURE, INPUT);
    pinMode(ADDRESS_SENSOR_TEMPERATURE, INPUT);
    Serial.begin(SERIAL_BAUD_RATE);
    delay(TIMEOUT_IN_MS);

    SensorData sd;
    ulong_t last_timestamp_temperature = 0UL;
    ulong_t last_timestamp_moisture = 0UL;

    //  instead of using the loop function below this also
    //  reduces additional time for the next function call itself
    //  => more in use for professional workflow with ESP-IDE, HAL (STM32), ...
    while(1) {
        ulong_t current = millis();

        if (current - last_timestamp_temperature > TIMEOUT_SENS_TEMP_IN_MS) {
            last_timestamp_temperature = current;
            int sens_val = analogRead(ADDRESS_SENSOR_TEMPERATURE);

            //  TMP36 comes with a range of [20; 358] and this can
            //  be used for a certain temperature range between [-40; 125] °C
            sd.sens_temperature = map(sens_val, 20, 358, -40, 125);
            Serial.println(sd.sens_temperature);
        }

        if (current - last_timestamp_moisture > TIMEOUT_SENS_MOISTURE_IN_MS) {
            last_timestamp_moisture = current;
            int sens_val = analogRead(ADDRESS_SENSOR_MOISTURE);

            //  a classic moisture sensor may come with a sensor value in the
            //  range between [0; 876] and this shows the moisture value in
            //  a range between [0; 100]%
            sd.sens_moisuture = map(sens_val, 0, 876, 0, 100);
            Serial.println(sd.sens_moisuture);
        }
    }
}

void loop() {}