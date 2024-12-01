#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enterPoints(int *array, int size);
void calculateTotalPoints(int *array, int size);

int main(){

    int size;
    printf("Enter the number of points: ");
    scanf("%d", &size);

    int *array = (int*)malloc(size*sizeof(int));
    if(array == NULL){
        printf("Memory not allocated.\n");
        return 1;
    }

    enterPoints(array, size);
    calculateTotalPoints(array, size);

    return 0;
}

void enterPoints(int *array, int size){


    for(int i = 0; i < size; i++){
        printf("Enter fee for point %d: ", i+1);
        scanf("%d", &array[i]);
    }
    return;
}

void calculateTotalPoints(int *array, int size){
    int total = 0;
    for(int i = 0; i<size; i++){
        total += array[i];
    }
    printf("The total fee for all the points is: %d\n", total);
    return;
}