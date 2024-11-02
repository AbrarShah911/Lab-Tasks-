#include <stdio.h>

int main(){

    int num;
    int Nnum = 1;
    int Knum = 0;

    printf("Please enter a number: ");
    scanf("%d", &num);

    for(int i = 1; i<=num; i++){
        Nnum = 1;
        Knum = i;
        for(int j = 0; j<i; j++){
            printf("%d",Nnum);
            Nnum++;
        }
         for(int k = Knum-1; k>0;k--){
            printf("%d",k);
         }
         printf("\n");
    }

    return 0;
}