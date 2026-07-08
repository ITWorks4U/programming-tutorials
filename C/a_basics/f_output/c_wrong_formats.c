#include <stdio.h>
#include <stdlib.h>

int main() {
    /* trying to print an integer by using a different format */
    // 123,456,789
    int a = 123456789;

    printf("'a' as decimal value = %d\n", a);              // regular formatted output for an integer
    printf("'a' as octal value = %o\n", a);                // octal expression | %O won't work
    printf("'a' as hexadecimal value = %X\n", a);          // hexadecimal expression | %x prints 0x instead of OX
    printf("'a' as exponential value = %e\n", a);          // format into an exponentional value | won't correctly work for an integer
    printf("'a' as short value = %d\n", (short)a);         // transfer the integer data type into a short data type => short as a smaller range than an integer

    // %c can only display a visible character between 33 and 127!
    // 0 - 31: system command, like \0, \n, \b, ... 32: space
    printf("'a' as char value = %c\n", (char)a);           // the value 123,456,789 rotates 488,145 times (484,144.27058...) trough the ASCII table (-128..127)
                                                           // and refers to the specific character

    // printf("'a' as string value = %s\n", a);               // causes a segmentation fault => application crashes

    printf("'a' as long value = %ld\n", (long) a);         // transfer the integer data type into a long data type | you may get a warning on compile time
    printf("'a' as unsigned int value = %u\n", a);         // works correctly for an integer, since it's not declared as 'unsigned'
    printf("'a' as float value = %f\n", a);                // transfer the integer data type into a single floating point number | won't work correctly
    printf("'a' as double value = %lf\n", a);              // maybe the same result for a double floating point number
    printf("address of 'a': %p\n", &a);                    // return the address, where this integer has been placed during runtime
                                                           // strictly recommended: use & in front of the variable, otherwise a wrong address returns
                                                           // followed by an undefined behavior

    return EXIT_SUCCESS;
}