#   math operations with C
-   allows to use math functions, like:
    -   trigonometry (sin, cos, tan, ...)
    -   extended math (log, log10, ...)
    -   base math (pow, sqrt, ...)
-   accessing to constants, like pi, e, ...

>   **NOTE:**   *On a Windows machine, some constants, like `M_PI` are undefined and must be defined by hand.*
>>  *Not every UNIX system comes with such constants, too.*

####    required module(s)
-   `math.h`(C only)
-   `cmath` (C++ only)

>   **NOTE:**   *On an UNIX system by using any math function the compiler must be combined with `-lm`, otherwise the application can't be build. On a Windows machine this is not required to do.*