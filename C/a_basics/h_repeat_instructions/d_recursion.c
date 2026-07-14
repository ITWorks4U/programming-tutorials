#include <stdio.h>
#include <stdlib.h>

// -----------
// Allows to run the function again and again and again... and... again.
// Runs often slower than a loop instruction, but has less content, however,
// you may have trouble when an error occurrs, because it's hard to find a logical error.
//
// By the way by using a recursion your RAM and CPU usage are also affected!
// -----------
int recursion_function(int start_counter) {
    if (start_counter >= 100) {
        return start_counter;
    }

    start_counter++;
    return recursion_function(start_counter);
}

///
//  simple mathematical operations with recursion
///

int calculate_gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    if (a == b) {
        return a;
    }

    if (a > b) {
        return calculate_gcd(a-b, b);
    }

    return calculate_gcd(a, b-a);
}

/*
* looks quite simple, however, by using numbers 50+ this will take a very, very, VERY long time
* unless, you're using a buffer for already calculated numbers instead => see: chapter c:i_runtime_optimizations
*/
int fibonacci(int n) {
    switch(n) {
        case 0:
            return 0;
        case 1:
            return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void) {
    printf("\"recursion_function\" has been called %d times...\n", recursion_function(/*start_counter: */0));
    printf("F(40) = %d\n", fibonacci(40));
    printf("GCD of 14, 78 = %d\n", calculate_gcd(14, 78));

    return EXIT_SUCCESS;
}