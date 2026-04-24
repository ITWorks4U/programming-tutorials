#   Detecing and handling interrupts

-   interrupts may appear **anytime**, **anywhere** with **any reason**
-   your job is to detect such interrupts and also to figure out, what happened and what to do
-   interrupts are similar to exceptions, where these two events are **not** the same
-   for an incoming interrupt an interrupt service routine (**ISR**) must be used
    -   depends on you which handler function shall be used

>   **NOTE**: Depending on which microcontroller you're using, the pins, which are able to handle an interrupt, are different. An Arduino (UNO) uses pins 2 and 3. An ESP32 may use almost any pin, except 3.3V, VIN, EN, GND, VP, VN and also pins of 30+. Take a look to the certain guide for your device.

##  pitfalls with interrupts

| mistake | reason |
| - | - |
| heavy instructions inside the ISR handler | the ISR shall be as shart as possible |
| using a serial communication | this may crash the microcontroller or cause any side effect(s) |
| delay(s) with `delay()` or `delayMicroseconds()` | this pauses your system with a certain wasting time

##  ISR
-   interrupt service routine
-   any void function, which takes no arguments:
    -   `void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);`

| argument | description | additional informations |
| - | - | - |
| interruptNum | the pin, which shall be able to trigger for any interrupt | cover this with `digitalPinToInterrupt(nbr)` to avoid side effects |
| (*userFunc)(void) | any void function, which doesn't take any arguments| - | 
| mode | a mode, which triggers an interrupt | can be: LOW, CHANGE, RISING, FALLING |

```
void isr_handler_function(void) {
    // do something here
}
```

>   **NOTE**: On an ESP32, this attribute can be added: **IRAM_ATTR**
>> This allows to move such ISR functions into a faster RAM sector.


##  Why you shouldn't use delay() / delayMicroseconds()
-   outside of an ISR, like loop():
    -   this pauses your system with a certain wasting time
    -   within this timespan an incoming interrupt is unable to handle

### functions for interrupts

| function | description | additional informations |
| - | - | - |
| `void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);` | attaching an interrupt pin | - |
| `void detachInterrupt(uint8_t interruptNum);` | detaching an interrupt pin | - |
| `noInterrupts()` | suppress any interrupts | this is a macro function, which is identical to `cli()` | 
| `interrupts()` | reanable interrupts | this is a macro function, which is identical to `sei()` |


>   **NOTE**: Whenever an interrupt pin is suppressed, this suppression will be vanished, whenever `interrupts()` has been called. Within this code or time span, an incoming interrupt trough the certain interrupt pin is **unable** to handle.