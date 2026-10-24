/*
* Since an union and a struct may have different purposes,
* those can also be combined. Also known as "tagged unions".
*
* Those can be used to hold one of several types, but we need
* to know which one currently stored.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_BUFFER       50
#define LENGTH_ZIP          6
#define NBR_OF_ADDRESSES    2

typedef struct {
    union {
        struct {
            char city[LENGTH_BUFFER + 1];
            char zip[LENGTH_ZIP + 1];
            char first_name[LENGTH_BUFFER + 1];
            char last_name[LENGTH_BUFFER + 1];
        } _priv;

        struct {
            char city[LENGTH_BUFFER + 1];
            char zip[LENGTH_ZIP + 1];
            char first_name[LENGTH_BUFFER + 1];
            char last_name[LENGTH_BUFFER + 1];
        } _pub;
    };
} Address;

int main(void) {

    // NOTE:
    // Without an array an access to a member also affects the other members!
    // Since C-strings are in use they contains garbage on runtime.
    // If you try to build that sample in C++ make sure NOT to use C++ keywords, like "public", "private".

    Address a[NBR_OF_ADDRESSES];
    printf("Total amount of bytes for Address: %llu\n", sizeof(Address));
    printf("Amount of bytes for a0: %llu\n", sizeof(a[0]));
    printf("Amount of bytes for a1: %llu\n", sizeof(a[1]));

    strcpy(a[0]._priv.city, "New York");
    strcpy(a[0]._priv.zip, "10001");
    strcpy(a[0]._priv.first_name, "Adam");
    strcpy(a[0]._priv.last_name, "Johnsons");

    strcpy(a[1]._pub.city, "Miami");
    strcpy(a[1]._pub.zip, "33101");
    strcpy(a[1]._pub.first_name, "Adam");
    strcpy(a[1]._pub.last_name, "Johnsons");

    printf("private address: %s, %s, %s, %s\n", a[0]._priv.city, a[0]._priv.zip, a[0]._priv.first_name, a[0]._priv.last_name);
    printf("public address: %s, %s, %s, %s\n", a[1]._pub.city, a[1]._pub.zip, a[1]._pub.first_name, a[1]._pub.last_name);

    return EXIT_SUCCESS;
}