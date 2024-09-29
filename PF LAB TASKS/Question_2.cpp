#include <stdio.h>

int main(){
	
	int a,b,c;
	
	printf("Please enter the three angles you want to check for a triangle with: \n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	if ((a > 0) && (b>0) && (c>0)){
		
		if (a+b+c == 180){
			
			printf("This is indeed a triangle!");
			} else{
			printf("This aint a triangle chief!");
		}
		} else{
			printf("This aint a triangle chief!");
		}
	
	}