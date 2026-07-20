#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 40960                                                   //  40,960 bytes buffer

int main(void) {
    FILE *src = fopen("lorem_ipsum.txt", "r");

    if (!src) {
        perror("fopen()");
        return EXIT_FAILURE;
    }

    char content_buffer[MAX_BUFFER_SIZE + 1];                                   //  no need to initialize this buffer by memset, ...

    //  read the whole file into RAM
    size_t bytes_read = fread(
        content_buffer,
        sizeof(char),
        sizeof(content_buffer),
        src
    );

    content_buffer[bytes_read] = '\0';
    fclose(src);

    //  tokenize the content by "." and "\n"
    char delmitter[] = ".\n";
    char *token = strtok(content_buffer, delmitter);
    int nbr_matches = 0;

    while(token != NULL) {
        printf("%d: %s\n", ++nbr_matches, token);
        token = strtok(NULL, delmitter);
    }

    return EXIT_SUCCESS;
}