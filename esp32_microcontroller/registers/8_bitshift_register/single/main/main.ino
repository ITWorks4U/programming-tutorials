/*
* Control a 7-segment-display by using an 8-bitshift-register (74HC595)
* module. This allows to use only 3 required input pins, whereas this
* register comes with 8 output pins and also an inverted output pin
* to move the handled 8 bits to an another device.
*
* Each 200ms the counter raises by one and displays the number
* sequence from 0 to 9.
*
* NOTE: This script comes from tinkercad with an Arduino Uno Rev. 3.
*       The used pins can be different to your used microcontroller.
*/

#define LATCH_PIN    3
#define CLOCK_PIN    2
#define INPUT_PIN    4

#define TIMEOUT_MS   200
#define MAX_BOUNDARY 10

const byte seven_seg_bits[] = {             // NOTE: typedef uint8_t byte; <=> uint8_t <=> unsigned char
  0b11111100,   // 0                        //       ==> to handle the values between 0 and 255
  0b01100000,   // 1
  0b11011010,   // 2
  0b11110010,   // 3
  0b01100110,   // 4
  0b10110110,   // 5
  0b10111110,   // 6
  0b11100000,   // 7
  0b11111110,   // 8
  0b11110110    // 9
};

static byte digit = 0;

void seven_seg_write() {
  digitalWrite(LATCH_PIN, LOW);             // turn off the LATCH pin to register a new byte stream
  shiftOut(
    INPUT_PIN,                              // the pin, which handles the input data (outgoing data)
    CLOCK_PIN,                              // the pin for the internal clock
    LSBFIRST,                               // determines the bit order; MSBFIRST => left to right | LSBFIRST => right to left
    seven_seg_bits[digit]                   // the required field of bits to use (position [0..9] of the seven_seg_bits field)
  );
  digitalWrite(LATCH_PIN, HIGH);            // turn the LATCH pin ON to handle the byte stream
}

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(INPUT_PIN, OUTPUT);
}

void loop() {
  static unsigned long last_timer = 0;

  if (millis() - last_timer > TIMEOUT_MS) { // unlike to use delay() or delayMicroseconds() no truly delay exists here
    last_timer = millis();
    seven_seg_write();

    digit = (digit + 1) % MAX_BOUNDARY;
  }
}