#include <stdio.h>
#include <stdlib.h>
int maxInArray(int *array, int size){
	int max = *array;
	int i;
	for(i=0; i<size; i++){
		if (*(array+i)>max){
			max = *(array+i);
		}
	}
	return max;
}

void main(){
	int size, i, *arr;
	printf("Enter the size of Array: ");
	scanf("%d", &size);
	 
	arr = (int*)malloc (size*sizeof(int));
	 
	if(arr==NULL){
	 	printf("Memory Allocation Failed!");
	 	exit(0);
	}
	 
	printf("Enter the %d elements of Array: \n", size);
	for(i=0;i<size; i++){
	 	scanf("%d", arr+i);
	}
	 
	int maximum =maxInArray(arr, size);
	printf("The maximum element in Array List is %d", maximum);
	
	free(arr);	 
}
