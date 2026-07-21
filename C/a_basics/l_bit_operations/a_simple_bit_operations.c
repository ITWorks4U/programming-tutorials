/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <stdio.h>
#include <stdlib.h>
#define NBR_OF_ELEMENTS 10

void basics_bitoperations(void) {
    /*
    * size of an integer value: 4 bytes
    * maximum number of an integer value (in C):     2,147,483,647
    * binary representation:                         11111111 11111111 11111111 11111111
    *
    * What operators are in use?
    * & => bitwise and
    * | => bitwise or
    * ~ => bitwise not
    * ^ => bitwise xor
    *
    * Don't mix bitwise and or bitwise or with && or ||, because these are logical operators.
    */

    int a = 42;                                 // 00000000 00101010
    int b = 9001;                               // 00100011 00101001

    printf("%d\n", a & b);                      // a AND b => 40
    printf("%d\n", a | b);                      // a OR b => 9003
    printf("%d\n", a ^ b);                      // a XOR b => 8963 | NOTE: if a XOR a or b XOR b is in use, 0 always returns
    printf("%d\n", ~a);                         // NOT a => (0->1)0101010 => -43
    printf("%d\n", ~a & b);                     // NOT a AND b => 8961
    printf("%d\n", ~(a & b));                   // NOT (a AND b) => NAND(a, b) => -41
    printf("%d\n", ~(a & ~b));                  // NOT (a AND NOT b) => NOT a OR b => -3
    printf("%d\n", ~(a | b));                   // NOT a OR b => NOR(a, b) => -9004
    printf("%d\n", ~(a ^ b));                   // NOT a XOR b => NXOR(a, b) => -8964
}

void create_inverted_mask(void) {
    //  assuming, you want to create an inverted
    //  bitmask, however, this comes with a twist...
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //  illegal in C/C++
    // int inverted[] = ~data;
    // int inverted[] = ~*data;

    // correct "solution"
    int inverted[NBR_OF_ELEMENTS];

    for(int i = 0; i < NBR_OF_ELEMENTS; i++) {
        inverted[i] = ~data[i];                  // store each inverted number element for element
        printf("%d (0x%X) <=> %d (0x%X)\n", data[i], data[i], inverted[i], inverted[i]);
    }
}

int main(void) {
    basics_bitoperations();
    create_inverted_mask();

    return EXIT_SUCCESS;
}