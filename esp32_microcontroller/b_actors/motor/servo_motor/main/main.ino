/*
* A servo motor is a simple device to move lightweighted devices.
* Pitfall:  By default the Arduino IDE comes with a header file for
*           servo motors, however, this library is designed for
*           Arduino UNO and a few other micro controllers. By using
*           an ESP32 the sketch is usually unable to build. You have
*           to use an external library, like: https://github.com/madhephaestus/ESP32Servo
*/

// #include <Servo.h>               //  pitfall for an ESP32

#include <ESP32Servo.h>

#define PIN_SERVO_MOTOR   13
#define SERIAL_BAUD_RATE  57600
#define UPPER_ANGLE_VALUE 180

#define AUTOMATIC_ANGLE_SETUP       //  if defined, then the servo motor moves automatically from 0..180 degrees

Servo s;

void setup() {
  s.attach(PIN_SERVO_MOTOR);
  Serial.begin(SERIAL_BAUD_RATE);
  s.write(0);
}

void loop() {
  #ifndef AUTOMATIC_ANGLE_SETUP
  //  only for an external input (e. g. serial communication)
  //  NOTE: By default the perseInt() method "handles" any
  //        invalid input, like "abc", "abc123" or else with 0.

  if (Serial.available()) {
    long angle = Serial.parseInt(); //  read from serial stream
    s.write(angle);                 //  write the (expected) angle value to the servo motor
  }

  #else
  //  only for an automatic move from 0..180 and reversal direction
  for(int i = 0; i <= UPPER_ANGLE_VALUE; i++) {
    s.write(i);
  }

  for(int i = UPPER_ANGLE_VALUE; i >= 0; i--) {
    s.write(i);
  }
  #endif
}