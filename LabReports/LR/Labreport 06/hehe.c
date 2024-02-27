#include <stdio.h>

int main() {
    FILE *fptr;
    char c;
    fptr = fopen("employee.txt", "r");
    
    if (fptr == NULL) {
        printf("File not Found\n");
        return 1;
    }
    
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    
    fclose(fptr);
    return 0;
}

