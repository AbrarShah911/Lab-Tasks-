#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeArray(int ***array, int *size, int rows, int columns); // Function to initialize all the array values
void printArray(int **array, int rows); // Function to print the array 
void modifyArray(int **array, int rows, int columns, int rowPosition, int colPosition, int value); // Function to insert or delete in the array
void freeArray(int ***array, int rows); // Function to free the array

int main(){

    int **array = NULL;
    int rows = 10, columns = 10;

    initializeArray(&array, NULL, rows, columns);

    printf("Initial Array:\n");
    printArray(array, rows);

    modifyArray(array, rows, columns, 2, 3, 42);
    printf("\nArray After Modification:\n");
    printArray(array, rows);

    freeArray(&array, rows);

    return 0;
}

void initializeArray(int ***array, int *size, int rows, int columns){

    *array = (int**)malloc(rows*sizeof(int));

    if(array == NULL){
        printf("Memory not allocated.\n");
        return;
    }

    for(int i=0;i<rows;i++){
        (*array)[i] = (int*)malloc(columns*sizeof(int));
        if ((*array)[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i);
            return;
        }
        for (int j = 0; j < columns; j++) {
            (*array)[i][j] = 0; 
        }
    }

    
}

void printArray(int **array, int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            printf("%d ", (array)[i][j]);
        }
        printf("\n");
    }
}

void modifyArray(int **array, int rows, int columns, int rowPosition, int colPosition, int value) {
    char choice;
    printf("Do you want to insert or delete? (i/d): ");
    scanf(" %c", &choice);

    if (choice == 'i') {
        if (rowPosition >= 0 && rowPosition < rows && colPosition >= 0 && colPosition < columns) {
            array[rowPosition][colPosition] = value;
        } else {
            printf("Invalid position for insertion.\n");
        }
    } else if (choice == 'd') {
        if (rowPosition >= 0 && rowPosition < rows && colPosition >= 0 && colPosition < columns) {
            array[rowPosition][colPosition] = 0;
        } else {
            printf("Invalid position for deletion.\n");
        }
    } else {
        printf("Invalid choice. Please enter 'i' for insert or 'd' for delete.\n");
    }
}

void freeArray(int ***array, int rows) {
    if (*array != NULL) {
        for (int i = 0; i < rows; i++) {
            free((*array)[i]);
        }
        free(*array);
        *array = NULL;
    }
}