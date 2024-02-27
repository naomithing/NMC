#include <stdio.h>
struct Limits {
	int lowerLimit;
	int upperLimit;
}userlimits;
void display(struct Limits limit){
	printf("Numbers between %d and %d are: ", limit.lowerLimit, limit.upperLimit);
	int i;
	for(i=limit.lowerLimit+1; i<limit.upperLimit; i++){
		printf("%d ", i);
	}
	printf("\n");
}
void main(){
	//struct Limits userlimits;
	
	printf("Enter lower limit: ");
	scanf("%d", &userlimits.lowerLimit);
	
	printf("Enter upper limit: ");
	scanf("%d", &userlimits.upperLimit);
	
	display(userlimits);
}
