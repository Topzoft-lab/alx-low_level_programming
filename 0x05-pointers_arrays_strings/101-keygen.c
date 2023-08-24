#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

// Function to generate a random character from a set of valid characters
char generateRandomChar() {
    const char validChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int validCharsCount = sizeof(validChars) - 1;  // Exclude the null terminator
    int randomIndex = rand() % validCharsCount;
    return validChars[randomIndex];
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    printf("Generated Password: ");
    for (int i = 0; i < PASSWORD_LENGTH; ++i) {
        char randomChar = generateRandomChar();
        putchar(randomChar);
    }
    putchar('\n');

    return 0;
}
