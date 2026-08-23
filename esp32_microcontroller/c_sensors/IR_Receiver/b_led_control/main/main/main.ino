/*
* ESP32 DevKit V1 + KY-022 IR receiver
*
* IR receiver : GPIO 15
* LED         : GPIO 13
*
* used commands:
*   0x02 => LED OFF (LED is OFF and no animation is in use)
*   0x03 => LED ON  (LED is ON and still no animation)
*   0x08 => BLINK   (LED must be ON before | optionally, BREATH command can be set earlier)
*   0x09 => BREATH  (LED must be ON before | optionally, BLINK command can be set earlier)
*
* meachanics:
*   - blink and breath are mutually exclusive
*   - 0x08 / 0x09 do nothing while LED is OFF
*   - 0x02 always switches LED OFF and disables the animation mode
*   - IR repeat frames are ignored
*   - ignore an identical command immediately => don't "restart" the animation(s)
*
*   author:   ITWorks4U
*   created:  August 20th, 2026
*   updated:  August 23rd, 2026
*   version:  1.0.0
*/

#define NO_LED_FEEDBACK_CODE                    //  don't use a LED feedback blink
#define SERIAL_BAUD_RATE        115200

#include <IRremote.hpp>
#include "led_operations.h"

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(LED_PIN, OUTPUT);

    toggle_led(/*turn_on: */ false);
    IrReceiver.begin(IR_RECEIVE_PIN);           //  without external LED feedback, like internal LED on the MCU

    lastStateUpdate = millis();
}

void loop() {
    //  calls loop() once only to avoid additional time consuming
    //  whenever the loop function is called next time
    while (true) {
        processing_ir_signal();
        update_led();
    }
}