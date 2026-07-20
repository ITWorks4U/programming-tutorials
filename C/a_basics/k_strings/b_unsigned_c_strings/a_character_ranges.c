#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_ranges(int start_value, int end_value, bool is_char_only) {
    for(int i = start_value; i <= end_value; i++) {
        printf("| %3d (0X%X) : %3c\t ", i, i, (is_char_only ? (char) i : (unsigned char) i));

        if ((i + 129) % 8 == 0) {               //  eight values for each line has been printed
            printf("|\n");                      //  jump to the next line
        }
    }
}

int main(void) {
    display_ranges(                             //  ranges for signed char [-128..127]
        /*start_value:  */ -128,
        /*end_value:    */ 127,
        /*is_char_only: */ true
    );

    display_ranges(                             //  ranges for unsigned char [0..255]
        /*start_value:  */ 0,
        /*end_value:    */ 255,
        /*is_char_only: */ false
    );

    return EXIT_SUCCESS;
}