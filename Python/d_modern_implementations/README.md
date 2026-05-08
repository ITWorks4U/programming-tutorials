#   contains...

0.  hardware scan
    -   figure out what is inside of your machine
1.  using a library written in C/C++
    -   delegate heavy time consuming instructions into raw C/C++ to speed up your code rapidly
        -   example: use the bubble sort algorithm (O(n²)) with 250,000 random numbers
            -   raw python: up to **1 hour**
            -   with C/C++: up to **3 minutes**
2.  cython management
    -   similar to **1.**, but delegate a raw python instruction into a C code and also speed up your code rapidly
3.  performance boost
    -   figure out what slows down your python script (without Cython or customized written C/C++ libraries)
4.  socket communication
    -   communicate between 2 or more different systems
        -   no matter which operating system (**OS**) is in use
5.  serial communication (**UART**)
    -   send and receive messages to a different system
        -   example: control **leds** of an **ESP32** microcontroller

>   **NOTE**: Those commands can be handled as C++ strings, C-strings, hashed expressions, as well as, raw byte streams.
>>  In this sample the commands are strings, which can be handled by C++ strings or C-strings.

6.
7.
8.
9.