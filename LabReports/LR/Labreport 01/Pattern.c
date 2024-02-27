#include <stdio.h>
void main(){
	int i=1, j=1;
	char start = '@';
	for (i = 1; i<=5; i++){
		for (j=1; j<=i; j++){
			printf("%c", start+i);
		}
		printf("\n");
	}
}
