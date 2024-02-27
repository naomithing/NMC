#include <stdio.h>
void main(){
	int n, i; 
	int tran = 0; 
	printf("Enter nth Number: ");
	scanf("%d", &n);
	for (i = 1; i<= n; i++){
		tran = tran + i;
	}
	printf("Triangular Number = %d", tran);
}
