#include <stdio.h>
int cube(int x){
	return x*x*x;
}
void main(){
	int num1;
	printf("Enter a number: ");
	scanf("%d", &num1);
	int result = cube(num1);
	printf("%d", result);
}
