#include <stdio.h>
int sortInAscending(int *array, int size){
	int i, j;
	for(i=0; i<size; i++){
		for(j=1; j<size-i; j++){
			if(*(array+j-1)>*(array+j)){
				*(array+j-1)=*(array+j-1)+*(array+j);
				*(array+j)= *(array+j-1)-*(array+j);
				*(array+j-1)= *(array+j-1)-*(array+j);
			}
		}
	}
}
void main(){
	int size, i;
	printf("Enter the size of Array: ");
	scanf("%d", &size);
	
	int arr [size];
	
	printf("\nEnter the %d elements of Array: ", size);
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("\nThe elements of Array are: ");
	for(i= 0; i<size; i++){
		printf("%d ", arr[i]);
	}
	
	sortInAscending(arr, size);
	
	printf("\nArray after sorting in Ascending order are: ");
	for(i = 0; i<size; i++){
		printf("%d ", arr[i]);
	}
}
