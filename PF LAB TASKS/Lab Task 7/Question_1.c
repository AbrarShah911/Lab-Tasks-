#include <stdio.h>
#include <stdbool.h>

int main(){

    int num;
    bool found = false;
    int test[] = {32,45,23,67,3,65,2,79,4,3,7,8,9,524,3};
    int i;

    printf("PLease enter the number to be found: ");
    scanf("%d" , &num);

    for(i = 0; i < sizeof(test)/sizeof(test[0]); i++){

        if(test[i] == num){
            found = true;
            break;
        }

    }

    if(found == true){
        printf("%d was found at: %d" , num , i);
    }else{
        printf("Your number was not found.");
    }

    return 0;
}