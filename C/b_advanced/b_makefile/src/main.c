#include <stdio.h>
#include <stdlib.h>
#include "math_functions.h"

int main(void) {
    int a = 100;
    int b = 20;

    printf(
        "add: %d <=> sub: %d <=> multiply: %d <=> divide: %d <=> modulo: %d <=> stuff %2.2lf\n",
        add(a,b), subtract(a,b), multiply(a,b), divide(a,b), modulo(a,b), calculate_suff(a, b)
    );

    return EXIT_SUCCESS;
}