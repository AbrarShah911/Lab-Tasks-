# include <stdio.h>

int main() {
	
	int gradeScore;
	
	printf("What is your grade score? \n");
	scanf("%d", &gradeScore);
	
		if (gradeScore>=90 && gradeScore<=100){
			printf("A");
	}
		else if  (gradeScore>=80 && gradeScore<=89){
			printf("B");
		}
		else if (gradeScore>=70 && gradeScore<=79){
			printf("C");
		}
		else if (gradeScore>=60 && gradeScore<=69){
			printf("D");
		}
		else if (gradeScore<60){
			printf("F");
		}
		else{
			printf("Not a grade lil bro");
	}
	return 0;
}

