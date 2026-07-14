#   repeat code over and over again
-   can be used to increment numbers or repeat code

#### different ways to repeat code

| type | with... |
| - | - |
| loops (iterations) | `for(initializer; condition; handling), while(condition) {...}, do {...} while(condition);` |
| recursion | function call to itself |
| jump instructions | by using `goto` |

##  loops (iteration)
-   an instruction runs until a base condition is no longer satisfied
-   very fast
-   hardly space amount
-   mostly more content rather than recursion or jump instructions (here: `goto` only)
-   recommended: **yes**

##  recursion (recurrent instructions)
-   use a function to run over and over again
    -   needs a condition check to clearly terminate the recursion, otherwise the application crashes (no more free space for a virtual amount of space during runtime)
-   difference between:
    -   direct recursion: a function calls itself
    -   indirect recursion: at least two functions required, where function A calls function B and vice versa
-   much slower than loops
-   comes with less code
-   often in use by Mathematicans / Physicans
-   takes more CPU / RAM
-   recommended: **yes**, but use this with care

##  jump instructions (goto only)
-   use this, if **you** really know what you do
-   more in use for assembly instructions to speed up the execution process
-   you **must** care about to use the goto statement(s)
-   comes with a mark to jump to that mark unless a condition, if given, does no longer satisfy
-   harder to debug
-   often causes "spaghetti code" (code, which don't follow up a clean workflow instruction)
-   recommended: **no**, unless you really know what you do

### loops
#### for
-   initializing an index, often used `i` and modify i for the next step until an condition does no longer exist
    -   `i++ | i--` := modify i after the current operation
    -   `++i | --i` := modify i before the current operation takes action
```
for(int i = 0; i < 10; i++) {}

for(int i = 100; i >= 0; --i) {}
```

#### while:
-   runs over and over again while a condition is set
    >   **NOTE**:   Make sure to toggle the condition from `true` (1) to `false` (0), otherwise an endless loop appears.

```
int counter = 0;
while(counter != 100) {
    // do something here
    counter++;
}
```

#### do-while:
-   similar to while loop, where the instruction(s) in this loop runs at least once
-   the do-while statement must be termianted with a semicolon

```
int counter = 0;
do {
    // do something
    counter++;
} while (counter != 100);
```

#### recursion
-   often used in math
    -   fibonacci series
    >   **NOTE**:   The higher the number the more time amount is required to calculate the next result until you're using an internal storage to reduce already handled numbers over and over again.
    -   factorial
    -   great common divider
    -   some sorting algorithms
    -   ...

```
// bad example
// Assuming a function call can be handled 2,2 million times. By calculating F(100) with this function below, this may take up to 16,5 million years.
int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    // F(n) = F(n-1) + F(n-2)
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void) {
    for(int i = 0; i <= 30; i++) {
        printf("fib(%d) = %d\n", i, fibonacci(i));
    }
    return EXIT_SUCCESS;
}
 ```
>   **NOTE**:   In **section c:i_runtime_optimizations** an optimization for the fibonacci series has been implemented there.

### goto

```
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int counter = 0;
    mark:
    printf("counter = %d\n", counter);

    if (counter < 10) {
        goto mark;
    }

    return EXIT_SUCCESS;
}
```