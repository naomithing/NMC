#include <stdio.h>
void main(){
	double finalScore;
	
	printf("Enter your final score: ");
	scanf("%lf", &finalScore);
	
	if(finalScore >= 80){
		printf("Congralutions! You have achieved Distinction. \n");
	}else if (finalScore >= 60){
		printf("Congralutions! You have achieved First Division. \n");
	}else if (finalScore >= 50){
		printf("Congralutions! You have achieved Second Division. \n");		
	}else if (finalScore >= 40){
		printf("Congralutions! You have achieved Third Division. \n");
	}else{
		printf("Sorry! You have failed the Module. \n");
	}
}

