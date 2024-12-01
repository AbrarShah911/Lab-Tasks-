#include <stdio.h>
#include <stdlib.h>

void findLargestInArray(int size);

int main(){

    int size;

    printf("Please enter the number of elements you want to input in the array: ");
    scanf("%d",&size);

    findLargestInArray(size);
    
    return 0;
}

void findLargestInArray(int size){

    int *array = (int*)malloc(size*sizeof(int));
    if(array == NULL){
        printf("Memory allocation failed\n");
    }
    int maxElement;

    for(int i = 0; i<size; i++){
        printf("Enter array value: %d\n", i+1);
        scanf("%d", &array[i]);
    }

    maxElement = array[0];

    for(int i = 0; i<size;i++){
        if(array[i] > maxElement){
            maxElement = array[i];
            }
    }

    printf("The highest in the numbers input was: %d", maxElement);
    free(array);
    return;

}