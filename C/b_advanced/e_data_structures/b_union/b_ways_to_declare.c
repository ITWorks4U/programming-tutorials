#include <stdio.h>
#include <stdlib.h>

typedef union {
    int x;
    int y;
}Point;

int main(void) {
    #ifdef WAY_ONE
    Point p;
    p.x = 1;
    p.y = 2;
    #endif

    #ifdef WAY_TWO
    //  NOTE:   In C++ this is illegal, but in C this works.
    //  NOTE:   With -pendantic-errors a C compiler also refuses to build the application
    Point p = {1,2};
    #endif

    #ifdef WAY_THREE
    //  NOTE:   With a C++ compiler this can't be build anyway. Maybe you'll receive an information
    //          to use -std=c++20 or std=gnu++20, however, with these flags you'll receive a new
    //          error, that too many initializers are existing here.
    Point p = {
        .x = 1,
        .y = 2
    };
    #endif

    #if defined(WAY_ONE) || defined(WAY_TWO) || defined(WAY_THREE)
    printf("{%d, %d}\n", p.x, p.y);
    #endif

    return EXIT_SUCCESS;
}