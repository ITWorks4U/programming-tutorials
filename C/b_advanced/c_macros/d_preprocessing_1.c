/*
* This C file offers to run instructions, if, and only if, a macro is defined.
* But with this twist, that this macro isn't defined in the source code. This will
* be defined in the compiling instruction instead.
*
* use: -D<MACRO>, where <MACRO> is the certain macro name
*
* To define multiple macros, you shall do this: -D<MACRO_1> -D<MACRO_2>, ...
*
* Those macros can also be defined with a certain value to do any special "magic".
* Use -D<MACRO>=<VALUE>, then this defined macro with a certain value enables to run
* code, if, and only if, this condition is set and compared with the expected value.
*
* To see, if the certain macro is truly defined, add -E as a single statement in your
* compile command. This prints everything defined on the console. Or redirect this into
* a commonly file with 'gcc[.exe] -D<MACRO>[=<VALUE>] > output_file.txt'
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    #ifdef SHOW_ME
    // use: gcc[.exe] -DSHOW_ME [-o <name_of_executable>]
    puts("This text can be shown.");
    #endif

    #if defined(SHOW_ME) && defined(ME_TOO)
    // use: gcc[.exe] -DSHOW_ME -DME_TOO [-o <name_of_executable>]
    puts("This can be displayed only, if SHOW_ME and ME_TOO has been defined.");
    #endif

    #if ANSWER == 42
    // use: gcc[.exe] -DANSWER=42 [-o <name_of_executable>]
    puts("The question is: What is the question?");
    #endif

    #if ANSWER == 21
    // use: gcc[.exe] -DANSWER21 [-o <name_of_executable>]
    puts("This makes no sense, but this also works. :o)");
    #endif

    return EXIT_SUCCESS;
}