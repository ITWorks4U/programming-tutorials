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
#include <string.h>

#define BUFFER_LENGTH   50

int main(void) {
    char word[BUFFER_LENGTH];
    char fixed_expression[] = "A fixed expression for our purpose.";

    /* Won't work in C! */
    // word += fixed_expression;

    // will be interpreted as an addition of two numbers, if this might
    // not throw an error during compile time
    // word = word + fixed_expression

    /*
    * concatenation: add a string to an another string; doesn't handle buffer overflow
    * char *strcat(char *destination, const char *source);
    *
    * char *strncat(char *destination, const char *source, size_t __n);
    * add n characters from source to destination; doesn't handle buffer overflow
    * 
    * NOTE:     Make sure, that the destination string has enough free space left,
    *           otherwise this leads into an unstable state.
    */
    memset(word, '\0', sizeof(word));
    strncat(word, fixed_expression, strlen(fixed_expression));
    printf("word contains: %s\n", word);

    return EXIT_SUCCESS;
}