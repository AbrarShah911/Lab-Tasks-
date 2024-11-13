#include <stdio.h>
void recursivePrint(int arr[], int size){
	if(size == -1){
		return;
	}
	recursivePrint(arr, size-1);
	printf("%d ", arr[size]);
}
int main(){
	printf("Array:\n");
	int arr[] = {2,2,3,4,455,4,3,2,2,34,4,56,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	recursivePrint(arr, size-1);	
	return 0;
}

