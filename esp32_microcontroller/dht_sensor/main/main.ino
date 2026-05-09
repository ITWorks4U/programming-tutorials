/*
* Do you want to scan the temperature and/or humidity value?
* With a module, like DHT11 or DHT22 this is possible.
*
* You also need an external library, e. g. from Adafruit.
*
* NOTE: Usually, a timeout of 2 seconds (2,000 ms) is minimal
*       required to work with a clean data request, otherwise
*       you'll receive the previous output or any garbage.
*
*       However, even after the minimal timeout you may also
*       receive garbage value for the next scan.
*/

#include <DHT.h>

#define PIN_DHT           13
#define SERIAL_BAUD_RATE  57600
#define TIMEOUT_DHT_IN_MS 3000

DHT sensor(PIN_DHT, DHT22);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  sensor.begin();
}

void loop() {
  float hum = sensor.readHumidity();
  float temp = sensor.readTemperature();

  String s = "humidity: " + String(hum) + "% | temperature: " + String(temp) + "°C";
  Serial.println(s);

  delay(TIMEOUT_DHT_IN_MS);
}
