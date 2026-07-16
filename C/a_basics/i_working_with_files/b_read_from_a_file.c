/*
* Read from a file. This code snippet is supposed to use on
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
// assuming, that a line may hold up to 100 characters only
#define MAX_CHARS_PER_LINE 100

#include <stdio.h>
#include <stdlib.h>

// alternatives:
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define FILE_TO_READ    "test.txt"              //  make sure, that this file truly exists

void read_from_file(void) {
    FILE *source = fopen(FILE_TO_READ, "r");

    if (!source) {                              //  alternative: if (source == NULL) {...}
        perror("fopen()");
        return;
    }

    char buffer[MAX_CHARS_PER_LINE + 1];        //  contains a buffer for 100 characters (+1 for \0)
    // memset(buffer, '\0', sizeof(buffer));    //  optional: can be used to reset the buffer, but with fgets() this step can be skipped

    // reading the file line by line
    // the loop stops, when no more data from source can be read
    //
    // perhaps, this also happens, when the file stream is corrupted,
    // suddenly deleted, ..., but this is not a 100% guarantee
    //
    // "sizeof(buffer) - 1" is recommended, because a C-string MUST end
    // with a null termination character!
    while ((fgets(buffer, sizeof(buffer), source)) != NULL) {
        // usually, in every loop the buffer must be reset, otherwise it may
        // happen, that some characters left may also be exist for the next line
        //
        // since fgets already appending "\n" to buffer, there's no need
        // to add "\n" in printf function
        printf("%s", buffer);
    }

    /*  wrong way:
    *
    *   Why this is wrong? Even fread() gives you a more meaningful name
    *   of what to do here, this function shall only be used, if binary files
    *   are in use, too. If those are mixed, then the buffer contains garbage.
    *
    *   size_t fread(
    *       void *buffer,                           //  the destination buffer
    *       size_t element_size,                    //  the size in bytes for the expected data type, e. g.: sizeof(byte) or similar
    *       size_t element_count,                   //  the number of elements, which are in this buffer => sizeof(buffer) / sizeof(buffer[0])
    *       FILE *stream                            //  source stream, e. g.: FILE stream ("source"), stdin, ... (but NOT stdout, stderr)
    *   );
    * 
    *   Returns the number of bytes read from the stream or 0, if this failed.
    */

    /*
    *   NOTE: This way comes with a wrong function handling, but this was intended.
    *
    while(true) {
        if (fread(buffer, sizeof(buffer), 1, source) == 0) {
            break;
        }

        printf("%s\n", buffer);
    }
    */

    fclose(source);
}

int main(void) {
    read_from_file();

    return EXIT_SUCCESS;
}
#endif