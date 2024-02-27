#include <stdio.h>
void printUniqueElements(int *arr, int size) {
    printf("Unique elements in the array: ");
    int i,j;
    for (i = 0; i < size; i++) {
        int isUnique = 1;

        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void main() {
    int arr[] = {1, 2, 4, 8, 4, 2, 4, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printUniqueElements(arr, size);
}

