#include <stdio.h>
#include <stdlib.h>
#define BUFFER_LENGTH   32

/*
* With scanf() you're able to read any input from keyboard, however, you should
* know which input refers to which variable. By detecting a space bar the previously read text
* has been stopped. The text left is stored to the input buffer, which will be automatically
* used for the next input.
*
* So if you're using a text with two or more words, then this function doesn't handle your input well.
*
* By the way, almost every function, which reads from a file stream has not a clear
* limitation for the input buffer. Use your mind to figure out, when a buffer has
* reached its limit!
*/

int main(void) {
    char word[BUFFER_LENGTH];                                  // holds up to n-1 characters + one null termination character ('\0')
    char single_sign = 'C';                                    // holds a single character only
    char fixed_word[] = "A given string with a fixed length";  // fixed expression

    printf("enter any word: ");
    scanf("%s", word);                                         // "scan" your keyboard input, but with a nasty twist...
    printf("input was: %s\n", word);                           // What happens, if multiple words has been typed in?

    // stores an expected number from keyboard => Undefined behavior, if "number" may contain any other
    // value instead of an integer value!
    int number;

    // reading from keyboard
    printf("enter a number: ");

    // advantage: you can handle different variables at the same time
    // disadvantage: the order of words must be identical to the scanned formats
    scanf("%d", &number);

    // see, what happens:
    printf("number: %d\n", number);
    printf("signle_sign contains...? \"%c\"\n", single_sign);
    printf("fixed word: %s\n", fixed_word);

    return EXIT_SUCCESS;
}