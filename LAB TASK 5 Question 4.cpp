#include <stdio.h>

int main(){
	
	int price;
	char membership;
	
	
	printf("Please enter the price: \n");	
	scanf("%d", &price);
	
	printf("Please tell me if you is member or no? saying y or n: \n");
	scanf(" %c", &membership);
	
	(price>100 && (membership == 'y' || membership == 'Y')) ?
	 printf("You hvcae have gotten a dicount"):
	  printf("You have no discount");
	
	return 0;
}