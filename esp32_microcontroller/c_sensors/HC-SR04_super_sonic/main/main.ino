#include "scanner.h"
#include "buzzer.h"

void setup() {
  Serial.begin(BAUD_RATE);
  
  init_scanner();  
  init_buzzer();
}

void loop() {
  long distance = scan_area();

  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    // Speed of sound = 343 m/s
    float distance_cm = distance * ECHO_DISTANCE;

    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    if (distance_cm < 15 || distance_cm > 40) {
      trigger_alarm();
    }
  }
  
  delay(500);

  // make_sound();
  // delay(1000);
}