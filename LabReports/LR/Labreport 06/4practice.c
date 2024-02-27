#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main(){
	char string [50];

	FILE *fptrOdd, *fptrEven;
	fptrOdd = fopen("Odd.txt","w");
	fptrEven = fopen("Even.txt", "w");
	
	while (1){
		int count=0, i, num;
		printf("Enter Integer or no to stop the program: ");
		scanf("%s", string);
		for(i=0; i<strlen(string); i++){
			count += isdigit(string[i]);
		}
		if (count == strlen(string)){
			num= atoi(string);
			if (num%2==0){
				fprintf(fptrEven, "%s\n", string);
			}else{
				fprintf(fptrOdd, "%s\n", string);
			}
		}else{
			if(strcmp("no", string)==0){
				printf("Program Ends\n");
				break;
			}else{
				printf("Please enter a valid integer.\n");
			}
		}
	}
	fclose(fptrOdd);
	fclose(fptrEven);
	printf("Entered even numbers are in Even.txt file and Odd numbers are in Odd.txt file");
}
