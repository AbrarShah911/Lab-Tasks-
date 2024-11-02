#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

    char students[6][20] = {"Harry","Potter","Hermoine", "Grainger", "Ron","Weasly"};
    char inp[20];
    bool found = false;

    printf("Please enter the name you want to find amongst the names of students: ");
    scanf("%s", &inp);

    for(int i = 0; i<6;i++){
        if( strcmp(students[i],inp) == 0){
            found = true;
            break;
        }
    }

    if(found == false){
        printf("Not Found");
    }else{
        printf("Found");
    }


    return 0;
}