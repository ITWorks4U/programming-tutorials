#   C-strings
>   **NOTE**:   C-strings are quite different to regular strings and these shall **never** be mixed. Furthermore C-strings have a different way to use.

-   store n bytes (characters) into a buffer, which can be used for anything
-   a C-string **must** be terminated with a null termination character: `\0`
    -   if you omit this requirement, then this leads to an undefined behavior
-   in contrast to a regular string a C-string is not immutable and can be changed during runtime
-   can be handled as an array, because it stores n elements of type `char` (n = 0,1,2,3,...)

### different types of C-strings
1.  regular (signed) C-strings
    -   usually in a range between `[0..127]` (ASCII-table)
    -   for ASCII communication
2.  unsigned C-strings
    -   more in use for byte expressions, like: UART
    -   in a range between `[0..255]` (often hexadecimal value `0x0..0xFF`)
3.  wide characters
    -   in use for extended characters, like emojis and for other languages, like russian, japanese, chinese, ...
    -   uses an another purpose and handling in contrast to the regular C-strings
    -   a mix between C-strings and wide characters often won't work
    -   a prefix with `L` is required, otherwise this can't be handled as a wide string

>   **NOTE:**
>>  *On a Windows machine the range of wchar_t comes with `[0..65,535]`, whereas on an UNIX machine this often comes with a range of `[0..2,147,483,647]`, thus not each symbol, word, expression can be displayed without flaws on every system.*

### header for C-strings

| language | header file | additional informations |
| - | - | - |
| **C** | `string.h` | only in C |
| **C** | `strings.h` | only in C; more in use for additional operations on **UNIX** systems; on **Windows** this header file usually doesn't exist |
| **C** | `wchar.h` | only in C; more in use for wide characters (for emojis, other languages, UTF-8, UTF-16, UTF-32, ...)
| **C++** | `cstring` | only for C++; C++ **may** also work with the libaries above, however, for C-strings the C language is recommended to use |

### functions, like:
>   **NOTE:**   *Depending on the system, you're using, these function examples below are almost **not** thread-safe or offers a nasty side effect, if you don't mind.*

-   `strcmp(const char *str1, const char *str2);`
    -   compare str1 and str2, if these are equal
    -   returns `0`, if these are equal
    -   returns `<0`, str1 has on any position a smaller character than str2
    -   returns `>0`, str1 has on any position a higher character than str2

-   `strlen(const char *str);`
    -   returns the number of elements for str until the first null termination character has been detected
    >   **NOTE**:   Don't mix strlen() with sizeof(), because those have different meanings.

-   `strcpy(char *dest, const char *src);`
    -   copy src to to dest character by character
    >   **NOTE**:   If src contains more characters, then dest can be store, then this leads to an undefined behavior! In that case use the function `strncpy(char *dest, const char *src, size_t len);` instead to copy up to n characters from src to dest.

-   `memset(void *ptr, int val, size_t size);`
    -   because C-strings, as well as other variables, contains garbage on runtime until those are initialized, it's highly recommended to set a C-string with a default value state
        -   example:
        ```
        char data[30];
        memset(data, '\0', sizeof(data));
        ```

-   `strcat(char *dest, const char *src);`
    -   concatenate strings
        -   similar to strcpy make sure to copy not more characters from src to dest
        -   use `strncat(char *dest, const char *src, size_t len);`instead