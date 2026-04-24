// Merge sort on array 

#include <stdio.h>
#include <stdlib.h>

void insertArr(int*, int);
void displayArr(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(){
	int numArr;
	int* Arr = NULL;
	
	printf("\nEnter the number of element in array: ");
	scanf("%d",&numArr);
	if(numArr <= 0)
		return 1;

	Arr = (int*)malloc(numArr*sizeof(int));
	insertArr(Arr,numArr);
	displayArr(Arr,numArr);

	mergeSort(Arr,0,numArr-1);

	displayArr(Arr,numArr);

	return 0;
}
void insertArr(int* Arr,int n){
	int i;
	printf("Insert elements: \n");
	for(i = 0; i < n; i++){
		printf("\nEnter element %d: ",i+1);
		scanf("%d",(Arr+i));
	}
}
void displayArr(int* Arr,int n){
	int i;
	printf("\nInserted array is: \t");
	for(i = 0; i < n; i++){
		printf("%d\t",*(Arr+i));
	}
	printf("\n");
}
void mergeSort(int* Arr,int left_idx, int right_idx){
	if(left_idx < right_idx){
		int mid_idx = left_idx + (right_idx - left_idx)/2 ;

		mergeSort(Arr, left_idx, mid_idx);
		mergeSort(Arr, mid_idx+1, right_idx);

		merge(Arr, left_idx, mid_idx, right_idx);
	}
}
 




