#include <stdio.h>
#include <pthread.h>

void* threadOne (void* p){
	int i, j;
	int start =1, end = 250;
	for (i = start; i<=end; i++){
		for (j=2; j<=i-1; j++){
			if (i%j ==0){
				break;
			}
		}
		if(j == i){
			printf("Thread 1: %d\n",i);
		}
	}
}

void* threadTwo (void* p){
	int i, j;
	int start =251, end = 500;
	for (i = start; i<=end; i++){
		for (j=2; j<=i-1; j++){
			if (i%j ==0){
				break;
			}
		}
		if(j == i){
			printf("Thread 2: %d\n",i);
		}
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
