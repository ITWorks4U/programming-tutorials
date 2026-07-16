/*
* Write anything to a file. This code snippet is supposed to use on
* C only. Of course, you can also use a C++ compiler, however, in general
* the behavior of C++ is sometimes different rather than C.
* This can also be in this source code.
*
* In that case if you want to use a C++ compiler this won't work here.
*/

// this preprocessor condition check is in use, if a C++ compiler
// is in use; => take a look to chapter b:b_macros for more details
//
// Since FILE *... is a (raw) pointer, this might be handled
// different in C++ rather than in C. => take a look for chapter c:b_memory_management for more details
#ifdef __cplusplus
#error "This source code is supposed to use with a C compiler only."
#else
#include <stdio.h>
#include <stdlib.h>

// alternatives:
#include <errno.h>
#include <string.h>

#define FILE_TO_USE     "test.txt"                  //  make sure you have the permissions to create that file on your running system

void write_into_a_file(void) {
    FILE *destination = fopen(FILE_TO_USE, "w");

    // destination may NULL in case of:
    //  - the path doesn't exist
    //  - insufficient permissions
    //  - path is a folder / directory
    //  - ...
    //
    // By the way, in C++ this will be handled in a different and more secured way, because
    // such kind of code may also result to memory leaks!

    if (!destination) {                             //  also works: if (destination == NULL) {...}
        // void perror(const char *error_message);
        // in case of an error perror uses the internal handled errno variable
        // to figure out, which error with its reason was caused
        //
        // mostly the function name itself is given to show up where the error
        // has been detected
        perror("fopen()");

        // alternative way: use errno variable (not recommended, because errno
        // can also be modified here; if you're using threads, then this is
        // a horrible decision making
        fprintf(stderr, "Error: %s\n", strerror(errno));

        return;
    }

    // now the file stream exists, we can write anything to that file
    char simple_text[] = "This is a simple text.";
    const int nbr_of_repeats = 1000000;             //  1,000,000 times

    /*  correct way:    */
    for(int i = 0; i < nbr_of_repeats; i++) {
        fprintf(destination, "line %7d: %s\n", i+1, simple_text);
    }

    /*  wrong way:
    *
    *   Why this is wrong? Even fwrite() gives you a more meaningful name
    *   of what to do here, this function shall only be used, if binary files
    *   are in use, too. If those are mixed, then the output file contains garbage.
    *
    *   size_t fwrite(
    *       const void *buffer,                     //  the source buffer
    *       size_t element_size,                    //  the size in bytes for the expected data type, e. g.: sizeof(byte) or similar
    *       size_t element_count,                   //  the number of elements, which are in this buffer => sizeof(buffer) / sizeof(buffer[0])
    *       FILE *stream                            //  destination stream, e. g.: FILE stream ("destination"), stdout, stderr, ... (but NOT stdin)
    *   );
    * 
    *   Returns the number of bytes written into the stream or 0, if this failed.
    */

    /*
    *   NOTE: This way comes with a wrong function handling, but this was intended.
    *
    for(int i = 0; i < nbr_of_repeats; i++) {
        fwrite(simple_text, sizeof(simple_text), 1, destination);
    }
    */

    fclose(destination);
}

int main(void) {
    write_into_a_file();

    // fun fact: by reaching EXIT_SUCCESS / EXIT_FAILURE / return n (n = any integer value) /
    // exit(n) all streams are automatically closed, but this does not mean, that you don't
    // have to close streams by your own
    return EXIT_SUCCESS;
}
#endif