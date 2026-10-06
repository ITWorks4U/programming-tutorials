#include <stdio.h>
#include <stdlib.h>

// -------------
// this does not declare functions to a structure, but you can
// enumate those by using a pointer => this is the only way to
// add "methods" for C-structures
//
// can also be used for unions, but those are a rarely used
// -------------
typedef struct{

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

    Calculation calc2 = {
        add_numbers, subtract_numbers
    };
    printf("%d + %d = %d\n", x, y, calc2.add(x, y));
    printf("%d - %d = %d\n", x, y, calc2.substact(x, y));
    // -------------

    return EXIT_SUCCESS;
}