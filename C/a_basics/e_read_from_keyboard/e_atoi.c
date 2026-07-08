#include <stdio.h>
#include <stdlib.h>

/*
* With atoi() (argument to integer), atol(), atof(), ... you can try to convert the given
* word to an integer, long, float, ... , however, these functions have no buffer overflow
* detection and mostly no error on compile time appears when a wrong format is in use.
*/

int main(void) {
    char input[] = "100200300 123abc def456";  // fixed expression

    // MAY be used, however, ...
    int number = atoi(input);
    printf("number = %d\n", number);

    // What may happen here?
    // Do you see a warning on compile time?
    // Do you see 100200300123456 in number?
    // => At this point it's not clear what may happen here!

    return EXIT_SUCCESS;
}