#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else

/*
* Do you need a new password and you're tired to use an already, perhaps not good application?
* Then create your own application instead. ;-)
*
* - This application is written in C only.
* - tested with Linux (Mint 21.1), Raspberry OS Lite, Windows 10,11
*
* Have fun! :)
*/
#include <stdio.h>
#include <stdlib.h>

// for memset()
#include <string.h>

#include <time.h>

/* a pool of available characters => '%' must be marked with %% */
#define CHAR_POOL       "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"$%%&/()=?;,:._-'#*+\\{}[]"
#define SIZE_FOR_PASSWD 150

// ---------------
// ---------------
// ---------------

int main(void) {
    srand(time(NULL));
    char passwd[SIZE_FOR_PASSWD + 1];                   // to hold up to 150 random characters + \0

    for(int i = 5; i <= SIZE_FOR_PASSWD; i += 5) {      // create a random password; starts with 5 characters and ends with 150 characters
        memset(passwd, '\0', sizeof(passwd));

        int counter = 0;

        while(counter != i) {
            int rand_nbr = rand() % strlen(CHAR_POOL);
            passwd[counter] = CHAR_POOL[rand_nbr];
            counter++;
        }

        printf("random password (%3d characters): %s\n", i, passwd);
    }

    return EXIT_SUCCESS;
}
#endif