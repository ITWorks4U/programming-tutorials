#include "scanner.h"

void init_scanner() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);
}

long scan_area() {
  // Send a 10 µs pulse to trigger the measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pulse duration (timeout: 30 ms)
  return pulseIn(ECHO_PIN, HIGH, 30000);
}