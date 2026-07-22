/*
* Arrays are a fixed list of values, depending on its data type. Don't think, that an array and
* a pointer are the same! They don't, even they have a set of shared functionalities.
*
* If you want to know how to use pointers, then take a look to chapter c:b_memory_management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handler_function_for_arrays(int array[], size_t elements) {
    for(size_t i = 0; i < elements; i++) {
        printf("element: %d\n", array[i]);
    }
}

int main(void) {
    // -----------
    // integer array
    // -----------
    int array[] = {1, 2, 3, -100, -687, 753, 42, 1337, 9001};              // 9 array elements

    // MISTAKES with arrays in C/C++:

    // printf("WRONG: array has %d elements\n", array);                    // unable to print the array elements
    printf("WRONG: array has %lu elements\n", sizeof(array));              // Shall return 9 elements, right? Wrong! Here, 36 elements returns!
                                                                           // Reason: An integer uses 4 bytes => 4 * 9 = 36 bytes, which means this is
                                                                           //         the maximum number of required free space.

    // this is the correct way to receive the number of elements in an array:
    // 9 elements :o)
    size_t number_of_elements = sizeof(array) / sizeof(array[0]);

    // by the way: On Windows %lu might be an unsigned int, so it may happen,
    // that you're getting a warning on compile time
    printf("CORRECT: array has %lu elements\n", number_of_elements);

    // -----------
    // C-strings (are more an array of characters)
    // -----------
    char word[] = "Howdy! How're you?";

    // Surprised of sizeof and strlen?
    printf("(sizeof) => word has %lu elements\n", sizeof(word));
    printf("(strlen) => word has %lu elements\n", strlen(word));
    printf("(sizeof(word)/sizeof(word[0])) => word has %lu elements\n", sizeof(word) / sizeof(word[0]));

    // -----------
    // outsourcing to function
    // for a static array this works fine, however, if you're
    // using a pointer instead, you'll get a (some) nasty surprise(s)
    // -----------
    handler_function_for_arrays(array, number_of_elements);

    // puts("What happens here...???");
    // handler_function_for_arrays(word, strlen(word));
    // NOTE: At this point the compiler refuses to build your program, because
    //       the function arguments requires an integer array, followed by
    //       the number of elements for this integer array. By using pointers
    //       this can be used, but this also contains a nasty side effect.

    return EXIT_SUCCESS;
}