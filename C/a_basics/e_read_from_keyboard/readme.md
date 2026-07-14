# Reading from the keybord

-   in C you have many ways to read any input from the keyboard

##  Important
-   every input is a **word**, even a number has been typed in
-   almost every function, which reads from the keyboard or from a file stream has not a clear limitation for the input buffer
    -   keep this in mind, otherwise a nasty side effect will appear
    -   often crashes the application by causing a segmentation fault
-   every remaining character is stored into an internal buffer
    -   when a next read attempt is going to use, then the internal buffer is in use first before the keyboard or an external source is in use

##  different functions

| function | description | side effects | can be used...? |
| - | - | - | - |
| `gets(void)` | read everything from the keyboard | *Doesn't care about buffer limitation and leads to a critical state.* | definitely: **no** |
| `scanf(const char *format, ...)` | read from keyboard until the first space or enter character has been detected | you must use a valid format for the input, otherwise this function leads to an undefinded behavior; similar to `gets()`: *Doesn't care about buffer limitations.* | not really |
| `fscanf(const FILE *stream, const char *format, ...)` | read from an input stream, like keyboard (**stdin**), but can also read from a file | same side effect like `scanf()` function | hardly |
| `getc(FILE * stream)` | read a single character only | it returns the integer position from the **ASCII** table, e. g.: "0" => 48 , "A" => 65, ... |  maybe |
| `fgetc(FILE *stream)` | better handling in contrast to `getc()` | same side effect to `getc()` function | maybe |
| `getchar(void)` | read the next character from the keyboard only | same side effect to `getc()` function | yes |
| `getch(void)` | identical to `getchar()` function | only in use on old Windows versions with turbo C | hardly |
| `fgets(char *buffer, size_t length, FILE* stream)` | read any input including whitespace(s) from input stream, like keyboard (**stdin**) and store it to **buffer** | The newline character (`'\n'`) is also going to append to your buffer while the input fits into your buffer and shall be handled, otherwise this is not part of your input buffer. | yes |
| `atoi(const char *string)` | "argument to integer" => convert the given argument to an integer value | Any invalid input returns "0". Same side effect with `atol()`, `atof()`, ... | definitely: **no** |
| `strtol(const char *string, char **endptr, int base)` | convert an argument to a long value | Read and convert every valid value into an integer until the first invalid character or end of string has been detected. Every other valid value after an invalid value won't be handled and can be redirected to endptr, if given. If endptr is set to `NULL`, then the remaining input will not be handled. The `base` tells how the number shall be converted: 0 or 10: decimal value, 2: binary value, 8: octal value, 16: hexadecimal value, but the result is always an integer value! | yes |

>   **NOTE**: Some functions, like `sscanf(const char *buffer, const char *format, ...)`, ... sounds similar to the functions above, however, those have a different purpose.

###    clear the input buffer
-   it's high recommended to clear the input buffer for a next scan, otherwise any remaining character from the previous input will automatically be used

>   **NOTE**: This works only for C. In C++ this leads to an **undefined behavior**. Furthermore C++ uses an another way to clean up the remaining buffer mess.

-   typical way to clean up the remaining buffer:
```
int c;
while ((c = getchar()) != '\n' && c != EOF);

// It may happen to hit enter twice.
```

>   **NOTE**: Don't use the function `fflush(FILE *stream)` like: ```fflush(stdin)```. This won't clear the input buffer. It flushes the output stream only, like `stdout`, `stderr` or a file stream buffer.