# include <stdio.h>
# include <stdlib.h>
struct Employee{
	char name[50];
	double salary;
	float hours_worked;
};
double highestSalary(struct Employee *emp, int n){
	double maxSalary = emp[0].salary;
	int i;
	for(i = 0; i<n; i++){
		if(emp[i].salary>maxSalary){
			maxSalary = emp[i].salary;
		}
	}
	return maxSalary;
}
int main(){
	int n;
	printf("Enter the number of Employee: ");
	scanf("%d", &n);
	struct Employee *emp = (struct Employee*)malloc (n*sizeof(struct Employee));
	if(emp == NULL){
		printf("Memory Allocation Failed");
		return 1;
	}
	
	int i;
	for(i=0; i<n; i++){
		printf("Enter details for Employee %d\n", i+1);
		printf("Name: ");
		scanf("%s", emp[i].name);
		printf("Salary: ");
		scanf("%lf", &emp[i].salary);
		printf("Hours worked per day: ");
		scanf("%f", &emp[i].hours_worked);
		printf("\n");
	}
	double maximumSalary = highestSalary(emp, n);
	printf("The highest salary among the employees is: $%lf", maximumSalary);
	free(emp);
	return 0;
}
