#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>                                          //  offers special functions for unsigned char

#define PLACEHOLDER "=========="
typedef unsigned char uchar_t;

void compare_signend_with_unsigned_chars(void) {
    uchar_t word_u[] = "Hello World!";
    char word_s[] = "Hello World!";

    #ifdef WRONG_HANDLING
    if (strcmp(word_s, word_u) == 0) {                      //  prints a warning on compile time, because strcmp expects "const char *" twice
        puts("Both strings are idenitcal.");                //  maybe this result is going to print on your console...
    } else {
        puts("Both strings are different.");
    }
    #endif

    //  correct handling
    if (strcmp(word_s, (const char *)word_u) == 0) {        //  word_u must be converted into: "const char *" (char * works, too, but may also lead into an undefined behavior)
        puts("Both strings are idenitcal.");
    } else {
        puts("Both strings are different.");
    }
}

void work_with_uchar_t(void) {
    uchar_t signs[] = {'A', 'j', 0xAB, '\t', 49};           //  alpha, lower, ½, \t, 1
    size_t nbr_elements = sizeof(signs) / sizeof(signs[0]);

    printf("%s\n", PLACEHOLDER);
    for(size_t i = 0; i < nbr_elements; i++) {
        printf("using sign %llu: %c...\n\n", i, signs[i]);

        printf(
            "> Is alpha? %s | Is upper? %s | Is lower? %s | Is this a digit? %s | to lower: %c | to upper: %c | to ASCII: %c\n",
            (isalpha(signs[i]) ? "yes" : "no"), (isupper(signs[i]) ? "yes" : "no"), (islower(signs[i]) ? "yes" : "no"),
            (isdigit(signs[i]) ? "yes" : "no"), tolower(signs[i]), toupper(signs[i]), toascii(signs[i])
        );

        printf("%s\n", PLACEHOLDER);
    }
}

int main(void) {
    compare_signend_with_unsigned_chars();
    work_with_uchar_t();

    return EXIT_SUCCESS;
}