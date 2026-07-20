#include <stdio.h>
#include <stdlib.h>

// -----------
// Debugging a code runs easy within an IDE.
// Without an IDE (terminal) use gdb
// -----------
// Linux:
// 	gdb shall be installed by default
// 	usage: gdb <application>
// Windows:
// 	use mingw to debug code outside of an IDE
// 	=> gdb.exe <your application.exe>
// -----------
// small breakdown for debugging:
//
//  ---------------|----------------------------|-----------------------------
//  command        | effect                     | additional information
//  ---------------|----------------------------|-----------------------------
//  r | run        | run your application       | shall be the last command
//  ---------------|----------------------------|-----------------------------
//  b | break      | tells the debugger, where  | this can be a function (function name),
//                 | the application shall be   | a line number in the current file,
//                 | halted                     | line number in a foreign file, ...
//                 |                            | example: b(reak) recursion_function
//  ---------------|----------------------------|-----------------------------
// s | step        | do the next step           | can go into a function, which was not marked
//                 |                            | with break => in IDE (typically) F11
//  ---------------|----------------------------|-----------------------------
// n | next        | do the next step           | runs to the next instruction or to the next break statement
//  ---------------|----------------------------|-----------------------------
// p | print       | print the current value    | the value must be named here
//  ---------------|----------------------------|-----------------------------
// q | quit        | stops the debugger         | on runtime you must confirm to leave the debugger
//  ---------------|----------------------------|-----------------------------

int recursion_function(int counter) {
    /*
    * Let's take a look to this recursion function.
    * This leaves the function only, if counter is 100, however,
    * this won't be done. Let's try to figure out why.
    */

    if (counter == 100) {
        return counter;
    }

    return recursion_function(counter++);           //  This is the error: counter++ tells: "Call recursion_function and modify counter by 1.",
                                                    //  however, when recursion_function has been called, then the incrementation attempt won't
                                                    //  be done for the new function. Instead, counter still remains to the last assigned value.
                                                    //  This incrementation will be done, when the next recursion function call returns to the
                                                    //  previous function call. In other words: Never.
                                                    //
                                                    //  Solution:   Either use counter++ before the recursive function call is going to use or
                                                    //              use ++counter. With ++(value) this has a higher priority instead of the
                                                    //              function call itself.
}

int main(void) {
    printf("%d\n", recursion_function(0));
    return EXIT_SUCCESS;
}