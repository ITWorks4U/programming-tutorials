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
    Point p = {
        .x = 1;
        .y = 2;
    };
    #endif

    #if defined(WAY_ONE) || defined(WAY_TWO) || defined(WAY_THREE)
    printf("{%d, %d}\n", p.x, p.y);
    #endif

    return EXIT_SUCCESS;
}