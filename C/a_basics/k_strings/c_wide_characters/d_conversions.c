#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define BUFFER_LENGTH  128

void convert_to_wide_string(void) {
    char data_c_string[] = "This is a regular C-string and this shall be converted into a wide character string and vice versa.";
    wchar_t converted_wide_string[BUFFER_LENGTH] = {0};

    mbstowcs(converted_wide_string, data_c_string, strlen(data_c_string));                  // Multi Byte String TO Wide Character String
    wprintf(L"WIDE-CHARACTER: %ls\n", converted_wide_string);
}

void convert_to_signed_string(void) {
    wchar_t data_wide[] = L"This is a regular C-string and this shall be converted into a wide character string and vice versa.";
    char buffer_c_string[BUFFER_LENGTH] = {0};

    wcstombs(buffer_c_string, data_wide, sizeof(buffer_c_string));      // Wide Character String TO Multi Byte String

    printf("C-STRING: %s\n", buffer_c_string);                          // NOTE: It may happen, that wprintf is unable to
                                                                        // display the C-string in a correct order.
                                                                        // If true, then use printf instead.
}

void try_to_convert_bidirectional(void) {
    char data_c_string[] = "This is a regular C-string and this shall be converted into a wide character string and vice versa.";
    wchar_t converted_wide_string[BUFFER_LENGTH] = {0};

    mbstowcs(converted_wide_string, data_c_string, strlen(data_c_string));
    wprintf(L"WIDE-CHARACTER: %ls\n", converted_wide_string);

    char reconverted_to_c_string[BUFFER_LENGTH] = {0};
    wcstombs(reconverted_to_c_string, converted_wide_string, sizeof(converted_wide_string));
    printf("C-STRING: %s\n", reconverted_to_c_string);
}

int main(void) {
    convert_to_wide_string();
    convert_to_signed_string();
    try_to_convert_bidirectional();     //  NOTE: may not work on every system

    return EXIT_SUCCESS;
}