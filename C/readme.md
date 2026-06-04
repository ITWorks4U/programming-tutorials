#   C programming

>   **NOTE**    *At this moment the repository is currently in a rework. Check out the videos on YouTube: https://www.youtube.com/watch?v=DHYG2lALRrg&list=PLwMeVY6dlAg20kre011gbHHzMl77SIi-g*

- learn how to use C
    - basic usage
    - decicion making
    - loops
    - debugging
    - ...
- can be used with UNIX/Linux, macOS, Windows
    - create files / directories
    - handling I/O
    - ...

### Requirements
-   you need a C compiler, like: `gcc, clang, cygwin, msys32, ...`
    -   Windows: ```gcc.exe```
        -   by default these programs are going to build with `MinGW`
        -   If you run Visual Studio, then you might have a different workflow or behavior.
    -   Linux/macOS: ```gcc```
        -   by default gcc is installed on your system

### How to figure out, if gcc[.exe] exists?
-   Windows: ```where gcc.exe```
-   Linux: ```whereis gcc```

### How to run
-   usually, your source file must be compiled first: ```gcc[.exe] [additional flag(s)] <source file(s)> -o <output_file_name>```
    -   Windows is using `.exe` by default
    -   In Linux `*.out` is in use here

### additional flags
| flag | description |
| - | - |
| `-Wall` | enable more detailed warnings, which are usually not visible on compile time |
| `-Wextra` | more warnings... |
| `-o` | output file name |
| `-g` | create a dumped core file in case of your application crashes |

### Can C++ also used here?
-  even C and C++ shares a bunch of functionalities, it's not recommended to use a C++ compiler to run those samples
    -  it may happen, that your application(s) may not work correctly or returns a different result rather than C

### How to run your application wrongly
-   very easy, if you don't mind
-   this happens, if:
    -   wrong usage of the C code
    -   copy + paste the code 1:1 to run this on a different system