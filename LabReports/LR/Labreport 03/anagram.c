#include <stdio.h>
#include <string.h>

int areAnagrams(const char *str1, const char *str2){
	int length1= strlen(str1);
	int length2 = strlen(str2);
	int i;
	
	if(length1!= length2){
		return 0; 
	}
	
	int count1[256]= {0};
	int count2[256]={0};
	
	for (i =0; str1[i] != '\0'; i++){
		count1[(int)str1[i]]++;
	}
	
	for(i=0; str2[i]!='\0'; i++){
		count2[(int)str2[i]]++;
	}
	
	for(i=0;i<256; i++){
		if(count1[i]!=count2[i]){
			return 0;
		}
	}
	return 1;
	
}

void main(){
	char str1[100], str2[100];
	int i;
	printf("Enter first string: ");
	scanf("%s", &str1[i]);
	
	printf("Enter second string: ");
	scanf("%s", &str2[i]);
	
	printf("The first string is %s", str1);
	printf("\nThe second string is %s", str2);
	
	if (areAnagrams(str1, str2)){
		printf("\nThe strings '%s' and '%s' are Anagrams\n",str1,str2);
	}else{
		printf("\nThe strings '%s' and '%s' are not Anagrams\n",str1,str2);
	}
	
}
