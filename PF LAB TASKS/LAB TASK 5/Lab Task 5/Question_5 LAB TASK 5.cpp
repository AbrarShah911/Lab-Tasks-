#include <stdio.h>

int main() {
    int num;
    
    printf("Please enter the number you want to check for even or odd: \n");
    scanf("%d", &num);
    
    if ((num ^ 1) == (num +1)){
        printf("The number is even");
    }else{
        printf("The number is odd");
    }

    return 0;
}