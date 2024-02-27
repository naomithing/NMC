#include <stdio.h>
int sumOfElements(int *array, int size) {
    int sum = 0;
    int i;
    
    for (i = 0; i < size; i++) {
        sum += *(array + i);
    }
    
    return sum;
}

void main() {
    int size, i;
    
    printf("Enter the size of an Array: ");
    scanf("%d", &size);
    
    int a[size];
    
    printf("Enter the %d elements of Array: \n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    
    int result = sumOfElements(a, size);
    
    printf("The sum of all elements of array is %d\n", result);

}

