#include <stdio.h>
#include <stdlib.h>

/*
* In C the boolean data type usually doesn't exist, however, you can
* either simulate a boolean determination by using integer values,
* where 0 means false, every other value means true, no matter is positive or negative.
*
* In stdbool.h true is defined as 1, whereas false is defined as 0.
*
* regular way:   int expression = 0   => leads to "false"
* custom way:    #define TRUE 1       => every "TRUE" statement leads to 1
* stdbool.h:     true / false         => leads to 1 / 0
*
*========================================
* way 1: library for C
* #include <stdbool.h>
*
* bool condition = true;
*========================================
* way 2: define customized boolean expressions
* #define BOOL  int         //  or: typedef int bool
* #define TRUE  1
* #define FALSE 0
*
* BOOL condition = TRUE
* ========================================
*
* way 3: using integers only
* int condition = 1;        //  true statement
* int wrong = 0;            //  false statement
* ========================================
*/

int main(void) {
    return EXIT_SUCCESS;
}