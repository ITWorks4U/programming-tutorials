#ifndef INPUT_H
#define INPUT_H

#define ROW_NUM         4
#define COLUMN_NUM      4
#define BUFFER_INPUT    15
#define PRESET_CODE     "3571D59BA84C26"
#define CANCEL_KEY      '*'
#define CONFIRM_KEY     '#'

typedef unsigned int uint_t;

void append_input(const char c);
uint_t compare_with_preset(void);
void reset_input(void);
void terminate_input(void);
char *print_input(void);

#endif