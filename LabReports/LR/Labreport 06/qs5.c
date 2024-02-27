#include <stdio.h>
void main(){
	FILE *oddFile = fopen("Odd.txt", "r");
	FILE *evenFile = fopen("Even.txt", "r");
	FILE *numbers_file = fopen("numbers.txt", "w");
	
	if(oddFile == NULL && evenFile == NULL){
		printf("File doesn't exist.");
	}
	
	char c;
	fprintf(numbers_file, "Odd\n");
	while ((c=fgetc(oddFile))!=EOF){
		fputc(c, numbers_file);
	}
	fprintf(numbers_file, "Even\n");
	while((c=fgetc(evenFile))!=EOF){
		fputc(c, numbers_file);
	}
	fclose(oddFile);
	fclose(evenFile);
	fclose(numbers_file);
	printf("Contents from Odd.txt and Even.txt are copied to numbers.txt");
}
