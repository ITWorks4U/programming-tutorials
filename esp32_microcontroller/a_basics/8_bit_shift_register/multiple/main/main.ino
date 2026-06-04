/*
* Control 4 times 7-segment-displays by using 4 times 8-bitshift-register (74HC595)
* modules. This still requires 3 input pins.
*
* Each 50ms the counter raises by one and displays the number
* sequence from 0000 to 9999.
*
* NOTE: This script comes from tinkercad with an Arduino Uno Rev. 3.
*       The used pins can be different to your used microcontroller.
*/

#define LATCH_PIN    3
#define CLOCK_PIN    2
#define INPUT_PIN    4

#define TIMEOUT_MS   50
#define MAX_BOUNDARY 10000
#define MOD_TENS     10

const byte seven_seg_bits[] = {
  0b11111100,   // 0
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
  byte ones = digit % MOD_TENS;
  byte tens = (digit / 10) % MOD_TENS;
  byte hundrets = (digit / 100) % MOD_TENS;
  byte thousands = (digit / 1000) % MOD_TENS;

  digitalWrite(LATCH_PIN, LOW);
  shiftOut(INPUT_PIN, CLOCK_PIN, LSBFIRST, seven_seg_bits[ones]);
  shiftOut(INPUT_PIN, CLOCK_PIN, LSBFIRST, seven_seg_bits[tens]);
  shiftOut(INPUT_PIN, CLOCK_PIN, LSBFIRST, seven_seg_bits[hundrets]);
  shiftOut(INPUT_PIN, CLOCK_PIN, LSBFIRST, seven_seg_bits[thousands]);
  digitalWrite(LATCH_PIN, HIGH);
}

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(INPUT_PIN, OUTPUT);
}

void loop() {
  static unsigned long last_timer = 0;

  if (millis() - last_timer > TIMEOUT_MS) {
    last_timer = millis();
    seven_seg_write();

    digit = (digit + 1) % MAX_BOUNDARY;
  }
}