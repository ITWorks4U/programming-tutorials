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
*
* advantage: you can handle different variables at the same time
* disadvantage: the order of words must be identical to the scanned formats
*/

// global expressions
char word[BUFFER_LENGTH];                                      // holds up to n-1 characters + one null termination character ('\0')
char single_sign = 'C';                                        // holds a single character only
char fixed_word[] = "A given string with a fixed length";      // fixed expression

void use_scanf(void) {
    printf("enter any word: ");
    scanf("%s", word);                                         // "scan" your keyboard input, but with a nasty twist...
    printf("input was: %s\n", word);                           // What happens, if multiple words has been typed in?
}

void read_integer(void) {
    // stores an expected number from keyboard => Undefined behavior, if "number" may contain any other
    // value instead of an integer value!
    int number;

    // reading from keyboard
    printf("enter a number: ");

    // NOTE: for variables the address of the variable is required (not for a C-string)
    //       otherwise the application crashes
    scanf("%d", &number);
    printf("number: %d\n", number);
}

void unnecessary_scanf_usage(void) {
    // sometimes the scanf() function for a certain C-string
    // comes with a maximal number of characters to handle
    // => This don't do the expected behavior. You also can exceed this limit.

    printf("enter any word: ");
    scanf("%31s", word);
    printf("word: %s\n", word);
}

void no_buffer_overflow_protection(void) {
    // Similar to gets(): The scanf() function doesn't care about a buffer overflow protection.
    // So what happens, if more than 32 characters are in use? Maybe you see nothing bad, but
    // you may also see an error. => Undefined behavior!

    printf("enter anything: ");
    scanf("%s", word);
    printf("word: %s\n", word);
}

int main(void) {
    use_scanf();
    read_integer();
    unnecessary_scanf_usage();
    no_buffer_overflow_protection();

    printf("signle_sign contains...? \"%c\"\n", single_sign);
    printf("fixed word: %s\n", fixed_word);

    return EXIT_SUCCESS;
}