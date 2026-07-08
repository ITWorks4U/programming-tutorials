#include <stdio.h>
#include <stdlib.h>

/*
* Unlike atoi(), atol(), ... use strtol(), strtod(), ... functions instead.
* strtol() := string to long,
* strtod() := string to double, ...
*
* With those functions you're able to handle any input left, which wasn't able to
* convert to the correct data type. Not a clean way to do this, but at this moment
* this is much better than the completly deprecated functions, like atoi(), atol(), ...
*/

int main(void) {
    char input[] = "1001001";
    char *endpointer = NULL;

    /*
    * long strtol(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base);
    * __nptr     :=   source to read and trying to convert to a long value
    * __endptr   :=   if given, any other character, which doesn't fit to long data type can be stored elsewhere; NULL: discard the input left
    * __base     :=   determine in which kind of format the number is going to read; 0: decimal, 2: bindary, 8: octal, 10: decimal, 16: hexadecimal
    */

    long number_decimal = strtol(input, NULL, 10);
    printf("decimal number: %ld\n", number_decimal);

    long number_binary = strtol(input, NULL, 2);
    printf("binary(?) number: %ld\n", number_binary);

    long number_octal = strtol(input, NULL, 8);
    printf("octal number: %ld\n", number_octal);

    // now, endpointer is also going to use
    long number_hexadecimal = strtol(input, &endpointer, 16);
    printf("hexadecimal number: %ld\n", number_hexadecimal);

    //////////////////////////
    printf("by the way, endpointer contains: %s\n", endpointer);

    return EXIT_SUCCESS;
}