#include <stdio.h>
#include <stdlib.h>

// -------------
// Similar to structures with unions a function link can
// also be done, but those are rarely used.
// -------------
typedef union{

    //  NOTE:   only integer functions with two arguments of type int
    //          are allowed to link together

    int (*add)(int, int);
    int (*substact)(int, int);
    // ...
} Calculation;

// -------------
// only in use for additional functions,
// which are linked to a structure
// -------------
int add_numbers(int a, int b) {
    return a + b;
}

int subtract_numbers(int a, int b) {
    return a - b;
}

int main(void) {
    // -------------
    // using functions, which shall be refered to a certain
    // structure instead
    // -------------
    int x = 1;
    int y = 2;

    Calculation calc;
    calc.add = add_numbers;
    calc.substact = subtract_numbers;

    printf("%d + %d = %d\n", x, y, calc.add(x, y));
    printf("%d - %d = %d\n", x, y, calc.substact(x, y));

    #ifndef __cplusplus
    //  only available for C without `-pedantic-errors` flag
    Calculation calc2 = {
        add_numbers, subtract_numbers
    };
    printf("%d + %d = %d\n", x, y, calc2.add(x, y));
    printf("%d - %d = %d\n", x, y, calc2.substact(x, y));
    #endif
    // -------------

    return EXIT_SUCCESS;
}