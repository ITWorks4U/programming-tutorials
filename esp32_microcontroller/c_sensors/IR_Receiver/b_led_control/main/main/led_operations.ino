#include "led_operations.h"

static LedMode ledMode = MODE_OFF;                              //  initial value for LED mode
static uint16_t lastAcceptedCommand = 0xFF;                     //  last accepted command => avoids to reset the state,
                                                                //  when the same command has been arrived

// animation timing
uint32_t lastStateUpdate = 0;
static uint32_t modeStartTime = 0;

/////
//  static function(s)
/////

//  Handle the current command. The command can be [OFF, ON, BLINK, BREATH].
static void _handle_command(uint16_t command) {
    switch(command) {
      case CMD_OFF: {
        ledMode = MODE_OFF;
        toggle_led(/*turn_on: */ false);
        modeStartTime = millis();
        break;
      } case CMD_ON: {
        ledMode = MODE_ON;
        toggle_led(/*turn_on: */ true);
        modeStartTime = millis();
        break;
      } case CMD_BLINK: {
        if (ledMode == MODE_ON || ledMode == MODE_BREATH) {
          ledMode = MODE_BLINK;
          modeStartTime = millis();
        }

        break;
      } case CMD_BREATH: {
        if (ledMode == MODE_ON || ledMode == MODE_BLINK) {
          ledMode = MODE_BREATH;
          modeStartTime = millis();
        }

        break;
      } default:
        break;
    }
}

/////
//  public functions
/////

void toggle_led(bool turn_on) {
  if (turn_on) {
    analogWrite(LED_PIN, 255);
  } else {
    analogWrite(LED_PIN, 0);
  }
}

void processing_ir_signal() {
    if (!IrReceiver.decode()) {
        return;
    }

    //  get the last command and also IR flags
    const uint16_t command = IrReceiver.decodedIRData.command;
    const uint8_t flags   = IrReceiver.decodedIRData.flags;

    IrReceiver.resume();

    //  ignore the workflow, when when a button has been pressed for a certain time amount
    if (flags & IRDATA_FLAGS_IS_REPEAT) {
        return;
    }

    //  also ignore the identical command
    if (command == lastAcceptedCommand) {
        return;
    }

    lastAcceptedCommand = command;                    //  remember the last used command
    _handle_command(command);
}

void update_led(void) {
    const uint32_t now = millis();

    if (now - lastStateUpdate < STATE_UPDATE_MS) {                      //  keep the animation update independent of IR command processing
       return;
    }

    lastStateUpdate = now;

    switch (ledMode) {
        case MODE_OFF:
            toggle_led(/*turn_on: */ false);
            break;

        case MODE_ON:
            toggle_led(/*turn_on: */ true);
            break;

        case MODE_BLINK: {
            const uint32_t elapsed = now - modeStartTime;
            const bool ledOn = (elapsed % BLINK_PERIOD_MS) < (BLINK_PERIOD_MS / 2);
            analogWrite(LED_PIN, ledOn ? 255 : 0);
            break;
        }

        case MODE_BREATH: {
            const uint32_t elapsed = now - modeStartTime;
            const uint32_t position = elapsed % BREATH_PERIOD_MS;

            uint8_t brightness;

            if (position < (BREATH_PERIOD_MS / 2)) {
                brightness = map(
                    position,
                    0,
                    BREATH_PERIOD_MS / 2,
                    0,
                    255
                );
            } else {
                brightness = map(
                    position,
                    BREATH_PERIOD_MS / 2,
                    BREATH_PERIOD_MS,
                    255,
                    0
                );
            }

            analogWrite(LED_PIN, brightness);
            break;
        }
    }
}