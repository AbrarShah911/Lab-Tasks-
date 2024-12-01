#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertInArray(int **array, int *size, int position, int insertionValue);
void deleteFromArray(int **array, int *size, int position);

int main(){

    int numberOfTestCases ,position ,valueToInsert;
    char input [20];
    char letter;

    int *array = (int *)malloc(10 * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    array[4] = 50;
    array[5] = 60;
    array[6] = 70;
    array[7] = 80;
    array[8] = 90;
    array[9] = 100;

    int size = 10;

    printf("Please enter the number of test cases: ");
    scanf("%d", &numberOfTestCases);


    for(int i = 0; i<numberOfTestCases;i++){
        printf("Please enter 'i' to insert or 'd' to delete and the appropriate values: ");
        scanf(" %c %d %d", &letter, &position, &valueToInsert); 
        if(letter == 'i' || letter == 'I'){
            insertInArray(&array, &size, position, valueToInsert);
        }else{
            deleteFromArray(&array, &size, position);
        }
    }

    free(array);
    return 0;
}

void insertInArray(int **array, int *size, int position, int insertionValue){
    (*size)++;
    *array = (int*)realloc(*array, (*size)*sizeof(int));
    for (int i = *size - 1; i > position; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    (*array)[position] = insertionValue;
    for(int i = 0; i<*size; i++){
        printf("%d ", (*array)[i]);
    }
}

void deleteFromArray(int **array, int *size, int position){
    for(int i = position; i < *size - 1; i++){
        (*array)[i] = (*array)[i + 1];
    }
    (*size)--;
    *array = (int*)realloc(*array, (*size)*sizeof(int));

    for(int i = 0; i<*size; i++){
        printf("%d ", (*array)[i]);
    }
}