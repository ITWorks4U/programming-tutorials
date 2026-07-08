#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    bool condition = true;

    /*
    * An else block will always be used, if the condition
    * above didn't satisfy.
    */

    if (condition) {
        puts("This statement is \"true\".");
    } else {
        puts("This statement is \"false\".");
    }

    if (condition != true) {
        puts("This statement shall now be false, right?");
    } else {
        puts("This statement is still \"true\".");
    }

    int value_a = -100;

    if (value_a) {
        puts("This statement is \"true\"");
    } else {
        puts("This statement is \"false\"");
    }

    return EXIT_SUCCESS;
}