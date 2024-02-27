#include <stdio.h>
struct student_info{
	char name [50];
	int age;
	char dob[20];
};

struct Student{
	int rollNo;
	double marks;
	struct student_info info;
}std[3];


void main(){
//	struct Student std[3];
	printf("Enter the information of three students\n");
	int i;
	for(i=0; i<3; i++){
		printf("Enter details for student %d\n",i+1);
		printf("Name: ");
		scanf("%s", std[i].info.name);
		
		printf("Age: ");
		scanf("%d", &std[i].info.age);
		
		printf("Date of Birth(DD/MM/YYYY): ");
		scanf("%s", std[i].info.dob);
		
		printf("Roll Number: ");
		scanf("%d", &std[i].rollNo);
		
		printf("Marks: ");
		scanf("%lf", &std[i].marks);
		
		printf("\n");
	}
	
	printf("Details of Students: \n");
	for(i=0; i<3; i++){
		printf("Student %d:\n", i+1);
		printf("Name: %s\n", std[i].info.name);
		printf("Age: %d\n", std[i].info.age);
		printf("Date of Birth: %s\n", std[i].info.dob);
		printf("Roll Number: %d\n", std[i].rollNo);
		printf("Marks: %lf\n", std[i].marks);
		printf("\n");
	}
}

