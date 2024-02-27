#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
    int id;
} ThreadData;

void* displayNumbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int i;
    for (i = data->start; i <= data->end; i++) {
        printf("Thread %d: %d\n", data->id, i);
    }
    pthread_exit(NULL);
}

void main() {
    int numThreads;
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadData* threadData = (ThreadData*)malloc(numThreads * sizeof(ThreadData));

    int numbersPerThread = 1000 / numThreads;
    int i;

    for (i = 0; i < numThreads; i++) {
        threadData[i].id = i + 1;
        threadData[i].start = i * numbersPerThread + 1;
        threadData[i].end = (i + 1) * numbersPerThread;

        pthread_create(&threads[i], NULL, displayNumbers, (void*)&threadData[i]);
    }
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    free(threadData);
}


