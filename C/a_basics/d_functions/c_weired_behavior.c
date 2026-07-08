#include <stdio.h>
#include <stdlib.h>

/*
* Usually, a function has a clean definition, however, in C this doesn't
* always count. The function "any_function" usually don't accept any
* arguments. In languages, like C++, Java, C#, Python, ..., an error on
* compile or runtime appears, when this function is going to call with
* any amount of any arguments. However, in C this is legal, because the
* function behavior in C is different.
*
* This will be more described in section c:e_strange_function_behavior.
*
* NOTE: It may happen, that a C compiler may refuse to compile this
*       source code.
*/

void any_function() {
    printf("This function has been called.\n");
}

int main(void) {
    any_function();                     // without arguments
    any_function(1,2,3,4,5);            // any amount of numerical arguments
    any_function("hello", "world");     // any amount of C-strings
    any_function(NULL);                 // pointer(s)
    any_function("1,2,3", 4,5,6, NULL); // any anount of any arguments

    return EXIT_SUCCESS;
}