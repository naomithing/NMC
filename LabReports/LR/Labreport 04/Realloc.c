#include <stdio.h>
#include <stdlib.h>
int* addElements(int size, int *array, int newSize){
	int i;
	array = (int*)realloc(array, (size+newSize)*sizeof(int));
	if (array==NULL){
		printf("Memory allocation Failed");
		exit(0);
	}
	printf("Enter %d more elements to add in Array List: \n", newSize);
	for(i=size; i<(size+newSize); i++){
		scanf("%d", array+i);
	}
	return array;
}

void main(){
	int i, size;
	int *arr;
	
	printf("Enter the size of Array: ");
	scanf("%d", &size);
	
	arr = (int*)calloc(size, sizeof(int));
	
	if(arr == NULL){
		printf("Memory allocation Failed");
		exit(0);
	}
	
	printf("Enter the %d elements of Array: \n",size);
	for(i=0; i<size; i++){
		scanf("%d",arr+i);
	}
	
	printf("The %d elements of Array are: ", size);
	for(i=0; i<size; i++){
		printf("%d ", *(arr+i));
	}
	
	int newSize;
	printf("\nEnter number of additional elements to add: ");
	scanf("%d", &newSize);
	
	int *updatedElements=addElements(size, arr, newSize);
	
	printf("The updated %d elements of Array are: ",(size+newSize));
	for(i=0; i<size+newSize; i++){
		printf("%d ", *(updatedElements+i));
	}
	free(updatedElements);
}
