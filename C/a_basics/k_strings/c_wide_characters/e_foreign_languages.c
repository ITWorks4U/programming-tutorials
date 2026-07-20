#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#ifdef _WIN32
//  more in use for Windows, because typically foreign characters may not be displayed on console
#include <fcntl.h>
#include <io.h>
#endif

#define BUFFER_SIZE 32

typedef enum {                          //  see: chapter b:d_structures
    ARABIC,
    JAPANESE,
    RUSSIAN
}Language;

void display_hello(Language l) {
    static wchar_t hello_string[BUFFER_SIZE] = {0};

    switch(l) {
        case ARABIC:
            wcscpy(hello_string, L"مرحبا");
            break;
        case JAPANESE:
            wcscpy(hello_string, L"こんにちは");
            break;
        case RUSSIAN:
            wcscpy(hello_string, L"Привет");
            break;
        default:
            break;
    }

    wprintf(L"expression: %ls\n", hello_string);
}

int main(void) {
    #ifdef _WIN32

    //  NOTE    If "_O_U16TEXT" may not be known, which should, then this expression must be
    //          redefined again with: #define _O_U16TEXT     0x20000
    _setmode(_fileno(stdout), _O_U16TEXT);      //  more in use for Windows
    #endif

    setlocale(LC_ALL, "");

    //  NOTE: works in C, but C++ refuses to build this application
    for(Language l = ARABIC; l <= RUSSIAN; l++) {
        display_hello(l);
    }

    return EXIT_SUCCESS;
}