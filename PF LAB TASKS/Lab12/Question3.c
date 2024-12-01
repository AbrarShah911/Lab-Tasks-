#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void addToArray(int **array, int *size, int number);
void printArray(int *array, int size);
void freeArray(int *array);
void removeLastElement(int **array, int *size);

int main() {
    int *array = (int *)malloc(4 * sizeof(int)); 
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int size = 4; 
    for (int i = 0; i < size; i++) {
        array[i] = i + 1; 
    }

    printf("Initial array:\n");
    printArray(array, size);

    addToArray(&array, &size, 10); 
    printf("\nArray after adding a number:\n");
    printArray(array, size);

    removeLastElement(&array, &size); 
    printf("\nArray after removing the last element:\n");
    printArray(array, size);

    freeArray(array); 

    return 0;
}

void addToArray(int **array, int *size, int number) {
    printf("Please enter the number you want to add: ");
    scanf("%d", &number);

    (*size)++;
    *array = (int *)realloc(*array, (*size) * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    (*array)[(*size) - 1] = number; 
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void freeArray(int *array) {
    free(array);
}

void removeLastElement(int **array, int *size) {
    if (*size == 0) {
        printf("Array is already empty.\n");
        return;
    }

    (*size)--;
    *array = (int *)realloc(*array, (*size) * sizeof(int));
    if (*array == NULL && *size > 0) {
        printf("Memory reallocation failed.\n");
    }
}

