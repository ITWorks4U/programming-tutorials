#ifndef LITERALS_H
#define LITERALS_H

#include <wchar.h>

#define NUMBER_OF_LITERALS  12

// by default, it might be interpreted as signed integer
#define EXPRESSION_0   1000

// unsigned integer
#define EXPRESSION_1   1000U

// long integer
#define EXPRESSION_2   1000L

// long long integer (1000i64)
#define EXPRESSION_3   1000LL

// binary expression => 1000 => 8 in decimal
#define EXPRESSION_4   0B1000

// octal expression => 512 in decimal
#define EXPRESSION_5   01000

// hexadecimal expression => 4096 in decimal
#define EXPRESSION_6   0x1000

// floating point expression only
#define EXPRESSION_7   1000.0F

// double expression only
#define EXPRESSION_8   1000.0

// character literal only => 70 in decimal
#define EXPRESSION_9   'F'

// string literal only, even this contains a single character only
// Guess what? C-String comes with \0 => "F" has a length of 2 bytes.
#define EXPRESSION_10  "F"

//  large string (use: wchar_t as type, as well as, #include <wchar.h>)
#define EXPRESSION_11   L"This is a large string!"

///
// function prototype
///

void display_all_expressions(void);

#endif