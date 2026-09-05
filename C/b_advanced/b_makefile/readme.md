#   using a built tool for your project
-   allows you to build your application (almost) automatically without typing all required source files

##  Ways to create a project

| file | for... | special purpose | run with |
| - | - | - | - |
| `makefile` | UNIX (perhaps Windows, if supported) | contains targets to build a certain area or everything | `make` (to run the first target) or `make clean` (to clear the executable, if defined and also existing) |
| `*.bat` | Windows | contains marks with jump instructions for whats coming next | `.\<name>.bat` shall be enough |
| `*.ps1` | Windows | similar to a batch file, but for Powershell | `.\<name>.ps1 *` |
| `CMakeLists.txt` | any | for more professional software engineering and crosswide usage | `cmake --build . **` |

>   NOTES:
>>  `*` *It may happen, that a powershell is unable to run on Windows, because of user security purpose. This can be bypassed, but this must used with care. Command: `Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass`*

##  usage for CMake
1.  first check, if cmake is already installed on your system
    -   Windows: `where cmake`
        -   if not installed:
            -   installation cmake at cmake.org/download
            -   follow the instruction guide
    -   other systems: `whereis cmake`
        -   if not installed:
            -   `sudo apt install cmake`
2.  check, which version cmake you have with: `cmake --version`
3.  create a build folder and switch into this folder
4.  `cmake ..`
5.  `cmake --build .`
6.  usually, the application has been built
    -   Windows: the application is in `Debug/` folder
    -   other systems: the application is in the current folder
7.  to remove the application, run `cmake --build . --target clean`