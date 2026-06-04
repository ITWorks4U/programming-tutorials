/*
* Control a RGB LED with your microcontroller. This led comes with 4 pins,
* where the longest pin is the cathode. Usually, these pins controls these leds:
*
* left of the cathode:  red
* right of the cathode: green
* shortest pin:         blue
*
* Similar to a casual LED a resistor for each color is required.
* There's also one resistor possible, which is connected to the cathode,
* however, this shall sum up on the highest value for all three single LEDs.
*
* NOTE: By powering a LED directly with 5V or even 3.3V this drastically
*       reduces the LED's lifetime. Your LED may also be break immedeately.
*
*       A blue / white LED requires more power in contrast red / green / yellow, ...,
*       thus those LEDs requires a smaller resistor, like 100Ω, otherwise a resistor
*       with 220Ω shall be enough for each single LED.
*/

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define PIN_RED     2
#define PIN_GREEN   3
#define PIN_BLUE    4
#define PIN_POT     A0

#define RANGE_LOW          32
#define RANGE_RED          64
#define RANGE_GREEN        128
#define RANGE_BLUE         192
#define RANGE_CYAN         256
#define RANGE_YELLOW       512
#define RANGE_PURPLE       768
#else
#define PIN_RED     15
#define PIN_GREEN   2
#define PIN_BLUE    4
#define PIN_POT     13

#define RANGE_LOW          512
#define RANGE_RED          1024
#define RANGE_GREEN        1536
#define RANGE_BLUE         2048
#define RANGE_CYAN         2560
#define RANGE_YELLOW       3712
#define RANGE_PURPLE       3684
#endif

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_POT, INPUT);
}

void loop() {
  int pot_val = analogRead(PIN_POT);

  if (pot_val >= 0 && pot_val < RANGE_LOW) {                       //  all off
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);
  } else if (pot_val >= RANGE_LOW && pot_val < RANGE_RED) {        //  red only
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);
  } else if (pot_val >= RANGE_RED && pot_val < RANGE_GREEN) {      //  green only
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, LOW);
  } else if (pot_val >= RANGE_GREEN && pot_val < RANGE_BLUE) {     //  blue only
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, HIGH);
  } else if (pot_val >= RANGE_BLUE && pot_val < RANGE_CYAN) {      //  blue + green  =>  cyan
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, HIGH);
  } else if (pot_val >= RANGE_CYAN && pot_val < RANGE_YELLOW) {    //  red + green   =>  yellow
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, LOW);
  } else if (pot_val >= RANGE_YELLOW && pot_val < RANGE_PURPLE) {  //  red + blue    =>  purple
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, HIGH);
  } else {                                                         //  turn all on   =>  white
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, HIGH);
  }
}