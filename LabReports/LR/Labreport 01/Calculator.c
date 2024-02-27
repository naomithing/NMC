#include <stdio.h>
void main(){
	char operator;
	double num1, num2, result;
	
	printf("Enter an Operator(+, -, *, /, %%): ");
	scanf(" %c", &operator);
	
	printf("Enter First Number: ");
	scanf("%lf", &num1);
	
	printf("Enter Second Number: ");
	scanf("%lf", &num2);
	
	switch(operator){
		case '+':
			result = num1 + num2;
			printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
			break;
		case '-' :
			result = num1 - num2;
			printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
			break;
		case '*':
			result = num1 * num2;
			printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
			break;
		case '/':
			if (num2 != 0){
				result = num1 / num2;
				printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
			}else{
				printf("Error! Division by 0 is not allowed\n");
			}
			break;
		case '%':
			if (num2 != 0){
				result = (int)num1 % (int)num2;
				printf("Result: %.2lf %% %.2lf = %.2lf\n", num1, num2, result);
			}else{
				printf("Error! Division by 0 is not allowed for Modulo operation\n");
			}
			break;
		default:
			printf("Invalid Oprator is Entered\n");			
	}
}
