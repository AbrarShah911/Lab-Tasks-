#include <stdio.h>

int main(){
	
	int x;
	
	
	do {
	
	printf("Please enter a negative number: ");
	scanf("%d" , & x);
        if (x <= 0) {
            printf("You entered: %d\n", x);
        }
	}while(x < 0);
	
	return 0;
}