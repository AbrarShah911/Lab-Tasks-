#include <stdio.h>
#include <stdlib.h>

void findHighestFrequency();

int main(){

    int numOfTestCases;

    printf("Please enter the amount of test cases: ");
    scanf("%d", numOfTestCases);

    for(int i =0; i<numOfTestCases; i++){
        findHighestFrequency();
    }

    return 0;
}

void findHighestFrequency(){

    int numOfElements, count;

    printf("Please enter the number of elements in the array: \n");
    scanf("%d", &numOfElements);

    int *array = (int*)malloc(numOfElements*sizeof(int));
    int *frequencyArray = (int*)malloc(numOfElements*sizeof(int));

    if(array== NULL || frequencyArray == NULL){
        printf("Memory error");
        return;
    }

    for(int i = 0; i<numOfElements;i++){
        printf("Please enter element %d: ", i+1);
        scanf("%d",&array[i]); 
    }

    for(int i = 0; i<numOfElements;i++){
        count = 0;
        for(int j = 0; j<numOfElements;j++){
            if(array[i] == array[j]){
                count++;
            }
        }
        frequencyArray[i] = count;
    }

    int maxFrequency = frequencyArray[0];
    int maxElement = array[0];

    for(int i = 1; i<numOfElements;i++){
        if(frequencyArray[i] > maxFrequency){
                maxFrequency = frequencyArray[i];
                maxElement = array[i];
            }
    }

    printf("The highest frequency is: %d of %d\n", maxFrequency,maxElement);
    free(array);
    free(frequencyArray);

    return;
}
