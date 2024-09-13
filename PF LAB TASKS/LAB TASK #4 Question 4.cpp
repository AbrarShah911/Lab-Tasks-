# include <stdio.h>


int main(){
	
	int n;
	
	printf("What is n? \n");
	scanf("%d", &n);
	
	switch (n){

	case 1:
		printf("one");
		break;
	case 2:
		printf("two");
		break;
	case 3:
		printf("three");
		break;
	case 4:
		printf("four");
		break;
	case 5:
		printf("five");
		break;
	case 6:
		printf("six");
		break;
	case 7:
		printf("seven");
		break;
	case 8:
		printf("eight");
		break;
	case 9:
		printf("nine");
		break;
	case 10:
		printf("ten");
		break;
	case 11:
		printf("elevn");
		break;
	case 12:
		printf("twelve");
		break;
	case 13:
		printf("thirteen");
		break;
	case 14:
		printf("fourteen");
		break;
	case 15:
		printf("fifteen");
		break;
	case 16:
		printf("sixteen");
		break;
	case 17:
		printf("seventeen");
		break;
	case 18:
		printf("eighteen");
		break;
	case 19:
		printf("nineteen");
		break;
	case 20:
		printf("twenty");
		break;
	}
	
	if (n>20){
		printf("The number is greater than twenty!");
	}
	return 0;
}