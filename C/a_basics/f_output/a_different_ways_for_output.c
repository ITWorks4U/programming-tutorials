#include <stdio.h>
#include <stdlib.h>

// required for strerror() function
#include <string.h>

int main(void) {
    /* prints anything to stdout; doesn't handle empty words; without \n the next output is on the same line */
    printf("\n");

    /* prints anything to stdout; unlike to printf() no formatted output can be handled here; adds a newline by default */
    puts("");

    /* works like printf(), whereas the destination stream can be modified */
    fprintf(stdout, "");

    /* perror allows you to give a detailed error message on any runtime error */
    perror("using perror");

    /* prints an error message by given error number => 13: "permission denied" */
    // NOTE: Not every system knows the strerror() function without using
    //       the string.h header file.
    fprintf(stderr, "using fprintf: %s\n", strerror(13));

    /* atcs like puts(), whereas the destination stream can be modified */
    fputs("", stdout);

    ///
    //  single character output to stdout or to a specific output stream
    ///

    /* prints a single character to given stream */
    putc('?', stdout);

    /* almost identical to putc(); has more secure handling for buffer storage */
    fputc('?', stdout);

    /* prints a single character to stdout by default */
    putchar('?');

	return EXIT_SUCCESS;
}