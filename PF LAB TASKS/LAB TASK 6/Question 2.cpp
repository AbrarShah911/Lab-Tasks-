#include <stdio.h>

int main(){
	
	int n, x;
	
	x = 0;
	
	printf("Please enter the limit for printing the even numbers: ");
	scanf("%d" , &n);
	
	while (x <= n){
		if(x%2 == 0){
			printf("%d " , x);

		}
		x++;

	}
	
	return 0;
	
}