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

// contains functions for C-strings
#include <string.h>

#define BUFFER_LENGTH   50

int main(void) {
    char word[BUFFER_LENGTH];
    char fixed_expression[] = "A fixed expression for our purpose.";

    /*
    * There're two ways to determine the length of a string, whereas it's not
    * a good choice to use them those at every time:
    *
    * 1) strlen()  => size_t strlen(const char s*);
    *   -   counts the number of characters until the first null termination character
    *       '\0' appears
    *
    * 2) sizeof()  => sizeof has a different definition, depending on the running system
    *   -   determines the size of a C-string, as well as, other fields, but with
    *       the twist, that this is not everytime a good choice
    */

    // NOTE:    Windows:    %llu -OR- %u (sometimes %llu MAY work, but that returns garbage)
    //          Linux:      %lu
    printf("word contains %llu characters\n", strlen(word));
    printf("word contains %llu characters\n", sizeof(word));

    // What about fixed_expression? Surprised?
    printf("fixed_expression contains %llu characters\n", strlen(fixed_expression));
    printf("fixed_expression contains %llu characters\n", sizeof(fixed_expression));

    // in summary:
    // strlen(): counts all characters until the first null termination character \0 has been detected
    // sizeof(): counts the maximum number of possible storage characters with null termination character
    //
    // in summary, part 2:
    // since >>word<< contains up to 50 characters and this is not initialized, it contains garbage and
    // your >>word<< may result any content

    return EXIT_SUCCESS;
}