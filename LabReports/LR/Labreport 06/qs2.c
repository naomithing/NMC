#include <stdio.h>
struct Employee{
	char empName[50];
	int age;
	double salary;
}emp[3];
void main(){
	FILE *fptr;
	fptr = fopen("employee.txt", "r");
	
	if(fptr == NULL){
		printf("File not Found");
	}
	
	int i;
	char line[100];
	for(i=0; i<3;i++){
		printf("Reading information of student: %d\n", i+1);
		fgets(line, sizeof(line), fptr);

        // Read employee information
        fgets(line, sizeof(line), fptr); // Read Name line
        fscanf(line, "Name: %s", emp[i].empName);

        fgets(line, sizeof(line), fptr); // Read Age line
        fscanf(line, "Age: %d", &emp[i].age);

        fgets(line, sizeof(line), fptr); // Read Salary line
        fscanf(line, "Salary: %lf", &emp[i].salary);
        
        fgets(line, sizeof(line), fptr);
	}
	
	printf("\nEmployee Information: ");
	for(i=0; i<3; i++){
		printf("\nEmployee %d\n", i + 1);
		printf("\nName: %s", emp[i].empName);
		printf("\nAge: %d", emp[i].age);
		printf("\nSalary: %.2lf\n", emp[i].salary);
	}
	fclose(fptr);
}
