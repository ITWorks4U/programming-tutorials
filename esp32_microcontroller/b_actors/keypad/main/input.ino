#include <string.h>
#include "input.h"

static char input_buffer[BUFFER_INPUT + 1] = {0};
static uint_t position = 0;

void append_input(const char c) {
    if (position != BUFFER_INPUT) {
        input_buffer[position++] = c;
    }
}

uint_t compare_with_preset(void) {
    return strcmp(input_buffer, PRESET_CODE) == 0;
}

void reset_input(void) {
    memset(input_buffer, '\0', sizeof(input_buffer));
}

void terminate_input(void) {
    input_buffer[position] = '\0';
}

char *print_input(void) {
    return input_buffer;
}