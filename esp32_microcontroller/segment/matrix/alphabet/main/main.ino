/*
* How to display the letters in alphabetical order on an 8x8 matrix.
* Each letter comes with a field of 8 bits 8 times to ensure to control
* all 64 leds.
*/

#define NBR_OF_FIELDS 8
#define TIMEOUT_MS    500                           //  in use for loop()
#define LETTERS_COUNT 26                            //  26 letters

const int rows[] = {15,5,13,16,32,12,33,27};        //  pins for rows
// const int columns[] = {17,25,26,2,14,4,18,19};   //  reversed order for colums => mirrored display
const int columns[] = {19,18,4,14,2,26,25,17};      //  pins for columns

unsigned long millis_now;
int time_count = 0;

//  fields for each letter ("only" 8 members)
//  => each member comes with 8 bits (1 = HIGH, 0 = LOW)
//  ==> all 64 LEDs can be controlled

const int A[] = {0b11111111,0b11000011,0b10011001,0b10011001,0b10000001,0b10011001,0b10011001,0b10011001};
const int B[] = {0b10000111,0b10110111,0b10110111,0b10001111,0b10110111,0b10111011,0b10111011,0b10000011};
const int C[] = {0b11111111,0b11100001,0b11011111,0b10111111,0b10111111,0b10111111,0b11011111,0b11100001};
const int D[] = {0b11111111,0b11000111,0b11011011,0b11011101,0b11011101,0b11011011,0b11000111,0b11111111};
const int E[] = {0b11111111,0b11000011,0b11011111,0b11000111,0b11011111,0b11011111,0b11000011,0b11111111};
const int F[] = {0b11111111,0b11000011,0b11011111,0b11000111,0b11011111,0b11011111,0b11011111,0b11111111};
const int G[] = {0b11111111,0b11000001,0b11011111,0b11011111,0b11010001,0b11011101,0b11000001,0b11111111};
const int H[] = {0b11111111,0b11011011,0b11011011,0b11000011,0b11011011,0b11011011,0b11011011,0b11111111};
const int I[] = {0b11111111,0b11000111,0b11101111,0b11101111,0b11101111,0b11101111,0b11000111,0b11111111};
const int J[] = {0b11111111,0b11100011,0b11110111,0b11110111,0b11110111,0b11010111,0b11000111,0b11111111};
const int K[] = {0b11111111,0b11011011,0b11010111,0b11001111,0b11010111,0b11011011,0b11011011,0b11111111};
const int L[] = {0b11111111,0b11011111,0b11011111,0b11011111,0b11011111,0b11011111,0b11000011,0b11111111};
const int M[] = {0b11111111,0b11111111,0b10111011,0b01010101,0b01101101,0b01111101,0b01111101,0b11111111};
const int N[] = {0b11111111,0b11011101,0b11001101,0b11010101,0b11011001,0b11011101,0b11111111,0b11111111};
const int O[] = {0b11111111,0b11000011,0b10111101,0b10111101,0b10111101,0b10111101,0b11000011,0b11111111};
const int P[] = {0b11111111,0b11000111,0b11011011,0b11011011,0b11000111,0b11011111,0b11011111,0b11111111};
const int Q[] = {0b11111111,0b11000011,0b10111101,0b10111101,0b10111101,0b10111001,0b11000001,0b11111110};
const int R[] = {0b11111111,0b11000111,0b11011011,0b11011011,0b11000111,0b11011011,0b11011011,0b11111111};
const int S[] = {0b11111111,0b11000011,0b11011111,0b11000011,0b11111011,0b11111011,0b11000011,0b11111111};
const int T[] = {0b11111111,0b10000011,0b11101111,0b11101111,0b11101111,0b11101111,0b11101111,0b11111111};
const int U[] = {0b11111111,0b10111101,0b10111101,0b10111101,0b10111101,0b11011011,0b11100111,0b11111111};
const int V[] = {0b11111111,0b11011101,0b11011101,0b11011101,0b11101011,0b11101011,0b11110111,0b11111111};
const int W[] = {0b11111111,0b01111101,0b01101101,0b10101011,0b10101011,0b11010111,0b11111111,0b11111111};
const int X[] = {0b11111111,0b10111101,0b11011011,0b11100111,0b11100111,0b11011011,0b10111101,0b11111111};
const int Y[] = {0b11111111,0b10111011,0b11010111,0b11101111,0b11101111,0b11101111,0b11101111,0b11111111};
const int Z[] = {0b11111111,0b11000011,0b11111011,0b11110111,0b11101111,0b11011111,0b11000011,0b11111111};

