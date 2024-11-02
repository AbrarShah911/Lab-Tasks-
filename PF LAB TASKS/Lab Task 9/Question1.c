#include <stdio.h>

int main(){

   int num, rnum = 1;

    num = 10;

    for(int i =num+1; i>1;i--){
        for(int j = i; j>0;j--){
            printf(". ");
        }
        for(int j = 0; j<rnum;j++){
            printf("O");
        }
        printf("\n");
        rnum++;
    }

    for(int i =1; i<num+2;i++){
        for(int j = 0; j<i;j++){
            printf(". ");
        }
        for(int j = 0; j<rnum;j++){
            printf("O");
        }
        printf("\n");
        rnum--;
    }

}