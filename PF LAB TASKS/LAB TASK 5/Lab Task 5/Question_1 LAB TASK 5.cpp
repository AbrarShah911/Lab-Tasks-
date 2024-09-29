#include <stdio.h>


int main() {
	
	
	int age;
	int citizen;
	printf("Please entrer your age: ");
	scanf("%d", &age);
	
	printf("Are you a citizen? 1 for yes and 0 for no: ");
	scanf("%d",&citizen);
	
	if (age >= 18 && citizen == 1) {
		printf("You are eligible to vote.\n");
	} else {
		printf("You are not eligible to vote.\n");
	}
return 0;
}