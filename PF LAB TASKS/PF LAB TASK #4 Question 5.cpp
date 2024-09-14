#include <stdio.h>

int main() {
    
    int currentTime;
    
    printf("What is the current time: \n");
    scanf("%d", &currentTime);
    
    if (currentTime>=6 && currentTime<12){
        printf("Good Morning");
    } else if (currentTime>=12 && currentTime<18){
        printf("Good Afternoon");
    }else if (currentTime>=18 && currentTime<24){
        printf("Good Evening");
    }else if (currentTime>=0 && currentTime<=5){
        printf("Good Night");
    }

    return 0;
}
