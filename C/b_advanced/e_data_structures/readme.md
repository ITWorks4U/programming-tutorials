#   Structures, Unions, Enumerations

-   allows you to store data (almost of any kind) into a storage "class" to work with
-   in C only `struct`, `union` and `enum` exists
    -   C++ also comes with `enum class`

## struct

-   storage holder for any kind of datatypes
-   each member has its own memory to work with
-   commonly used for any storage attempt
-   a struct can also hold its own functions, however, unlike to OOP languages, these comes with more complexity
    -   a function pointer is in use for C-structures

####    example
```
#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;

    //  function pointer reference for almost any function outside
    //  =>  must contain the integer datatype, followed by 2 arguments
    //      of struct Point itself
    int (*cross_product)(struct Point p, struct Point q);
};

int use_this_function_here(struct Point p, struct Point q) {
    return p.x * q.y - p.y * q.x;
}

int main(void) {
    //  "marriage" of both implementations
    struct Point p = {
        .x = 5,
        .y = -1
    };

    struct Point q = {
        .x = -4,
        .y = 7
    };

    p.cross_product = use_this_function_here;
    printf("p x q = %d\n", p.cross_product(p, q));

    return EXIT_SUCCESS;
}
```

## union
-   storage holder for any kind of datatypes
-   in contrast to a struct each member shares their memory with the biggest data type
    -   the last member, which has been modified, also modifies the other members in the union
-   often used for multiple member accesses, whereas on a timestamp only one member can really be used
    -   for embedded systems, e. g. Arduino, ESP32, ..., you're limited to rare memory, thus you will see the real purpose there

####    example
```
#include <Arduino.h>

#define SERIAL_BAUD_RATE        115200
#define PIN_TEMPERATURE_WATER   A0
#define PIN_AIR_SENSOR          A1
#define PIN_MOISTURE_SENSOR     A2
#define TIMEOUT_IN_MS           1000

union SensorContainer {
    int sens_water_temperature;
    int sens_air;
    int sens_moisture;
    
    //  other members
    
    //  NOTE:   It may also be possible to declare
    //          a function pointer reference into this
    //          union, however, this is hardly used and
    //          this may also leads to an undefined behavior.
};

static uint32_t now = 0;
static int sens_val = 0;

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    delay(TIMEOUT_IN_MS);
    
    pinMode(PIN_TEMPERATURE_WATER, INPUT);
    pinMode(PIN_AIR_SENSOR, INPUT);
    pinMode(PIN_MOISTURE_SENSOR, INPUT);
    
    union SensorContainer sc;
    uint32_t last_time_water_temperature = 0;
    uint32_t last_time_air = 0;
    uint32_t last_time_moisture = 0;
    
    while(1) {
        now = millis();
        
        //  each 3 seconds: check water temperature
        //  each 5 seconds: check air temperature
        //  each 7 seconds: check moisture value
        
        //  NOTE:   If a certain operation consumes too much time,
        //          then the next expected instruction may not be fired!
        
        if (now - last_time_water_temperature > TIMEOUT_IN_MS * 3) {
            last_time_water_temperature = now;
            sens_val = analogRead(PIN_TEMPERATURE_WATER);
            sc.sens_water_temperature = map(sens_val, 20, 357, -20, 127);
            
            //  any other certain operations here
        }
        
        if (now - last_time_air > TIMEOUT_IN_MS * 5) {
            last_time_air = now;
            sens_val = analogRead(PIN_AIR_SENSOR);
            sc.sens_air = map(sens_val, 0, 330, -130, 150);
            
            //  ...
        }
        
        if (now - last_time_moisture > TIMEOUT_IN_MS * 7) {
            last_time_moisture = now;
            sens_val = analogRead(PIN_MOISTURE_SENSOR);
            sc.sens_moisture = map(sens_val, 0, 1023, 0, 100);
            
            //  ...
        }
    }
}

void loop() {   /*  not in use here */  }
```

## enum
-   contains an enumeration of integers only
-   often used to represent a state
    -   logging
    -   system status
    -   ...

### Pitfalls with C-enumerations
-   multiple states in at least two different enumerations
    -   even when more than one enum exists, an another enumeration **must not** have an identical expression
    -   in contrast to C++, which comes with ```enum class``` there's possible to define multiple expressions
    -   in contrast to C++, you can do operations in C, which are invalid in C++

>   *fun fact:* *You can write a raw C code, which can be build with a C compiler, but not with a C++ compiler and vice versa.*

####    Runs with C, but not with C++

```
typedef enum {
    IDLE, READY, RUNNING, WAITING, TERMINATED, ERROR
} Status;

//  illegal for C++, but C can deal with it
for(Status s = IDLE; s <= ERROR; s++) {
    printf("s = %d\n", s);
}
```

####    Runs with C++, but not with C

```
//  illegal for C, but C++ can deal with it

typedef enum {
} Empty;

//  ...
```