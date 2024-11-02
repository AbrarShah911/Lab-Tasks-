#include <stdio.h>
#include <stdbool.h>

int main(){

    int bolts, nuts, washers = 0;
    int boltPrice, nutPrice, washerPrice = 0;
    int totalPrice;
    bool mark = false;
    bool markAgain = false;

    printf("Please enter the number of bolts you want to buy: ");
    scanf("%d", &bolts);

    printf("Please enter the number of nuts you want to buy: ");
    scanf("%d", &nuts);

    printf("Please enter the number of washers you want to buy: ");
    scanf("%d", &washers);

    boltPrice = bolts *5;
    nutPrice = nuts *3;
    washerPrice = washers *1;
    totalPrice = boltPrice + nutPrice + washerPrice;

    if((nutPrice>=boltPrice)){
        mark = true;
    }

    if(((2*washers)>=boltPrice)){
        markAgain = true;
    }

    if(mark){
        printf("Check the order: Too few nuts");
        printf("Total Cost: %d", totalPrice);
    }else if(markAgain){
        printf("Check the order: Too few washers");
        printf("Total Cost: %d", totalPrice);
    }else if (mark && markAgain){
        printf("Check the order: Too few nuts and Too few washers");
        printf("Total Cost: %d", totalPrice);
    }else{
        printf("Total Cost: %d", totalPrice);
    }

    return 0;
}