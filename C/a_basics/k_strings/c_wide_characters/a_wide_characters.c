/*
* In contrast to regular characters or unsigned characers (often: raw byte data),
* wide characters are in use to cover additional encoding formats, like UTF-8, UTF-16, ...,
* to handle languages in japanese, russian, arabic, emojis, ...
*
* NOTE: On a Windows system you might get a warning like:
*       "warning: character not encodable in a single code unit"
*
*       Because on Windows wchar_t usually comes with an upper
*       boundary of 65,536 whereas on an UNIX system this is similar
*       to 2,147,483,647.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void) {
    //  shows the upper boundary of wchar_t
    printf("ranges for wchar_t: [%u..%u]\n\n\n", WCHAR_MIN, WCHAR_MAX);
    
    // only with <wchar.h>
    wchar_t single_character = L'A';

    //NOTE: a compiler would give you a warning, because wide characters usually needs wprintf()
    printf("the wide-single character: %lc\n", single_character);

    // in combination with <string.h>
    char word[] = "This is a simple string.";
    size_t length = strlen(word);

    for(size_t i = 0; i < length; i++) {
        printf("%lc\n", word[i]);
    }

    return EXIT_SUCCESS;
}