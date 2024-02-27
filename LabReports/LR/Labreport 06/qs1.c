#include <stdio.h>
struct Employee{
	char empName[50];
	int age;
	double salary;
}emp[3];

void readRecords(struct Employee emp[]){
	printf("Enter details of 3 students: ");
	int i;
	for(i=0; i<3; i++){
		printf("Student %d", i+1);
		printf("\nName: ");
		scanf("%s", &emp[i].empName);
		printf("Age: ");
		scanf("%d", &emp[i].age);
		printf("Salary: ");
		scanf("%lf", &emp[i].salary);
		printf("\n");
	}
}

void main(){
	FILE *fptr;
	fptr = fopen("employee.txt", "w");
	
	if(fptr == NULL) {
		printf("File not found!");
	}
	readRecords(emp);
	int i;
	for(i=0; i<3; i++){
		printf("\nName: %s", emp[i].empName);
		printf("\nAge: %d", emp[i].age);
		printf("\nSalary: %.2lf", emp[i].salary);
		
		fprintf(fptr, "Employee %d\n", i + 1);
        fprintf(fptr, "Name: %s\n", emp[i].empName);
        fprintf(fptr, "Age: %d\n", emp[i].age);
        fprintf(fptr, "Salary: %.2lf\n\n", emp[i].salary);
	}
	fclose(fptr);
}
