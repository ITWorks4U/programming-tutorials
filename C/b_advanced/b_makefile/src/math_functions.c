#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_functions.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    // What happens for b = 0? >:-)
    return a / b;
}

int modulo(int a, int b) {
    return a % b;
}

float calculate_suff(int range_1, int range_2) {
    return sqrtf((float) abs(range_1 - range_2) + 1) * tanhf(log2f(0.19F));
}