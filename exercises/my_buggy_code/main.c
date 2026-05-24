#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct User {
    char username[16];
    char is_admin;
} User;


int main(int argc, char** argv) {

    User logged_user;

    printf("Hi, and welcome to the automated version of the super nefarious db\n");

    char* credential_path = argv[1];

    int fd = open(credential_path, O_RDONLY);

    if (!fd) {
        printf("No credentials were found\n");
        return 0;
    }

    // Read credentials
    int exit = 0;
    int buff_step = 8;
    int buffer_size = buff_step;
    char* buffer = malloc(buffer_size * sizeof(char));

    while (!exit) {

        int bytes_read = read(fd, buffer + (buffer_size - buff_step), buff_step);

        // Read enough bytes
        if (bytes_read < buff_step) {
            exit = 1;
            buffer[buffer_size] = 0;
            continue;
        }

        // Reallocate new space
        buffer_size += buff_step;
        char* tmp_buf = realloc(buffer, buffer_size);

        if (tmp_buf == NULL) {
            printf("Something bad really happened\n");
            return 1;
        }

        buffer = tmp_buf;

    }

    printf("User input: %s\n", buffer);

    // Split in user and password

    exit = 0;
    int separator_position = 0;
    while (!exit) {

       
        // Count
        if (buffer[separator_position] == ' ') {
            exit = 1;
            continue;
        }

        separator_position += 1;

        if (!(separator_position < buffer_size)) {
            printf("There's no separator\n");
            return 0;
        }

    }

    char password[17];

    strncpy(logged_user.username, buffer, separator_position);
    strncpy(password, buffer + (separator_position + 1), 16);

    password[16] = 0;

    close(fd);
    free(buffer);


    if (password == "admin_0101" && logged_user.username == "admin") {
        logged_user.is_admin = 1;
    }


    if (!logged_user.is_admin) {
        printf("Sorry %s, but you need to be an admin to use this program\n", logged_user.username);
        return 0;
    }

    printf("Hi %s, and welcome to this super secret program, if only it was completed\n", logged_user.username);
    return 0;


}