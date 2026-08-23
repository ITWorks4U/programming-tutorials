/*
* Use a KY-008 laser emitter to display a laser point by a laser beam.
*
* NOTE: This laser emitter comes with a laser class of 2 or 3.
*       DON'T take a look into the active laser without eye protection,
*       otherwise you may receive a horrible damage for your eyes!
*/

#define LASER_EMITTER_PIN   15
#define TIMEOUT_IN_MS       2500

typedef unsigned long ulong_t;

void setup() {
  pinMode(LASER_EMITTER_PIN, OUTPUT);
}

void loop() {
  static ulong_t last_trigger = 0;
  ulong_t current_millis = millis();

  if (current_millis - last_trigger >= TIMEOUT_IN_MS) {
    last_trigger = current_millis;

    static bool toggle_laser = false;
    toggle_laser = !toggle_laser;

    digitalWrite(LASER_EMITTER_PIN, (toggle_laser ? HIGH : LOW));
  }
}
