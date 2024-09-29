#include <stdio.h>

int main() {

    int num;
    
    printf("Please enter the number you want to check the number of ones for: \n");
    scanf("%d" , &num);
    
    int numOfOnes = __builtin_popcount(num);
    
    printf("%d", numOfOnes);
    
    return 0;

}
// Without GCC inbuilt function



int main2() {

    int num;
    int numOfOnes = 0;
    
    printf("Please enter the number you want to check the number of ones for: \n");
    scanf("%d" , &num);
    
    if (num &1<<0) numOfOnes++;
    if (num &1<<1) numOfOnes++;
    if (num &1<<2) numOfOnes++;
    if (num &1<<3) numOfOnes++;
    if (num &1<<4) numOfOnes++;
    if (num &1<<5) numOfOnes++;
    if (num &1<<6) numOfOnes++;
    if (num &1<<7) numOfOnes++;
    if (num &1<<8) numOfOnes++;
    if (num &1<<9) numOfOnes++;
    if (num &1<<10) numOfOnes++; 
    if (num &1<<11) numOfOnes++;
    if (num &1<<12) numOfOnes++;
    if (num &1<<13) numOfOnes++;
    if (num &1<<14) numOfOnes++;
    if (num &1<<15) numOfOnes++;
    if (num &1<<16) numOfOnes++;
    if (num &1<<17) numOfOnes++;
    if (num &1<<18) numOfOnes++;
    if (num &1<<19) numOfOnes++;
    if (num &1<<20) numOfOnes++;
    if (num &1<<21) numOfOnes++;
    if (num &1<<22) numOfOnes++;
    if (num &1<<23) numOfOnes++;
    if (num &1<<24) numOfOnes++;
    if (num &1<<25) numOfOnes++;
    if (num &1<<26) numOfOnes++;
    if (num &1<<27) numOfOnes++; 
    if (num &1<<28) numOfOnes++;
    if (num &1<<29) numOfOnes++;
    if (num &1<<30) numOfOnes++;
    if (num &1<<31) numOfOnes++;

    
    printf("%d", numOfOnes);
    
    return 0;
}