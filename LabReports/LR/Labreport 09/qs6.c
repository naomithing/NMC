#include <stdio.h>
#include <pthread.h>

int a[] = {1, 2, 3, 4, 6, 8, 9, 13};
int thread_max = 4;
int key = 9;
int size = sizeof(a) / sizeof(int);
int f = 0;
int current_thread = 0;

void* thread_search(void* p) {
    int i;
    int num = current_thread++;
    for (i = num * (size / 4); i < (num + 1) * (size / 4); i++) {
        if (a[i] == key) {
            f = 1;
        }
    }
    pthread_exit(NULL);
}

void main() {
    pthread_t thread[thread_max];
    int i;
    for (i = 0; i < thread_max; i++) {
        pthread_create(&thread[i], NULL, thread_search, NULL);
    }
    for (i = 0; i < thread_max; i++) {
        pthread_join(thread[i], NULL);
    }
    if (f == 1) {
        printf("Element Found\n");
    } else {
        printf("Element not found\n");
    }
}

