#include <stdio.h>
#include <pthread.h>

void* threadOne(void *p){
	int i;
	for (i = 1; i <= 1000; i++){
		printf("Thread One: %d\n", i);
	}
}

void* threadTwo(void *p){
	int i;
	for (i = 1; i <= 1000; i++){
		printf("Thread Two: %d\n", i);
	}  
}

void main(){
	pthread_t id1; 
	pthread_t id2;
	pthread_create(&id1, NULL, threadOne, NULL);
	pthread_create(&id2, NULL, threadTwo, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
}
