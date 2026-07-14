/*
* In contrast to a direct recursion an indirect recursion
* needs at least two functions, where function 1 calls
* function 2 and vice versa.
*
*/

#include <stdio.h>
#include <stdlib.h>

// internal counter
int counter = 0;

// function prototypes
int function_a(int n);
int function_b(int n);

int main(void) {
    for(int i = 0; i < 100'000; i++) {      // 100'000 = 100,000 times
        counter = 0;
        printf("using %5d: this took %d steps to return %d...\n", i, counter, function_a(i));
    }

    return EXIT_SUCCESS;
}

/*
* What happens here and when does this indirect recursion stops?
* case 1: n == 10 (function a) and n returns (n = 10)
* case 2: n can be divided by 100 and n/4 returns (e. g. n = 100 => 25 returns)
*
* if the condition in function a is false, then function b with n*2 is called
* if the condition in function b is false, then function a with n-- (n = n - 1) is called
*
* How many steps would this take?
*
* init_value | steps
* -----------|-------
* 0          | 1
* 1          | 63
* 2          | 61
* 3          | 63
* 4          | 59
* 5          | 2
* 6          | 61
* 7          | 63
* 8          | 57
* 9          | 63
* ...        | ...
*/

int function_a(int n) {
    if (n == 10) {
        return n;
    }

    counter++;
    return function_b(n*2);
}

int function_b(int n) {
    if (n % 100 == 0) {
        return n/4;
    }

    counter++;
    return function_a(n--);
}