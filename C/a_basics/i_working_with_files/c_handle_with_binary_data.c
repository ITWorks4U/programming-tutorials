/*
* In contrast to ASCII / UTF-8 text, a binary data is going to handle
* in a different way. There, fwrite, as well as, fread can and shall be used.
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10                      //  expecting 10 bytes for a buffer
#define BINARY_FILE "outsourced.dat"

typedef unsigned char byte_t;               //  take a look to: chapter b:l_your_own_datatype

void write_to_binary_file(void) {
    FILE *destination = fopen(BINARY_FILE, "wb");
    if (!destination) {
        perror("failed to open file");
        return;
    }

    //  assuming, this data (from any source) exists:
    byte_t data[] = {0xff, 0xA0, 0x45, 0xFF, 0x55, 0xAA, 0x19, 0x46, 0x65, 0x20};
    size_t length = sizeof(data) / sizeof(data[0]);

    size_t bytes_written = fwrite(data, sizeof(byte_t), length, destination);
    fclose(destination);

    #ifdef _WIN32
    printf("wrote %llu bytes into %s...\n", bytes_written, BINARY_FILE);
    #else
    printf("wrote %lu bytes into %s...\n", bytes_written, BINARY_FILE);
    #endif
}

void read_from_binary_file(void) {
    FILE *source = fopen(BINARY_FILE, "rb");
    if (!source) {
        perror("failed to open file");
        return;
    }

    byte_t buffer[BUFFER_SIZE];             //  this buffer contains any garbage until fread() function has been used
    size_t bytes_read = fread(buffer, sizeof(byte_t), sizeof(buffer), source);
    fclose(source);

    #ifdef _WIN32
    printf("read %llu bytes from %s...\n", bytes_read, BINARY_FILE);
    #else
    printf("read %lu bytes from %s...\n", bytes_read, BINARY_FILE);
    #endif

    printf("\ndata from source: ");

    for(size_t i = 0; i < sizeof(buffer); i++) {
        printf("0x%2X ", buffer[i]);
    }

    printf("\n");
}

int main(void) {
    write_to_binary_file();
    read_from_binary_file();

    return EXIT_SUCCESS;
}