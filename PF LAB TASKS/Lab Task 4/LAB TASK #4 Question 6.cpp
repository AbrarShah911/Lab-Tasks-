#include <stdio.h>

int main(){
	
	int x,y;
	
	printf("What is the first number?\n");
	scanf("%d" , &x);
	
	printf("What is the second number?\n");
	scanf("%d" , &y);
	
	if (x == y){
		printf("The numbers are equal!");
	}
	else{
	if (x>y){
		if (x>100){
			printf("The first number is significantly greater!");
		}else{
			printf("The first number is greater!");
		}
	}else{
		if(x<0){
			printf("The first number is smaller and negative!");
		}else{
			printf("The first number is smaller!");
		}
	
	}
	}

	return 0;
}