#include <Keypad.h>                                     //  library:  keypad (Mark Stanley, Alexander Brevig)
#include "input.h"

#define SERIAL_BAUD_RATE  115200

const char keys[ROW_NUM][COLUMN_NUM] = {                //  a map for a 4x4 keypad
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[] = {13, 12, 14, 27};                     //  used pins for the rows
byte pin_column[] = {17, 5, 18, 19};                    //  used pins for the columns

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
  char key = keypad.getKey();

  // switch(keypad.getState()) {
  //   case IDLE:
  //     Serial.println("No key currently pressed");
  //     break;
  //   case PRESSED:
  //     Serial.println("any key pressed");
  //     break;
  //   case HOLD:
  //     Serial.println("button hold");                 //  estimated time amount: 2s
  //     break;
  //   case RELEASED:
  //     Serial.println("button released");
  //     break;
  //   default:
  //     break;
  // }

  if (key) {
    if(key == CONFIRM_KEY) {
      terminate_input();
      // Serial.println(print_input());

      if (compare_with_preset()) {
        Serial.println("\tInput was correct.");
      } else {
        Serial.println("\tInput was invalid.");
      }

      reset_input();
    } else if (key == CANCEL_KEY) {
      reset_input();
    } else {
      append_input(key);
      Serial.print(key);
    }
  }
}