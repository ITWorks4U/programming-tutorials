#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int value_a = 100;
    int value_b = 200;

    /*
    * logical AND => &&
    * logical OR => ||
    *
    * Don't mix this with a single '&' or '|'.
    * These are bitwise operators and those have
    * a different purpose. Take a look to section: "l:bit_operators"
    */

    if (value_a >= 100 && value_b >= 100) {         //  logic AND
        puts("This statement is \"true\"");
    }

    // identical to condition check above
    if (value_a && value_b) {
        puts("This statement is \"true\"");
    }

    if (value_a >= 200 || value_b >= 200) {         //  logic OR
        puts("This statement is \"true\"");
    }

    if (!(value_a >= 100 || value_b >= 200)) {      //  logic NOT
        /* !(value_a || value_b)
        *  => !value_a && !value_b
        */
       puts("Have you expected to see this text?");
    } else {
        puts("You haven't seen anything.");
    }

    return EXIT_SUCCESS;
}