#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    // -----------
    // while loop (runs, while a certain condition is given)
    // in contrast to a for loop make sure, that the condition in the head
    // will false at any time to leave the loop
    // -----------
    int ctr = 0;
    while(ctr < 10) {
        ctr++;                                      //  required, otherwise the loop never ends
        printf("%d\n", ctr);
    }

    while (ctr != 0) {
        ctr--;

        if (ctr % 2 == 0) {                         //  check, if an even number has been reached, then skip
            continue;                               //  the remaining instructions for this step only
        }

        printf("%d\n", ctr);
    }

    /*  pitfall: never reach the next step  */
    /*
    ctr = 9;
    while(ctr != 0) {
        if (ctr % 2 == 0) {                         //  since any even number has been detected, the remaining
            continue;                               //  instructions are going to skip, however, while ctr is
        }                                           //  is still an even number, this loop never ends

        printf("%d\n", ctr);
        ctr--;
    }
    */

    ///
    //  infinite loops
    ///

    /* infinite loop in C-style until stdbool was available */
    while(1) {
        break;
    }

    /* infinite loop with a boolean expression */
    while(true) {
        break;
    }

    /* Also an infinite loop, however, THIS can't be left in a usual way! */
    // while(true);

    return EXIT_SUCCESS;
}