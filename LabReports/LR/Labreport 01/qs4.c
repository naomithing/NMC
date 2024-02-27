#include <stdio.h>

void main() {
    char character;
    printf("Enter a character (Press Enter to exit): ");

    while (1) {
        scanf("%c", &character); 
        
        if (character == '\n') {
            break; 
        }
        if (character >= 'A' && character <= 'Z') {
            character = character + ('a' - 'A');
        }
        printf("Lowercase character: %c\n", character);

        while (getchar() != '\n');
    }   
}

