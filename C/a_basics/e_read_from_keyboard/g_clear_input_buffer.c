#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH   32

/*
* It doesn't matter, which input function you're using, when you don't clear
* the input buffer with any characters left. This input buffer causes a
* wrong behavior if you're using a next input function. The buffer with n characters
* left has a higher priority instead of your keyboard, a file, ...
*
* Perhaps you have heared to use a function, like:
* fflush(stdin);
*
* This, however, does NOT clear your input buffer. This is only in use
* for output buffer.
*
* To clear the input buffer, use this syntax:
* int c;
* while ((c = getchar()) != '\n' && c != EOF);
*
* NOTE: This input clear instruction is recommended for C only.
*       C++ may use this, too, however, there's no clean behavior.
*       Furthermore C++ handles the input buffer clean sequence in an another way.
*/

void remove_newline_if_existing(char *input_buffer) {
    char *ptr = strrchr(input_buffer, '\n');

    if (ptr) {                                                 // if "ptr" is not NULL, then the input buffer contains '\n'
        *ptr = '\0';                                           // this character will be replaced with '\0'
    }
}

void clear_input_buffer(void) {
    // this will clear the input buffer left
    // NOTES:
    //      it may happen, that the enter key must be pressed twice
    //      This works only in C! In C++ this leads to an undefined behavior!
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    char word[BUFFER_LENGTH];                                  // holds up to n-1 characters + one null termination character ('\0')
    char single_sign = 'C';                                    // holds a single character only
    char fixed_word[] = "A given string with a fixed length";  // fixed expression

    // assuming, you may input more than 31 characters
    printf("enter something for word: ");
    fgets(word, sizeof(word) - 1, stdin);

    remove_newline_if_existing(word);
    clear_input_buffer();

    printf("do it again: ");
    fgets(word, sizeof(word) - 1, stdin);
    remove_newline_if_existing(word);
    clear_input_buffer();

    /* see, what happens: */
    printf("your input was: %s\n", word);
    printf("signle_sign contains...? \"%c\"\n", single_sign);
    printf("fixed word: %s\n", fixed_word);

    return EXIT_SUCCESS;
}