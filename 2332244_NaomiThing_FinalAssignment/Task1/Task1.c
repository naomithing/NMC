#include <stdio.h>
#include <stdlib.h>

void main(){
	
	//Initializing file pointers and variables
	FILE *file1, *file2, *file3, *file4, *file5;
	float x, y,sumX, sumY, sumXY, sumXX, a, b, inVal, result;
	int n = 0;
	
	/*For file opening, exception handling carried out.
	If a file is not found, print an error message and exit the program*/
	file1 = fopen("datasetLR1.txt", "r");
	if(file1==NULL){
		printf("File not found.");
		exit(0);
	}
	file2 = fopen("datasetLR2.txt", "r");
	if(file2==NULL){
		printf("No file found.");
		exit(0);
	}
	file3 = fopen("datasetLR3.txt", "r");
	if(file3==NULL){
		printf("No file found.");
		exit(0);
	}
	file4 = fopen("datasetLR4.txt", "r");
	if(file4==NULL){
		printf("File not found.");
		exit(0);
	}
	
	//Creating a new dataset file.
	file5 = fopen("datasetLR5.txt", "w");
	if(file5==NULL){
		printf("Error creating the fifth dataset text file.");
		exit(0);
	}
	
	//Calculate various sums and count of pairs of values read from a file.//
	while(fscanf(file1, "%f, %f", &x, &y)!=EOF){
		//Accumulate the values of x, y, xy, and xx.
		sumX += x;
		sumY += y;
		sumXY += (x*y);
		sumXX += (x*x);
		
		//Write the data to datasetLR5.txt.
		fprintf(file5, "%.2f, %.2f\n", x, y);
		
		n++; //Increase the count of pairs of values.
	}
	//Calculate various sums and count of pairs of values read from a file.//
	while(fscanf(file2, "%f, %f", &x, &y)!=EOF){
		//Accumulate the values of x, y, xy, and xx.
		sumX += x;
		sumY += y;
		sumXY += (x*y);
		sumXX += (x*x);
		
		//Write the data to datasetLR5.txt.
		fprintf(file5, "%.2f, %.2f\n", x, y);
		
		n++; //Increase the count of pairs of values.
	}
	//Calculate various sums and count of pairs of values read from a file.//
	while(fscanf(file3, "%f, %f", &x, &y)!=EOF){
		//Accumulate the values of x, y, xy, and xx.
		sumX += x;
		sumY += y;
		sumXY += (x*y);
		sumXX += (x*x);
		
		//Write the data to datasetLR5.txt.
		fprintf(file5, "%.2f, %.2f\n", x, y);
		
		n++; //Increase the count of pairs of values.
	}
	//Calculate various sums and count of pairs of values read from a file.//
	while(fscanf(file4, "%f, %f", &x, &y)!=EOF){
		//Accumulate the values of x, y, xy, and xx.
		sumX += x;
		sumY += y;
		sumXY += (x*y);
		sumXX += (x*x);
		
		//Write the data to datasetLR5.txt.
		fprintf(file5, "%.2f, %.2f\n", x, y);
		
		n++; //Increase the count of pairs of values.
	}
	
	//Close file pointers as they are not needed anymore
	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);
	fclose(file5); //Close the new dataset file
	
	//Calculate values of 'a' and 'b' using formula of linear regression.
	a = ((sumY*sumXX)-(sumX*sumXY))/((n*sumXX)-(sumX*sumX));
	b = ((n*sumXY)-(sumX*sumY))/((n*sumXX)-(sumX*sumX));
	
	//Print the calculated values of 'a' and 'b'
	printf("The values of 'a' and 'b' are: \n'a' = %f and 'b' = %f\n", a, b);
	
	//Print the regression line eqn.: y = bx+a
	printf("The equation of regression line is: ");
	printf("y = %.2f*x + %.2f\n\n", b, a);
	
	//User input for'x' to find the corresponding 'y' value.
	printf("Enter a value for 'x': ");
	scanf("%f", &inVal);
	result = b*inVal + a;
	printf("\nThe value of 'y' from the eqn. is: %.2f", result);
}
