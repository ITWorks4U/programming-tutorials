#include <stdio.h>
#include <stdlib.h>

#ifdef USE_EMPTY_STRUCT
// structs may contain nothing

// NOTE:    Usually, a C structure must not be empty,
//          because this is illegal in C, but works for
//          C++. However, depending on which compiler flags
//          you're using, this determines, if your application
//          can be built or not.

//          ISO C (-pedantic-errors)    =>  not allowed
//          GNU C (regular way)         =>  allowed
//          C++                         =>  allowed
struct Empty {};
#endif

int main(void) {

    //  NOTE:   compile with -DUSE_EMPTY_STRUCT

    #ifdef USE_EMPTY_STRUCT
    struct Empty e;

    #ifdef _WIN32
    printf("amount of bytes for \"e\": %llu\n", sizeof(e));
    printf("amount of bytes for \"e\": %llu\n", sizeof(struct Empty));
    #else
    printf("amount of bytes for \"e\": %lu\n", sizeof(e));
    printf("amount of bytes for \"e\": %lu\n", sizeof(struct Empty));
    #endif
    #endif

    return EXIT_SUCCESS;
}