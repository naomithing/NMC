#include <stdio.h>
#define ROWS 3
#define COLS 3

void addArrays(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int result[ROWS][COLS]) {
	int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void displayArray(int arr[ROWS][COLS]) {
	int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int array1[ROWS][COLS], array2[ROWS][COLS], result[ROWS][COLS];

    printf("Enter elements of first array (%d x %d):\n", ROWS, COLS);
    int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &array1[i][j]);
        }
    }

    printf("Enter elements of second array (%d x %d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &array2[i][j]);
        }
    }
    addArrays(array1, array2, result);

    printf("Resultant array after addition:\n");
    displayArray(result);

}

