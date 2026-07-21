/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte_t;

int main(void) {
    // Bit shifting allows you to move the bits by n positions to the left or right.
    // Shift to the left makes the number bigger, where right shift makes the number smaller.

    int a = 42;

    // 42 becomes 336
    printf("%d\n", a << 3);

    // 42 becomes 5
    printf("%d\n", a >> 3);



    // sometimes this can also be data to handle:
    byte_t info[] = {0xff, 0xA0, 0x45, 0xFF, 0x55, 0xAA};         // {255, 160, 69, 255, 85, 170}

    int data_0 = (info[0] << 8 | info[1]);                        // 65,440
    int data_1 = (info[2] << 8 | info[3]);                        // 17,919
    int data_2 = ((info[4] << 8 | info[5]) & 0x400) >> 3;         // 128

    printf("data_0 = %d\n", data_0);
    printf("data_1 = %d\n", data_1);
    printf("data_2 = %d\n", data_2);

    return EXIT_SUCCESS;
}