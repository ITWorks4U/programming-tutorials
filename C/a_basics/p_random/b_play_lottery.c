#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else

// Would you like to play lottery? Receive 6 random and unique numbers
// from 49 possible numbers. Perhaps this might be your next tip. ;-)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// contains six of all 49 lottery numbers between 1 and 49
// where "-1" is a placeholder for not defined yet
int lottery_array[] = {-1, -1, -1, -1, -1, -1};

// check, if the given number has already been
// put into the lottery array to avoid to add
// this same number again
bool has_number_already_picked_up(int number) {
    for(int i = 0; i < 6; i++) {
        if(lottery_array[i] == number) {
            return true;
        }
    }

    return false;
}

int main(void) {
    srand(time(NULL));
    int counter = 0;

    do {
        int random_number = (rand() % 49) + 1;

        if(!has_number_already_picked_up(random_number)) {
            lottery_array[counter] = random_number;
            counter++;
        }
    } while (counter < 6);

    printf("your picked lottery numbers: { ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", lottery_array[i]);
    }
    printf("} - super number: %d\n", (rand() % 10));

    return EXIT_SUCCESS;
}
#endif