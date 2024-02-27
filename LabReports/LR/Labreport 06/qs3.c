#include <stdio.h>
struct Employee{
	char empName[50];
	int age;
	double salary;
};
void readRecords(struct Employee emp[], int n){
	int i;
    for (i=0; i<n; i++){
        printf("Enter name of new employee %d: ",i+1);
        scanf("%s",&emp[i].empName);
        printf("Enter age of new employee %d: ",i+1);
        scanf("%d",&emp[i].age);
        printf("Enter salary of new employee %d: ",i+1);
        scanf("%f",&emp[i].salary);
    }
}
void main(){
	int n;
	printf("Enter number of new employees: ");
	scanf("%d", &n);
	
	struct Employee emp[n];
	FILE *fptr;
	fptr = fopen("employee.txt", "a");
	
	if (fptr == NULL){
        printf("File not found.");
    }
    readRecords(emp,n);
    int i;
    for (i=0; i<n; i++){
        fprintf(fptr, "\nName: %s",emp[i].empName);
        fprintf(fptr, "\nAge: %d",emp[i].age);
        fprintf(fptr, "\nSalary: %f",emp[i].salary);
    }
    fclose(fptr);
    printf("New employee details are appended to employee.txt");
}
