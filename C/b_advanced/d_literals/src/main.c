/*
* Literals allows you to specify a value for a certain data type,
* which might be useful for a correct handling.
*
* Literals are often in use for numbers in macro definitions.
*/

#include <stdio.h>
#include <stdlib.h>
#include "literals.h"

void display_all_expressions(void) {
    for(int i = 0; i < NUMBER_OF_LITERALS; i++) {
        printf("EXPRESSION_%d: ", i);

        switch(i) {
            case 0:
                printf("%d\n", EXPRESSION_0);
                break;
            case 1:
                printf("%u\n", EXPRESSION_1);
                break;
            case 2:
                printf("%ld\n", EXPRESSION_2);
                break;
            case 3:
                printf("%lld\n", EXPRESSION_3);
                break;
            case 4:
                printf("%d\n", EXPRESSION_4);
                break;
            case 5:
                printf("%d\n", EXPRESSION_5);
                break;
            case 6:
                printf("%d\n", EXPRESSION_6);
                break;
            case 7:
                printf("%f\n", EXPRESSION_7);
                break;
            case 8:
                printf("%lf\n", EXPRESSION_8);
                break;
            case 9:
                printf("%c\n", EXPRESSION_9);
                break;
            case 10:
                printf("%s\n", EXPRESSION_10);
                break;
            case 11:
                //  NOTE:   It may happen, that this expression may be unable
                //          to display on the console.
                wprintf(L"%ls\n", EXPRESSION_11);
                break;
            default:
                continue;
        }
    }
}

int main(void) {
    display_all_expressions();

    return EXIT_SUCCESS;
}