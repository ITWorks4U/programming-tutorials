#include <stdio.h>
#include <stdlib.h>

enum Status {
    OK, DEBUG, INFO, WARNING, ERROR, NOTHING 
};

// NOTE:    'WARNING' is already defined in Status.
enum LogType {
    LOG_DEBUG = 100, LOG_INFO, /*WARNING,*/ LOG_WARNING
} lt;

// defining an own datatype by using 'typedef'
typedef enum {
    ON, OFF
}ToggleSwitch;

int main(void) {
    enum Status status = OK;

    // Surprised? Since "OK" is the first value, 0 is automatically set
    printf("status = %d\n", status);

    /*
    * Since this source code contains to work with enumerations, which are valid
    * in C, but not in C++, a C++ - compiler may not build this application.
    *
    * "s++" or "lt--" can't be used correctly
    * "error: no 'operator++(int)' declared for postfix '++' [-fpermissive]""
    *
    * In that case by using a C++ compiler this code snippet is skipped.
    */
    #ifndef __cplusplus
    for(enum Status s = OK; s <= NOTHING; s++) {
        printf("%d\n", s);
    }

    for(lt = LOG_WARNING; lt >= LOG_DEBUG; lt--) {
        printf("%d\n", lt);
    }
    #endif

    // -----------
    // custom data type
    // -----------
    ToggleSwitch ts = ON;

    switch (ts) {
        case ON:
            puts("ToggleSwitch is ON!");
            break;
        case OFF:
            puts("ToggleSwitch is OFF!");
            break;
    }

    // -----------
    // Different amount of bytes? No!
    // -----------
    size_t size_status = sizeof(enum Status);
    size_t size_log_type = sizeof(lt);
    size_t size_toggle_switch = sizeof(ToggleSwitch);

    printf("amount of bytes for: [Status = %llu; LogType = %llu; ToggleSwitch = %llu]\n", size_status, size_log_type, size_toggle_switch);

    return EXIT_SUCCESS;
}