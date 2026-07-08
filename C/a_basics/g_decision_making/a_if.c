#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    /*
    * Usually, in C/C++ every condition check returns 0 for
    * false, every other value is true! Typically the number
    * range {0, 1} is used only.
    */
    bool condition = true;

    // short form
    if (condition) {
        puts("This statement is \"true\".");
    }

    // long form, and only if required
    if (condition == true) {
        puts("This statement is still \"true\".");
    }

    // What happens, if an integer value is in use instead?
    int value_a = -100;

    if (value_a) {
        puts("This statement is \"true\"");
    }

    return EXIT_SUCCESS;
}