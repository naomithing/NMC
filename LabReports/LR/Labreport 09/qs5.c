#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int id;
} ThreadData;

void* displayOddNumbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int i;

    for (i = data->start; i <= data->end; i += 2) {
        printf("Thread %d: %d\n", data->id, i);
    }

    pthread_exit(NULL);
}

int main() {
    int numThreads;

    // Get the number of threads from the user
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadData* threadData = (ThreadData*)malloc(numThreads * sizeof(ThreadData));

    int numbersPerThread = 1000 / numThreads;
    int i;

    // Create threads and assign them ranges of odd numbers
    for (i = 0; i < numThreads; i++) {
        threadData[i].id = i + 1;
        threadData[i].start = i * numbersPerThread + 1;
        threadData[i].end = (i + 1) * numbersPerThread;

        // Adjust the end if the last thread
        if (i == numThreads - 1) {
            threadData[i].end = 1000;
        }

        pthread_create(&threads[i], NULL, displayOddNumbers, (void*)&threadData[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(threadData);

    return 0;
}

