#include <stdio.h>
#include <stdlib.h>

typedef struct {
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
    Point p = {1,2};
    #endif

    #ifdef WAY_THREE
    //  NOTE:   For a C++ compiler the members must be in the correct order to work with,
    //          otherwise an error on compile time appears.
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