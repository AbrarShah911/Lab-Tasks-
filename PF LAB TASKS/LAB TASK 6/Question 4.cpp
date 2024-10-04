#include <stdio.h>

int main(){
	
	int x;
	
	printf("Please enter a number: ");
	scanf("%d" , &x);
	
	while (x != 0){
		printf("Please enter a number: ");
		scanf("%d" , &x);
		printf("%d " , x);
	}
	
	return 0;
}