/*
* Sometimes a code shall run on many different systems, however, not every
* system uses the identical code. This simple sketch offers a way to handle
* an instruction without a clean known dependency for the certain system itself.
*
* example:
* Sleeping for a while in x seconds, whereas this is different depending on the
* used system. Windows: Sleep(x) (x = milliseconds), UNIX: sleep(x) (x = seconds)
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
// only for Windows (NOTE: for any modern 32 / 64 bit machine)
#include <Windows.h>
#define TIMEOUT_IN_SECONDS(x)  Sleep((x) * 1000)
#else
// for UNIX systems (NOTE: this also "covers" any other non UNIX system)
#include <unistd.h>
#define TIMEOUT_IN_SECONDS(x)  sleep((x))
#endif

int main(void) {
    puts("Sleep for 5 seconds...");

    for(int i = 0; i < 5; i++) {
        puts("ZzZ");
        TIMEOUT_IN_SECONDS(1);
    }

    puts("I woke up!");

    return EXIT_SUCCESS;
}