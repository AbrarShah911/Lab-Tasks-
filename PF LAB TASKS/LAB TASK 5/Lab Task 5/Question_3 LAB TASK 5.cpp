#include <stdio.h>

int main(){
	
	float score;
	printf("Please enter your score as a percentage: \n");
	scanf("%f", &score);
	
	(score >=90 && score <=100) ? printf("A"):(score >=80 && score <=89) ? printf("B"):	(score >=70 && score <=79) ? printf("C"):(score >=60 && score <=69) ? printf("D"):printf("F");
	
	return 0;
}