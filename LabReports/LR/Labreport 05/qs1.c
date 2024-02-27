# include <stdio.h>
struct Student{
	char name[50];
	int roll;
	double marks;
}students[10];

void readRecords(struct Student students[]){
	printf("Enter information of 10 students : \n");
	int i;
	for (i=0; i<10; i++){
		printf("Student %d\n", i+1);
		printf("Name: ");
		scanf("%s", students[i].name);
		
		printf("Roll Number: ");
		scanf("%d", &students[i].roll);
		
		printf("Marks: ");
		scanf("%lf", &students[i].marks);
		
		printf("\n");
	}
}

void displayRecords(struct Student students[]){
	printf("Info of 10 Students.");
	int i;
	for(i=0; i<10; i++){
		printf("\nStudent: %d\n", i+1);
		printf("Name: %s", students[i].name);
		printf("\n");
		printf("Roll Number: %d", students[i].roll);
		printf("\n");
		printf("Marks: %.2lf", students[i].marks);
		printf("\n");
	}		
}

void main(){
	//struct Student students[10];
	readRecords(students);
	displayRecords(students);
}
