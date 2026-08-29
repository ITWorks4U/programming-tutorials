#   C / C++ header files
-   header files are similar to interfaces, where those are not interfaces for OOP
    -   these offers data types, definitions, functions, etc.
-   define anything in a header file and use this in the source file(s) without define those types multiple times
    -   attention: don't mix C and C++, when the header file shall be used in the C programming only
-   name of header file(s): `*.h`
    -   fun fact: for **C++** the header file `*.hpp` was in use for a **C++ - header file**, however, the classic `*.h` file has replaced this file extension

##  What is an include protection?
-   protecting the source files to redefine anything over and over again
-   required, otherwise this turns into an error on compile time

```
#ifndef expression
#define expression

// definitions for constants, data types, function prototypes, ...

#endif
```

-   modern alternative:
```
#pragma once

// definitions for constants, data types, function prototypes, ...
```

>   **NOTE:**   This alternative is recommended, because you don't use too complex code, however, on old systems this may be unknown. In that case the first version is usually in use.
>>  *However, the `expression` can be undefined and / or redefined anywhere and this causes a nasty surprise.* 