#   Using a potentiometer

-   this is a scalable resistor, which is almost everywhere included
-   the remaining voltage doesn't return a value of "0" or "1", because this is **not** a digital value. This is an *analog* value instead

##  ranges

-   depending on which microcontroller you're using, usually a value between `[0..1023] (2^10)` returns
    -   for an ESP32 this value comes with a range of `[0..4095] (2^12)`

>   **NOTE**:   *If you're using a microcontroller, like an **ESP32**, which comes with an operation voltage of **3.3V**, you should **NOT** use 5V or more for any GPIO pin, otherwise this leads into any undefined behavior and also may damage your microcontroller and possible physically connected devices!*

### Where to find them?
-   physical sound voulume setting, e. g. soundbox, headset, radio, ...