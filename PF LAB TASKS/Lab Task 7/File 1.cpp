#include <stdio.h>
#include <stdbool.h>


int main(){
	
	int num;
	int size;
	int sum =0;
	int myArray[20];
	
	
	for(int i = 0; i < 20; i++){
	printf("Please enter the number of the array: ");
	scanf("%d", &num);
	myArray[i] = num;
	}
	
	for(int x = 20; x > 0 ;x--){
		printf("%d \n", myArray[x]);
	}
	return 0;
}