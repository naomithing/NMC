#include <stdio.h>
struct Employee{
	char name[50];
	double salary;
	float hours_worked;
}emp[5];

void main(){
	printf("Enter details of the 5 Employee\n");
	int i;
	for(i=0; i<5; i++){
		printf("Employee %d\n", i+1);
		printf("Name: ");
		scanf("%s", emp[i].name);
		printf("Salary: ");
		scanf("%lf", &emp[i].salary);
		printf("Hours worked per day: ");
		scanf("%f", &emp[i].hours_worked);
		printf("\n");
	}
	
	for(i=0; i<5; i++){
		if (emp[i].hours_worked>=12){
			emp[i].salary += 150;
		}else if(emp[i].hours_worked >= 10){
			emp[i].salary += 100;
		}else if(emp[i].hours_worked >= 8){
			emp[i].salary += 50;
		}else{
			emp[i].salary = emp[i].salary;
		}
	}
	
	printf("Employee Details\n");
	for(i=0; i<5; i++){
		printf("Employee %d\n", i+1);
		printf("Name: %s\n", emp[i].name);
		printf("Final Salary: %.2lf\n", emp[i].salary);
		printf("\n");
	}
}
