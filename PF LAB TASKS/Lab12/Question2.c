#include <stdio.h>
#include <stdlib.h>

void makeArrayEven();

int main(){

    makeArrayEven();

    return 0;
}

void makeArrayEven(){

    int size;

    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    int *myArray = (int*)malloc(size * sizeof(int));

    for(int i = 0; i<size;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &myArray[i]);
        if(myArray[i]%2 != 0){
            myArray[i] = myArray[i] - 1;
        }
    }

    for(int i = 0; i<size;i++){
        printf("%d ", myArray[i]);
        printf("\n");
    }


    free(myArray);

    return;
}