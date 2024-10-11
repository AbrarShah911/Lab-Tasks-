#include <stdio.h>


int main(){
	
	int num;
	int min, max;
	int myArray[30];
	
	
	for(int i = 0; i < 30; i++){
	printf("Please enter the number of the array: ");
	scanf("%d", &num);
	myArray[i] = num;
	}
	
	min = max = myArray[0];
	
	for(int x =0; (x < sizeof(myArray)/sizeof(myArray[0]));x++){
		if(myArray[x] > max){
			max = myArray[x];
		}
		if(myArray[x] < min){
			min = myArray[x];
		}
	}
	
	printf("%d \n", max);
	printf("%d", min);
	
	return 0;
}