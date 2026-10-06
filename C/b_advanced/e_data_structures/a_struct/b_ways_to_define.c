#include <stdio.h>
#include <stdlib.h>

//  NOTE:   In contrast to OOP languages C-structures does not contain
//          methods, constructor, destructor. However, there's also a
//          way to implement this.

#ifdef WAY_ONE
//  normal way for structure definition
//  declaration: struct Coordinates point; point.x = 1; point.y = 2;
struct Coordinates {
    int x;
    int y;
};
#endif

#ifdef WAY_TWO
//  often used: "point" is automatically a reference to
//  this structure and this can access to its members
struct Coordinates {
    int x;
    int y;
}c;
#endif

#ifdef WAY_THREE
//  anonymous structure => no way to access to these members
//  Illegal for C++, but legal in C.
//  =>  In C an unnamed structure / union "only" a warning appears :D
struct {
    int x;
    int y;
};
#endif

#ifdef WAY_FOUR
//  also an anonymous structure, but "c" is defined and its members can be accessed
struct {
    int x;
    int y;
}c;
#endif

#ifdef WAY_FIVE
//  the modern way to define a C-structure, because you don't need the keyword struct
//  when you want to access to this structure; => Coordinates c; c.x = 1; c.y = 2;
typedef struct {
    int x;
    int y;
}Coordinates;
#endif

int main(void) {
    #ifdef WAY_ONE
    struct Coordinates c;
    c.x = 1;
    c.y = 2;
    #endif

    #ifdef WAY_TWO
    c.x = 1;
    c.y = 2;
    #endif

    #ifdef WAY_FOUR
    c.x = 1;
    c.y = 2;
    #endif

    #ifdef WAY_FIVE
    Coordinates c;
    c.x = 1;
    c.y = 2;
    #endif

    #if defined(WAY_ONE) || defined(WAY_TWO) || defined(WAY_FOUR) || defined(WAY_FIVE)
    printf("{%d, %d}\n", c.x, c.y);
    #endif

    return EXIT_SUCCESS;
}