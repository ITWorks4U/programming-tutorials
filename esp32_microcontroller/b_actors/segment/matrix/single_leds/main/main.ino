/*
* How to use an 8x8 matrix display with 16 pins. This matrix display
* doesn't come with an I2C or SPI interface. Without any external library
* you can control each LED by your own, however, you need 16 wires and
* 8 resistors. Usually a size of 220Ω shall be enough. In this sketch there
* were resistors with a size of 1kΩ in use.
*
* This sample shows you how to control each single LED.
*/

#define NBR_OF_FIELDS 8                               //  8 rows and also 8 columns
#define TIMEOUT       100                             //  can be milliseconds or microseconds
                                                      //  => this (drastically) affects the output

const int rows[] = {15,5,13,16,32,12,33,27};          //  pins for rows
const int columns[] = {19,18,4,14,2,26,25,17};        //  pins for columns
                                                      //  NOTE: These pins are in REVERSED order,
                                                      //        otherwise your output returns an
                                                      //        unexpected reversed result.

void setup() {
  for(int i = 0; i < NBR_OF_FIELDS; i++) {
    pinMode(columns[i], OUTPUT);
    pinMode(rows[i], OUTPUT);

    //  turn each row and column OFF
    digitalWrite(rows[i], LOW);
    digitalWrite(columns[i], HIGH);                   //  don't be confused, why each colum is set to HIGH
                                                      //  => since the colums have a different order in contrast
                                                      //  to the rows, the command must also be reversed, otherwise
                                                      //  those columns are fired on runtime
  }
}

void loop() {
  for(int i = 0; i < NBR_OF_FIELDS; i++) {
    for(int j = 0; j < NBR_OF_FIELDS; j++) {

      for(int p = 0; p < NBR_OF_FIELDS; p++) {        //  turn everything off first
        digitalWrite(rows[p], LOW);
        digitalWrite(columns[p], HIGH);
      }
      
      digitalWrite(rows[i], HIGH);                    // turn one LED on
      digitalWrite(columns[j], LOW);

      //  have fun with delays ;-)
      //  NOTE: Sometimes it's an awful decision to use any deleay.
      delay(TIMEOUT);
      // delayMicroseconds(TIMEOUT);
    }
  }  
}