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

    /* Won't work in C, unless pointers are in use. => See: chapter c:b_memory_management */
    // NOTE: The C compiler refuses to compile this program.
    // word = fixed_expression;

    // In C, and also C++, this can be used, but it's also NOT recommended,
    // because on runtime "word" contains any garbage or the application crashes.
    // *word = *fixed_expression;

    // this can be used, however, since >>word<< contains any garbage you don't
    // know, what word may also contain data after fully copying each character
    // from fixed_expression to word
    // for(size_t i = 0; i < strlen(fixed_expression); i++) {
    //     word[i] = fixed_expression[i];
    // }

    /*
    * copy a text to an another C-string; doesn't handle buffer overflow
    * char *strcpy(char *dest, const char *source);
    *
    * returns the memory address pointer for dest (rarely used)
    */

    //  NOTE:   Make sure, that the destination has enough free space, otherwise
    //          this leads into an unstable state, followed by application crash.
    strcpy(word, fixed_expression);

    /*
    * char *strncpy(char *dest, const char *source, size_t __n);
    * copies n characters from source to destination; doesn't handle buffer overflow
    * 
    * NOTE:     There's a huge difference between strlen and sizeof, as well as,
    *           which C-string will be used there!
    */
    strncpy(word, fixed_expression, strlen(fixed_expression));
    printf("word contains: %s\n", word);

    return EXIT_SUCCESS;
}