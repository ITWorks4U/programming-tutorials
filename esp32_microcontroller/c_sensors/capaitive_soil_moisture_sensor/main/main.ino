/*
* Have you ever thought about how to use a capaitive soil
* moisture sensor? There are different models and they return
* a different result depending on the used power supply and the
* internal remaining voltage for the analog pin.
*
* This setup shows a minimal sketch of how to use any
* moisture sensor.
*
* NOTE: This sketch has been optimized with a capaitive soil
*       moisture sensor v 1.2. The higher the ADC value,
*       the more dry is this sensor. If you're using a different
*       sensor, then the ADC value, as well as, the estimated
*       minimal and maximal values may be different.
*/

#define SENSOR_MOISTURE_PIN   34                              // those pin is more useful to read a sensor data
#define SERIAL_BAUD_RATE      57600
#define MIN_VAL               250
#define MAX_VAL               2500

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(SENSOR_MOISTURE_PIN, INPUT);                        // such pin doesn't support a setting, like INPUT_PULLUP or INPUT_PULLDOWN
                                                              // if you need a pull resistor, then you must use a hardware based pull resistor setup
}

void loop() {
  int adc_val = analogRead(SENSOR_MOISTURE_PIN);
  long percent_map = map(adc_val, MIN_VAL, MAX_VAL, 0, 100);  // usually, the map() function works well, however, sometimes you'll
                                                              // receive a value outside of [0..100]

  //NOTE: The constrain() macro function must NOT use
  //      with different data types, otherwise an un-
  //      defined behavior returns.
  long percent = constrain(percent_map, 0, 100);              // combine with the constrain() macro function to reveive a clean
                                                              // range between [0..100]

  String s = "adc_val: " + String(adc_val) + " <=> dry value: " + String(percent) + "%";
  Serial.println(s);
}
