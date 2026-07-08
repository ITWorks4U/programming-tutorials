#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH   32

/*
* With fgets() you're able to read any input from keyboard, however, it will
* be interpreted as a set of words only. So you have to convert the input
* to the correct format. On the other hand you are able to scan multiple
* words as a single word.
*
* fgets() will read a maximum number of characters depending on your given
* limit. Finally, a newline will be automatically added to the string.
*
* By the way, almost every function, which reads from a file stream has not a clear
* limitation for the input buffer. Use your mind to figure out, when a buffer has
* reached its limit!
*/

int main(void) {
    char word[BUFFER_LENGTH];                                   // holds up to n-1 characters + one null termination character ('\0')
    char single_sign = 'C';                                     // holds a single character only
    char fixed_word[] = "A given string with a fixed length";   // fixed expression

    printf("enter something: ");

    // read up to 31 characters to word from keyboard (stdin); remember: every
    // C-string MUST end with a null termination character, so it may also crash your
    // application or any other issue, if there's no free space left for a null termination character
    fgets(word, sizeof(word) - 1, stdin);

    //  "handle" a C-string after using fgets()
    //  the last character becomes \0
    word[strlen(word) - 1] = '\0';                              // NOTE: A null termination character must be added by your own.
                                                                //       Furthermore, replacing the last character with \0 may not work well each time

    /* see, what happens: */
    printf("your input was: %s\n", word);
    printf("signle_sign contains...? \"%c\"\n", single_sign);
    printf("fixed word: %s\n", fixed_word);

    return EXIT_SUCCESS;
}