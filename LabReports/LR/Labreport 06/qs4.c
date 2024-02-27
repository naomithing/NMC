#include <stdio.h>
#include <ctype.h>
#include <string.h>
void main(){
	char string[10];
	int count=0, i, num;
	FILE *fptrOdd, *fptrEven;
	fptrOdd = fopen("odd.txt","w");
	fptrEven = fopen("even.txt","w");
	while (1){
		count = 0;
		printf("Enter an integer: ");
		scanf("%s",string);
		for (i=0;i<strlen(string);i++){
			count = count + isdigit(string[i]);
		}
		if (count == strlen(string)){
			num = atoi(string);
			if (num%2==0){
				fprintf(fptrEven, "%s\n", string);
			} else {
				fprintf(fptrOdd,"%s\n",string);	
			}
		} else {
			if (strcmp("no",string) == 0){
				break;
			} else {
				printf("Please input a valid integer.\n");
			}
		}
	}
	fclose(fptrOdd);
	fclose(fptrEven);
}


