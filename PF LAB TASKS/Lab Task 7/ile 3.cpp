#include <stdio.h>

int main(){

	int num;
	int size;
	int sum =0;
	int myArray[15];
	
	
	for(int i = 0; i < 15; i++){
	printf("Please enter the number of the array: ");
	scanf("%d", &num);
	myArray[i] = num;
	}
	
	for(int x =0; (x < sizeof(myArray)/sizeof(myArray[0]));x++){
		sum += myArray[x];
	}
	
	printf("%d",sum);
	
	return 0;
}