/*
* Interrupts may appear anytime, anywhere with any reason.
* Your job is to detect such interrupts and also to figure
* out, what happened and what to do.
*
* NOTE: Depending on which microcontroller you're using, the pins, which are able to
*       handle an interrupt, are different. An Arduino (UNO) uses pins 2 and 3.
*       An ESP32 may use almost any pin, except 3.3V, VIN, EN, GND, VP, VN and also pins of 30+.
*       Take a look to the certain guide for your device.
*
* You SHOULD NOT do:
* - heavy instructions inside the ISR handler      => the ISR shall be as shart as possible
* - using a serial communication                   => this may crash the microcontroller or cause any side effect(s)
* - delay(s) with delay() or delayMicroseconds()   => this pauses your system with a certain wasting time
*
* Why you shouldn't use delay() / delayMicroseconds()
* outside of an ISR, like loop():
* - this pauses your system with a certain wasting time
* - within this timespan an incoming interrupt is unable to handle
*
* attaching an interrupt pin:      void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
* detaching an interrupt pin:      void detachInterrupt(uint8_t interruptNum);
* suppress any interrupts:         noInterrupts() => this is a macro function, which is identical to cli()
* reanable interrupts:             interrupts()   => this is a macro function, which is identical to sei()
*
* NOTE: Whenever an interrupt pin is suppressed, this suppression will be vanished, whenever
*       interrupts() has been called. Within this code or time span, an incoming interrupt
*       trough the certain interrupt pin is unable to handle.
*/

#define PIN_BUTTON       13                                             // NOTE: for an Arduino (UNO) only pin 2 or 3 is able to use
#define SERIAL_BAUD_RATE 9600

volatile bool isr_trigger = false;                                      // trigger point, when an interrupt has been detected
                                                                        // NOTE: To ensure, that this variable can be handled
                                                                        //       for an ISR (Interrupt Service Routine), the
                                                                        //       keyword volatile must be used. This is a "promise"
                                                                        //       for the compiler, that this variable can be changed
                                                                        //       anytime during the runtime and this is also
                                                                        //       be able to being handled with a higher "priority".

void isr_handler_function(void) {                                       // your ISR handler function, when a certain interrupt has been detected
    isr_trigger = false;                                                // NOTE: Keep your ISR as short as possible, because each interrupt
}                                                                       //       also pauses your other processes.

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(PIN_BUTTON, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), isr_trigger, RISING);

    // register a new interrupt handler, where:
    // - the pin, which may trigger an interrupt anytime for any reason
    //   - NOTE: this shall be covered with digitalPinToInterrupt() to avoid possible nasty side effects
    // - any function of type void (*)() => void function without any arguments
    // - a mode, which may trigger an interrupt, like: LOW, RISING, FALLING, CHANGE (typical cases)
}

void loop() {
    static int ctr_loop = 0;

    if (isr_trigger) {                                                  // whenever this interrupt has been detected, usually this will be reset (automatically or by user action with an UI)
        isr_trigger = false;                                            // to avoid to retrigger this handling sequence over and over again

        ctr_loop++;
    }

    String s = "ctr_loop = " + String(ctr_loop);
    Serial.println(s);
}