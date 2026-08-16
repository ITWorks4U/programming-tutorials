/*
* Arrays are a fixed list of values, depending on its data type. Don't think, that an array and
* a pointer are the same! They don't, even they have a set of shared functionalities.
*
* If you want to know how to use pointers, then take a look to chapter c:b_memory_management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//       often used: int *array
void use_array_wrong(int array[]) {
    size_t number_of_elements = sizeof(array) / sizeof(array[0]);       //  How many elements can be determined? Maybe 1, 2, ...?
                                                                        //  By the way, this also produces a warning, that
                                                                        //  the division of sizeof(int *) / sizeof(int) does not
                                                                        //  compute the number of array elements.

    printf("number of elements: %llu\n", number_of_elements);           //  UNIX: %lu | on some Windows systems: %u only
}

void use_array_correct(int array[], size_t elements) {                  //  the number of elements must be appended to work correctly
    for(size_t i = 0; i < elements; i++) {
        printf("element: %d\n", array[i]);
    }
}

int main(void) {
    int array[] = {1, 2, 3, -100, -687, 753, 42, 1337, 9001};           //  9 array elements

    #if false
    // MISTAKES with arrays in C/C++:

    printf("WRONG: array has %d elements\n", array);                    //  unable to print the array elements
                                                                        //  this usually prints the decimal value of the
                                                                        //  stored memory address of the array

    printf("WRONG: array has %lu elements\n", sizeof(array));           //  Shall return 9 elements, right? Wrong! Here, 36 elements returns!
                                                                        //  Reason: An integer comes with 4 bytes => 4 * 9 = 36 bytes, which means this is
                                                                        //          the maximum number of required free space has been
                                                                        //          determined here.

    use_array_wrong(array);                                             //  Won't produce a warning, but this is a wrong way to
                                                                        //  to work with an array.
    #else

    // this is the correct way to receive the number of elements in an array:   9 elements :o)
    size_t number_of_elements = sizeof(array) / sizeof(array[0]);

    // size_t number_of_elements = sizeof(array) / sizeof(int);         //  alternate way, unless the size of the certain type
                                                                        //  won't match

    printf("CORRECT: array has %llu elements\n", number_of_elements);
    use_array_correct(array, number_of_elements);

    // -----------
    // C-strings (are more an array of characters)
    // -----------
    char word[] = "Howdy! How're you?";

    // Surprised of sizeof and strlen?
    printf("(sizeof) => word has %llu elements\n", sizeof(word));
    printf("(strlen) => word has %llu elements\n", strlen(word));
    printf("(sizeof(word)/sizeof(word[0])) => word has %llu elements\n", sizeof(word) / sizeof(word[0]));

    #if false
    puts("What happens here...???");
    use_array_correct(word, sizeof(word));
    // NOTE:    At this point the compiler produces a warning or may also refuse
    //          to build your program, because the function arguments requires
    //          an integer array, followed by the number of elements for
    //          this expected integer array. By using an another data type
    //          this contains a nasty side effect.

    int a = 100;
    use_array_correct(&a, 5);
    // NOTE:    This also leads to an undefined behavior. Usually, the address
    //          of a variable of type int can be used, but with the twist, that
    //          this is not an array, this is marked as a pointer (memory address
    //          of the stored variable), thus this also comes with a nasty
    //          side effect. Furthermore the second argument assumes, that this
    //          "array" comes with 5 elements, which doesn't has.
    #endif
    #endif

    return EXIT_SUCCESS;
}