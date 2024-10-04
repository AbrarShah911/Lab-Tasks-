#include <stdio.h>

int main(){
	
	int n;
	int factorial = 1;
	
	printf("Please enter the number: \n");
	scanf("%d" , &n);
	
	if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
	
	for(int i = n; i > 0; i--){
		factorial *= i;
	}
	
	
	printf("The factorial is: %d" , factorial);

	return 0;	
}