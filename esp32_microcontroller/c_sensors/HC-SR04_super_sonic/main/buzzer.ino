#include "buzzer.h"

static void _play(int frequency, int duration) {
  ledcWriteTone(/*pin: */BUZZER_PIN, /*freq: */ frequency);
  delay(duration);
  ledcWriteTone(BUZZER_PIN, 0);
}

void init_buzzer() {
  pinMode(LED_PIN, OUTPUT);
  ledcAttach(/*pin: */ BUZZER_PIN, /*freq: */ 2000, /*resolution: */ 8);
}

void make_sound() {
  static String s;

  for(int i = 100; i <= 2000; i+=5) {
    s = "frequency: " + String(i) + " Hz...";
    Serial.println(s);
    _play(i, 10);
  }

  for(int i = 2000; i >= 100; i -= 5) {
    _play(i, 10);
  }

  // _play(262, 300); // C4
  // _play(294, 300); // D4
  // _play(330, 300); // E4
  // _play(349, 300); // F4
  // _play(392, 300); // G4
}

void trigger_alarm() {
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW); 
    _play(1000, 150);
  }
}