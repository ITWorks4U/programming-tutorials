#   literals in C / C++
-   allows to define a specific data type, when the default assignment is not clear or not solid to use
    -   macro expressions (constant expressions)
    -   integers, floating point values

####    different types of literals

| literal | effect |
| - | - |
|  U          |  unsigned integer       |
|  L          |  long (if 'L' is on the last position) |
|  L          |  large string (if 'L' is on the first position, where a word **MUST** be used, too => also remember to include `<wchar.t>` library) |
|  LU or UL   |  unsinged long          |
|  LL         |  long long              |
|  LLU or ULL |  unsigned long long     |
|  0B         |  binary expression      |
|  0          |  octal expression       |
|  0x         |  hexadecimal expression |
|  F          |  floating point         |
|  ' '        |  character literal      |
|  " "        |  string literal         |