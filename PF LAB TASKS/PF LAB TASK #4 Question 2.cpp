#include <stdio.h>

int main() {
    
    float unit30 = 0.0,unit80=0.0,unit100=0.0,unit210=0.0;
    float totalBill;
    int i,totalUnits;
    
    printf("Please enter the total ammount of units that you have used!: \n");
    scanf("%d", &totalUnits);
    
    if (totalUnits>=30){
        unit30 = 0.60;
    }
    
    if (totalUnits>=80){
        unit80 =0.85;
    }
    
    if (totalUnits>=100){
        unit100 =1.30;
    }
    
    if (totalUnits>=210){
     
        unit210 = (totalUnits - 210) * 1.60;
        
    }
    
    totalBill = unit30 +unit80+unit100+unit210;
    
    printf("The total of your bill was : %.2f", totalBill);
    return 0;
}
