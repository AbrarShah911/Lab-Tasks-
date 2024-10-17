#include <stdio.h>
#include <stdbool.h>

int main(){

    int test[10];
    int temp;

    for(int i = 0; i < 10; i++){
        printf("Please enter a number: ");
        scanf("%d" , &test[i]);
    }

    printf("Before: ");
    for (int y = 0; y < 10; y++) {
        printf("%d ", test[y]);  
    }

    temp = test[0];

    for(int x = 0; x < 9; x++){
        test[x] = test [x+1];
    }

    test[9] = temp;

    printf("After: ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", test[j]);  
    }
    

    return 0;
}