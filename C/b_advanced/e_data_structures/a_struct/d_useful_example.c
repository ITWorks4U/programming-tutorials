/*
*
* Structures (struct) are very often used to capsulate
* multiple expressions to one object. Similar to OOP languages,
* however, the C programming is not mentioned to use for OOP.
*
* A structure often has a larger amount of bytes, because
* every member requires it's own free space.
*
* --------------------------------
* basic syntax of a struct:
* struct <name> {};
*
* you can also use a synonym for your structure, like:
* struct <name> {}<name_to_use>;
*
* you can also use an anonymous structure, like:
* struct {};
*
* in contrast to C++ when you want to use a structure, you must write:
* struct <name_of_struct> <name_of_instance>;
* => then you can use your structure and an access to its member(s)
*
* if you want to use a syntax like C++, Java, C#, Python, ... just write:
* typedef struct {}<any_expression>;
* => then you can use: <any_expression> <name_of_instance>;
* --------------------------------
*
* By the way, C handles a structure different rather than C++.
*
* C:
* - a struct contains members only
* - every member is unable to initialize inside of the struct
* - even a function can be wrapped into a struct to "claim", that
*   this function refers to that structure, but this is a bit tricky
*
* C++:
* - may initialize up to one member (any member)
* - may contain functions, constructor, destructor, ...
*  - those functions are called "methods", even there are not in a class
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH   25

struct Person {
    int person_id;                              //  can be an ID from / for a DB
    char first_name[BUFFER_LENGTH + 1];         //  first name with up to 50 characters
    char last_name[BUFFER_LENGTH + 1];          //  last name
    char address[BUFFER_LENGTH + 1];            //  full address
    //...
};

int main(void) {
    // accessing to members
    struct Person p;

    p.person_id = 100;
    strcpy(p.first_name, "Homer");
    strcpy(p.last_name, "Simpson");
    strcpy(p.address, "742 Evergreen Terrace");

    printf("amount of bytes for \"p\": %llu\n", sizeof(p));

    // WYSIWYG
    printf(
        "%d, %s, %s, %s\n",
        p.person_id, p.first_name, p.last_name, p.address
    );

    //  modify any data:
    p.person_id = 105;

    printf(
        "%d, %s, %s, %s\n",
        p.person_id, p.first_name, p.last_name, p.address
    );

    //  summary:    By updating the member(s) the other member(s)
    //              of this struct won't be affected.

    return EXIT_SUCCESS;
}