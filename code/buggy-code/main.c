#include <stdio.h>


typedef struct User {
    char username[16];
    char is_admin;
} User;

int main(int argc, char** argv) {

    User logged_user;

    printf("Hi, and welcome to the program. Who are you?\n");

    // This is not secure
    scanf("%s", &logged_user.username);

    printf("Please %s, insert the password:\n", logged_user.username);

    char password[17];

    // This is secure
    scanf("%16s", &password);

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