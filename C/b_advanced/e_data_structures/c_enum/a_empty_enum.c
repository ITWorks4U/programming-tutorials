#include <stdio.h>
#include <stdlib.h>

#ifdef USE_EMPTY_ENUM && defined(__cplusplus)
//  An empty enum is illegal in C, but available in C++.
//  But this doesn't mean, that C++ is more prefered to
//  use C-enumerations.

enum Empty {};
#endif

int main(void) {
    #ifdef USE_EMPTY_ENUM && defined(__cplusplus)
    Empty e;

    #ifdef _WIN32
    printf("amount of bytes for \"e\": %llu\n", sizeof(e));
    printf("amount of bytes for \"e\": %llu\n", sizeof(enum Empty));
    #else
    printf("amount of bytes for \"e\": %lu\n", sizeof(e));
    printf("amount of bytes for \"e\": %lu\n", sizeof(enum Empty));
    #endif
    #endif

    return EXIT_SUCCESS;
}