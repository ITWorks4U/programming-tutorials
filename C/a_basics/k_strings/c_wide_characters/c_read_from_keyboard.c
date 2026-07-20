#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define BUFFER_LENGTH   32

int main(void) {
    // setlocale(LC_ALL, "");
    wchar_t input[BUFFER_LENGTH] = {0};
    
    printf("Enter something: ");
    fgetws(input, sizeof(input), stdin);                // similar to fgets, but with wide characters

    // clear remaining characters => a second '\n' (enter key) may be required
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    wprintf(L"input was: %ls\n", input);

    return EXIT_SUCCESS;
}