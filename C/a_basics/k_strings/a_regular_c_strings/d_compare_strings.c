/*
* Working with strings in C.
* It's difficult in contrast to other
* programming languages, because in C
* a string will be handled in a different way.
*
* It's not recommended to run this code under C++,
* because it may cause to crash the application!
*/

#include <stdio.h>
#include <stdlib.h>

// contains functions to work with for C-strings
#include <string.h>

// usually, on Windows the library <strings.h> is might not be available
// => this can be handled by macro condition checks => described in chapter b:b_macros
#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
// for strcasecmp() function
#include <strings.h>
#endif

#define BUFFER_LENGTH   50

int main(void) {
    char word[BUFFER_LENGTH];
    char fixed_expression[] = "A fixed expression for our purpose.";

    /*  May work for C, but that's not recommended! */
    if (word == fixed_expression) {
        puts("These C-Strings are different.");
    } else {
        puts("These C-Strings are equal.");
    }

    /*
    * comparing two C-strings to each other
    * int strcmp(char *s1, char *s2);
    *
    * returns:
    * <0     :=   s1 has on any position a smaller character than s2
    *  0     :=   s1 is equal to s2
    * >0     :=   s1 has on any position a higher character than s2
    *
    * int strncmp(char *s1, char *s2, size_t __n);
    * compares two C-strings up to n characters
    */

    // don't expect a useful result => since >>word<< looks like an "empty" string, this is wrong, because an uninitalized
    // variable, C-string, ... holds garbage on runtime, thus you don't really know what that variable
    // contains on runtime until assignment
    printf("%d\n", strcmp(word, fixed_expression));

    // ignore case formatting; result differs to above
    printf("%d\n", strcasecmp(word, fixed_expression));

    return EXIT_SUCCESS;
}