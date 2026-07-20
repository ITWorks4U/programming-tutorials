/*
* In contrast to a regular C-string, a wide string has a
* different handling to use this properly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) {
    wchar_t expression[] = L"This is a simple C-string, but of type wchar_t.";

    // unlike to use printf(), a wide C-string is recommended to use with wprintf()
    // NOTES:
    //      - %ls is in use instead of %s
    //      - the prefix "L" MUST be used in front of the expression, otherwise the compiler complains with an error (incompatible pointer type)
    wprintf(L"%ls\n", expression);

    // this is awful, but also possible to use
    wchar_t letters[] = {L'A', L'B', L'C', L'\0'};
    wprintf(L"%ls\n", letters);

    return EXIT_SUCCESS;
}