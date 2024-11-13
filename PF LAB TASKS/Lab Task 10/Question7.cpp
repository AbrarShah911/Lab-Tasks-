#include <stdio.h>
void recursiveBubbleSort(int arr[], int size){
	int temp;
	if(size==1){
		return;
	}
	for(int i = 0; i<size-1 ; i++){
		if(arr[i]>arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	recursiveBubbleSort(arr, size-1);
}
int main(){
	int arr[]={2,4,5,5,6,7,6,545,4,5,6,6,76,5,4,3,4,5566,6,434,45,56};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before sorting:\n");
	for(int i = 0; i<size; i++){
	    printf("%d ", arr[i]);
	}
	printf("\n");   
	
	recursiveBubbleSort(arr, size);
	
	printf("After sorting:\n");
	for(int i = 0; i<size; i++){
	    printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