void draw_screen(const int *buffer) {
  for(int i = 0; i < NBR_OF_FIELDS; i++) {
    digitalWrite(rows[i], HIGH);                          //  turn each row ON

    for(int j = 0; j < NBR_OF_FIELDS; j++) {
      digitalWrite(columns[j], (buffer[i] >> j) & 1);     //  turn each column OFF, which shall not be displayed
                                                          //  this will be realized, if on the right shifted buffer
                                                          //  value in combination with bit-and 1 results to 1 (HIGH)
                                                          //  each HIGH value turns this column row >>OFF<<

      // delayMicroseconds(100);                          //  By using any delay you'll see a (very) high
      // delayMicroseconds(1000);                         //  flickering output. The higher the delay, the
      // delay(10);                                       //  the more clean result returns, whereas not each
      // delay(100);                                      //  LED can be displayed and your result is hardly to detect.
                                                          //  In summary: Don't use a delay.

      digitalWrite(columns[j], HIGH);
    }

    digitalWrite(rows[i], LOW);                           //  turn the remaining rows OFF
  }
}

void setup() {
  for(int i = 0; i < NBR_OF_FIELDS; i++) {
    pinMode(columns[i], OUTPUT);
    pinMode(rows[i], OUTPUT);

    //  turn each row and column OFF
    digitalWrite(rows[i], LOW);
    digitalWrite(columns[i], HIGH);                       //  don't be confused, why each colum is set to HIGH
                                                          //  => since the colums have a different order in contrast
                                                          //  to the rows, the command must also be reversed, otherwise
                                                          //  those columns are fired on runtime
  }
}

void loop() {
  if (millis() - millis_now > TIMEOUT_MS) {               //  wait for each elapsed 501+ milliseconds
    millis_now = millis();
    time_count = (time_count + 1) % LETTERS_COUNT;
  }

  switch(time_count) {                                    //  this allows to display each letter for 500ms
    case 0:                                               //  where the loop() function can be called thousand
      draw_screen(A);                                     //  times in a single second
      break;
    case 1:
      draw_screen(B);
      break;
    case 2:
      draw_screen(C);
      break;
    case 3:
      draw_screen(D);
      break;
    case 4:
      draw_screen(E);
      break;
    case 5:
      draw_screen(F);
      break;
    case 6:
      draw_screen(G);
      break;
    case 7:
      draw_screen(H);
      break;
    case 8:
      draw_screen(I);
      break;
    case 9:
      draw_screen(J);
      break;
    case 10:
      draw_screen(K);
      break;
    case 11:
      draw_screen(L);
      break;
    case 12:
      draw_screen(M);
      break;
    case 13:
      draw_screen(N);
      break;
    case 14:
      draw_screen(O);
      break;
    case 15:
      draw_screen(P);
      break;
    case 16:
      draw_screen(Q);
      break;
    case 17:
      draw_screen(R);
      break;
    case 18:
      draw_screen(S);
      break;
    case 19:
      draw_screen(T);
      break;
    case 20:
      draw_screen(U);
      break;
    case 21:
      draw_screen(V);
      break;
    case 22:
      draw_screen(W);
      break;
    case 23:
      draw_screen(X);
      break;
    case 24:
      draw_screen(Y);
      break;
    case 25:
      draw_screen(Z);
      break;
  }
}