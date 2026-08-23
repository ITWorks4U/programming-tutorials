#include <Stepper.h>
#define STEPS_PER_REVOLUION   2048
#define IN1                   19
#define IN2                   18
#define IN3                   5
#define IN4                   17

Stepper s(
  /*number_of_steps: */ STEPS_PER_REVOLUION,
  /*motor_pin_1: */     IN1,
  /*motor_pin_2: */     IN2,
  /*motor_pin_3: */     IN3,
  /*motor_pin_4: */     IN4
);

void setup() {
  s.setSpeed(5);
  Serial.begin(115200);
}

void loop() {
  Serial.println("clockwise");
  s.step(STEPS_PER_REVOLUION);
  delay(1000);

  //  NOTE: Depending on the used stepper motor driver
  //        module, it may happen, that the counter clockwise
  //        movement may be unavailable. This is not part
  //        of the used library.

  Serial.println("counterclockwise");
  s.step(-1 * STEPS_PER_REVOLUION);
  delay(1000);
}
