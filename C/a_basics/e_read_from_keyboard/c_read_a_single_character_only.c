#include <stdio.h>
#include <stdlib.h>

/*
* You're also able to read a single sign from keyboard by using one of
* these functions: getc(), fgetc(), getchar(), getch(). The single sign
* will be converted as an integer and can't be referenced to a C-string!
*
* NOTE: By hit enter the enter character (\n) will also be read, thus
*       by using a second input attempt, your application comes with
*       a strange behavior.
*
* By the way, almost every function, which reads from a file stream has not a clear
* limitation for the input buffer. Use your mind to figure out, when a buffer has
* reached its limit!
*/

int main(void) {
    char input;

    printf("enter a single character with getc(): ");
    input = getc(stdin);                                       // read the first detected character from keyboard (stdin) or input buffer
    printf("input: %c (%d)\n", (char)input, input);

    printf("again with fgetc(): ");
    input = fgetc(stdin);                                      // comes with a better handling, but does the same action like getc(stdin)
    printf("input: %c (%d)\n", (char)input, input);

    printf("and again with getchar(): ");
    input = getchar();                                         // read a single character from keyboard (stdin) or input buffer => stdin is set by default
    printf("input: %c (%d)\n", (char)input, input);

    // sometimes used on Windows and turbo C, if defined
    // getch();

    return EXIT_SUCCESS;
}