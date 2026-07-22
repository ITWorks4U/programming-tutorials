#   Have fun with random
-   use a (pseudo) random generated number on runtime
-   examples:
    -   "random" number on runtime
    -   lottery
    -   password generator
    -   ...

####    required implementations
-   `time.h` (C only)
-   `ctime` (C++ only)
-   `time_t` datatype
-   `srand(unsigned int seed);`
-   `time(const time_t * _time);`
-   `rand(void);`

####    initialize with
```
time_t t;
srand(t);
```

####    take a "random" number
```
int a = rand();
```
>   **NOTES**:
>>  *In one elapsed second it may happen, that this "random" number is always the same before the next random number takes action.*

>>  *In C++ this has a different behavior instead of C. In that case you *should* really care about how to use that module(s)! These are (very old) functions. On a Windows machine the used function(s) may be a reason to assume, that this is a threat and your antivirus application may take action. On an UNIX system, this may also appear!*