#include <stdio.h>
int findLargestElement(int *array, int size){
	int max = *array;
	int i;
	for(i = 1; i<size; i++){
		if(*(array+i)>max){
			max = *(array+i);
		}
	}
	return max;	
}

void main(){
	int arr []= {78, 95, 23, 67, 85};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("The elements of Array are: ");
	int i;
	for (i = 0; i<size; i++){
		printf("%d ", arr[i]);
	}
	int largest = findLargestElement(arr, size); 
	
	printf("\nThe largest element of Array is %d", largest);	
}
