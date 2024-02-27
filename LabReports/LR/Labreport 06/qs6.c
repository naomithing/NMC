#include <stdio.h>
void main (){
	FILE  *sumFile = fopen("sum.txt", "a");
	if (sumFile == NULL){
		printf("Error");
	}
	int num, sum =0;
	printf("Enter an integer or 0 to stop \n");
	while(1){
		printf("Enter an integer: ");
		scanf("%d", &num);
		
		if(num==0){
			break;
		}
		sum += num;
	}
	fprintf(sumFile, "sum of integers: %d\n", sum);
	
	fclose(sumFile);
	printf("Sum has been appented to sum.txt.\n");
}
