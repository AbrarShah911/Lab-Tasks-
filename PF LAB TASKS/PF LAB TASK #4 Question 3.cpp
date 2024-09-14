#include <stdio.h>

int main() {
    
    float totalBill = 0;
    float itemPrice;
    
    printf("please enter the price of the item you want to buy: \n");
    scanf("%f", &itemPrice);
    
    totalBill = itemPrice;
    
    if (itemPrice<1500){
        totalBill = totalBill - ((0.07)*itemPrice);
    } else if(itemPrice>=1500 && itemPrice<3000){
        totalBill = totalBill - ((0.12)*itemPrice);
    } else if(itemPrice>=3000 && itemPrice<5000){
        totalBill = totalBill - ((0.22)*itemPrice);
    }else if(itemPrice>=5000){
        totalBill = totalBill - ((0.30)*itemPrice);
    }
    
    printf("The total Bill is: %.2f\n", totalBill);

    return 0;
}
