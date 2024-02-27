#include <stdio.h>
void main(){
	int number, digit, sum=0;
	
	printf("Enter number except single digit: ");
	scanf("%d", &number);
	
	while (number > 0){
		digit = number % 10;
		sum += digit;
		number /= 10;
	}
	printf("The sum of digits is: %d\n", sum);
}
