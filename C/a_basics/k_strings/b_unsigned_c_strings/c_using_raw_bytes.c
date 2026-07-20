/*
* Unsigned characters are usually in use, when byte data needs to be stored or transfered,
* e. g. UART communication, raw byte data into a file, ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char byte_t;                                                       //  see: chapter b:l_your_own_datatype

struct storage {                                                                    //  see: chapter b:d_structures
    int control_unit_0;
    int control_unit_1;
    int factor_value;
    int temperature;
    int humidity;
    int pressure;
};

bool validate_message(byte_t *message, size_t message_length) {                     // see: chapter a:q_array_handling
    int checksum = 0;

    for(size_t i = 0; i < message_length; i++) {
        checksum ^= message[i];
    }

    return checksum == 0;
}

int main(void) {
    //  example:    received data by UART or else, which may also be handled
    //              with bit shift operations (see: chapter a:l_bit_operations)
    byte_t data[] = {0xff, 0xA0, 0x45, 0xFF, 0x55, 0xAA, 0x19, 0x46, 0x65, 0x20};   // {255, 160, 69, 255, 85, 170, 25, 70, 101, 32}
    size_t length = sizeof(data) / sizeof(data[0]);

    if (!validate_message(data, length)) {
        fprintf(stderr, "received message invalid\n");
        return EXIT_FAILURE;
    }

    struct storage s = {
        .control_unit_0 = (data[0] << 8 | data[1]),                                 // 65,440
        .control_unit_1 = (data[2] << 8 | data[3]),                                 // 17,919
        .factor_value = ((data[4] << 8 | data[5]) & 0x400) >> 3,                    // 128
        .temperature = data[6],                                                     // 25°C
        .humidity = data[7],                                                        // 70%
        .pressure = data[8]                                                         // 101 hPa
    };

    puts("received data:");
    printf(
        "unit 0: %d\n unit 1: %d\n factor: %d\n temperature: %d %cC\n humidity: %d%%\n pressure: %d hPa\n",
        s.control_unit_0, s.control_unit_1, s.factor_value, s.temperature, (char)248, s.humidity, s.pressure
    );

    return EXIT_SUCCESS;
}