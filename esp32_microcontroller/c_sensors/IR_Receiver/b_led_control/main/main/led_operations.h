#ifndef LED_OPERATIONS_H
#define LED_OPERATIONS_H

/////
//  definitions
/////

#define IR_RECEIVE_PIN    15
#define LED_PIN           13

#define CMD_OFF           0x02              //  turn off the LED
#define CMD_ON            0x03              //  turn on the LED
#define CMD_BLINK         0x08              //  blink LED for each 250ms  
#define CMD_BREATH        0x09              //  do a "breath" of a LED (0 <=> 255 <=> 0)

#define STATE_UPDATE_MS   5                 //  5ms update time for a "breath"
#define BLINK_PERIOD_MS   500               //  period time for a full blink (250ms for each state)
#define BREATH_PERIOD_MS  2000              //  breath speed; one complete fade-in/out cycle

/////
//  data types
/////

typedef enum {
    MODE_OFF,
    MODE_ON,
    MODE_BLINK,
    MODE_BREATH
} LedMode;

/////
//  external definition(s)
/////
extern uint32_t lastStateUpdate;

/////
//  function prototypes
/////

//  Toggle LED depending on turn_on state. Defaults to true.
void toggle_led(bool turn_on = true);

//  Processing for the next incoming IR signal.
//
//  Ignores the same incoming IR signal.
void processing_ir_signal(void);

//  Update the LED depending on the last set mode.
//
//  See: LedMode enumeration.
void update_led(void);

#endif