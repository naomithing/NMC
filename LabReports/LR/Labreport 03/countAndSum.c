#include <stdio.h>
void countAndSum(int *arr, int size, int *count, int *total) {
    *count = 0;
    *total = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] % 5 == 0 && arr[i] % 2 != 0 && arr[i] % 3 != 0) {
            (*count)++;
            (*total) += arr[i];
        }
    }
}

void main() {
    int numbers[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int count, total_sum;
    
    countAndSum(numbers, size, &count, &total_sum);

    printf("Count of numbers divisible by 5 and not divisible by 2 and 3: %d\n", count);
    printf("Sum of numbers divisible by 5 and not divisible by 2 and 3: %d\n", total_sum);
}

