# include <stdio.h>
int searchElementsInArray(int *array, int size, int n){
	int i;
	for(i=0; i<size; i++){
		if (n==*(array+i)){
			return 1;
		}
	}
	return 0;
}
void main(){
	int i, size, n;

	printf("Enter size of Array: ");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter the %d elements of ArrayList: \n", size);
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
		
	printf("Enter element to search is arrayList: ");
	scanf("%d", &n);
	
	if (searchElementsInArray(arr,size,n)){
		printf("%d found in Array List", n);
	}else{
		printf("%d not found in ArrayList", n );
	}
	
}
