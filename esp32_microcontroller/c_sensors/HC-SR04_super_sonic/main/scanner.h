#ifndef SCANNER_H
#define SCANNER_H

#define TRIG_PIN      5                 //  trigger pin
#define ECHO_PIN      18                //  echo pin
#define BAUD_RATE     115200            //  serial baud rate
#define ECHO_DISTANCE 0.0343 / 2.0      //  sonic speed on 20°C room temperature (343 m/s)


void init_scanner();
long scan_area();

#endif