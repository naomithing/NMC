#include <stdio.h>
#include <stdlib.h>
void arrayAddition(int *array1, int *array2, int *addArray, int size){
	int i;
	for (i=0;i<size;i++){
		*(addArray+i)=*(array1+i)+*(array2+i);
	}
}
void main(){
	int i,size;
	int *array1, *array2, *addArray;
	
	printf("Enter the size of Array: ");
	scanf("%d", &size);
	
	array1 = (int*)calloc(size, sizeof(int));
	array2 = (int*)calloc(size, sizeof(int));
	addArray = (int*)calloc(size, sizeof(int));
	
	if (array1==NULL || array2 == NULL || addArray == NULL){
		printf("Memory Allocation Failed!");
		exit(0);
	}
	
	printf("Enter %d elements for first Array: \n", size);
	for(i=0; i<size; i++){
		scanf("%d", array1+i);
	}
	
	printf("Enter %d elements for second Array: \n", size);
	for(i=0; i<size; i++){
		scanf("%d", array2+i);
	}
	
	arrayAddition(array1, array2, addArray, size);
	printf("The addition of corresponding elements of two array is:" );
	for (i=0; i<size; i++){
		printf("%d ", *(addArray+i));
	}
	free(array1);
	free(array2);
	free(addArray);
}
