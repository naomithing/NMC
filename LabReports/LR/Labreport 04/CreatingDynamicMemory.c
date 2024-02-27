# include <stdio.h>
# include <stdlib.h>
void createInt(int **ptr){
	*ptr = (int*)malloc(sizeof(int));
}

void createChar(char **ptr){
	*ptr = (char*)malloc(sizeof (char));
}

void createFloat(float **ptr){
	*ptr = (float*)malloc(sizeof(float));
}
 
void main(){
	int *intPtr;
	char *charPtr;
	float *floatPtr;
	
	createInt(&intPtr);
	createChar(&charPtr);
	createFloat(&floatPtr);
	
	if (intPtr==NULL|| charPtr ==NULL|| floatPtr ==NULL){
		printf("Memory Allocation Failed!");
		exit(0);
	}
	
	printf("Memory Allocation Successful");
	
	free(intPtr);
	free(charPtr);
	free(floatPtr);
}
