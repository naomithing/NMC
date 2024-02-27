# include <stdio.h>
# include <string.h>

struct Employee{
	char name[50];
	char post[50];
	double salary;
};

int filterEmployee(struct Employee employee[], int numEmployee, struct Employee filtered[]){
	int count = 0;
	int i;
	for (i=0; i<numEmployee; i++){
		if (employee[i].salary>10000){
			strcpy(filtered[count].name, employee[i].name);
			strcpy(filtered[count].post, employee[i].post);
			filtered[count].salary= employee[i].salary;
			count++;
		}
	}
	return count;
}
void main(){
	int maxEmployee = 10;
	struct Employee employee [maxEmployee];
	int numEmployee;
	
	printf("Enter details of 10 employees\n");
	int i;
	for (i=0; i<maxEmployee; i++){
		printf ("Employee %d\n", i+1);
		printf("Name: ");
		scanf("%s", employee[i].name);
		printf("Post: ");
		scanf("%s", employee[i].post);
		printf("Salary: ");
		scanf("%lf", &employee[i].salary);
	}
	
	struct Employee filteredEmployee[maxEmployee];
	int numFiltered = filterEmployee(employee, maxEmployee, filteredEmployee);
	
	printf("\nEmployee with slary exceeds 10,000");
	if (numFiltered > 0){
		int i;
		for (i = 0; i< numFiltered; i++){
			printf("Name: %s\n", filteredEmployee[i].name);
			printf("Post: %s\n", filteredEmployee[i].post);
			printf("Salary: %lf\n", filteredEmployee[i].salary);
		}
	}else{
		printf("No employee found with salary exceeding 10,000.\n");
	}
	
}
