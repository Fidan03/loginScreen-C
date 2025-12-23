#include <stdio.h>    // For printf, fopen, fscanf
#include <conio.h>    // For getch() (Windows specific)
#include <string.h>   // For strcmp()

int main() {
    char ch;                     // Stores each typed character
    char pass[20];               // User-entered password
    char saved_pass[20];         // Password read from file
    int i = 0;                   // Index for password array

    printf("Enter password: ");

    // Loop to read password character by character
    while (1) {
        ch = getch();            // Read character without echoing

        // If ENTER key is pressed
        if (ch == 13) {
            pass[i] = '\0';      // End string
            printf("\n");
            break;
        }

        // If BACKSPACE key is pressed
        if (ch == 8) {
            if (i > 0) {
                i--;             // Move back in array
                printf("\b \b"); // Erase '*' from screen
            }
            continue;
        }

        // Store character if space is available
        if (i < (int)sizeof(pass) - 1) {
            pass[i++] = ch;      // Store character
            printf("*");         // Print '*' instead of character
        }
    }

    // Open password file
    FILE *ptr = fopen("password.txt", "r");
    if (!ptr) {
        perror("fopen");
        return 1;
    }

    // Read saved password from file
    if (fscanf(ptr, "%19s", saved_pass) != 1) {
        fprintf(stderr, "Failed to read saved password\n");
        fclose(ptr);
        return 1;
    }
    fclose(ptr);

    // Debug print (should be removed in real programs)
    printf("Saved password %s\n", saved_pass);

    // Compare entered password with saved password
    if (strcmp(pass, saved_pass) == 0) {
        printf("Logged in\n");
    } else {
        printf("Incorrect\n");
    }

    return 0;
}
