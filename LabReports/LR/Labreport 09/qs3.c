#include <stdio.h>
#include <pthread.h>

void* threadOne(void *p){
	int i;
	for (i = 1; i <= 200; i++){
		printf("Thread One: %d\n", i);
	}
}

void* threadTwo(void *p){
	int i;
	for (i = 201; i <= 400; i++){
		printf("Thread Two: %d\n", i);
	}  
}

void* threadThree(void *p){
	int i;
	for (i = 401; i <= 600; i++){
		printf("Thread Three: %d\n", i);
	}  
}

void* threadFour(void *p){
	int i;
	for (i = 601; i <= 800; i++){
		printf("Thread Four: %d\n", i);
	}  
}

void* threadFive(void *p){
	int i;
	for (i = 801; i <= 1000; i++){
		printf("Thread Five: %d\n", i);
	}  
}

void main(){
	pthread_t id1, id2, id3, id4, id5; 
	pthread_create(&id1, NULL, threadOne, NULL);
	pthread_create(&id2, NULL, threadTwo, NULL);
	pthread_create(&id3, NULL, threadThree, NULL);
	pthread_create(&id4, NULL, threadFour, NULL);
	pthread_create(&id5, NULL, threadFive, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);
	pthread_join(id4, NULL);
	pthread_join(id5, NULL);
}
