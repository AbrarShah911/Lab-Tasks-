#include <stdio.h>
#include <stdbool.h>

int main(){

    int test[12];
    int addTest[6];
    int temp;
    int i = 0;

    for(int x = 0; x < 12; x++){
        printf("Please enter a number: ");
        scanf("%d" , &test[x]);
    }

    printf("Original Array: ");
    for (int y = 0; y < 12; y++) {
        printf("%d ", test[y]);  
    }

    while(i <= 12 && i+1 < 12){
        temp = test[i] + test[i+1];
        addTest[i/2] = temp;
        i+=2;
    }

    printf("Add Array: ");
    for (int j = 0; j < 6; j++) {
        printf("%d ", addTest[j]);  
    }

    return 0;
}