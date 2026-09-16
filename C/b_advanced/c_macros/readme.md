#   macros and preprocessing directives in C / C++
-   allows to define real (un)stable constants
    -   because a macro is typeless and sometimes this offers more pitfalls instead of features
    -   recommended: use a literal expression (see: **section b:f_literals**)
-   often used for:
    -   constant expressions of (floating point) numbers, words
    -   macro functions (with nasty side effects, if you don't mind)
    -   preprocessor instructions, like on which operating system (OS) an application is running
    -   debugging instructions

>   **NOTES:**
>>  *A macro and a preprocessing instruction looks similar, but those are not the same!*

>>  *Sometimes on compile time a certain macro can be triggered. This can be realized with: `-D<MACRO_NAME>`.*

##  how to define a macro
-   use: `#define <MACRO_NAME> [<VALUE>]`
    -   a macro doesn't need a value, because this can be used for many different purposes

### difference between macro and preprocessing instruction

| type | meaning | example(s) |
| - | - | - |
| preprocessor | an instruction, which will be handled first before the first line of code is going to be checked by the compiler itself | `#include <library>`, `#ifdef <MACRO>`, `#undef <DEFINED_MACRO>` |
| macro | more in use for any constant expression, like integer, floating point value (`M_PI`), C-string, ... | `#define BUFFER_LENGH 100` |
| macro function | offers an "unique" function to handle with any data, however, this may also turn into a trip to hell, if you don't mind | `#define ADD(x, y) ((x) + (y))` |
| macro alias | defines an alias for any other defined value, where this must be defined earlier, otherwise this turns into an error or undefined behavior | `#define <ANY_ALIAS_FOR> <ANY_ALREADY_KNOWN_VALUE_OR_FUNCTION_OR_ELSE>` |
| crosswide union expression | more in use, if a certain step shall be done, no matter, on which OS you're working on | `#define TIMEOUT(x) [Ss]leep((x) [* 1000]) *`

>   **NOTE:**   *`*` The sleep function pauses the system for an amount of time in seconds, before the next instruction is going to do. Furthermore on Windows `Sleep(x)` is in use and `x` are already known **milliseconds**, whereas on an UNIX system `sleep(x)` is in use and `x` are known **seconds**.*


### known pitfalls
-   Macros are typeless. So you can also lead into an undefined behavior or a logical error in your application.
-   if a macro may exist anywhere, then may lead into an error on compile time or an undefined behavior, like:
    -   `BUF`, `BIFSIZ`, ...