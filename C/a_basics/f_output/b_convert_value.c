#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 123;

    printf("number (decimal): %d\n", number);
    printf("number (octal): %o\n", number);
    printf("number (hexadecimal): %x\n", number);
    printf("number (address): %p\n", &number);
    printf("number (unsigned): %u\n", number);

    printf("percent character: %%\n");

    return EXIT_SUCCESS;
}