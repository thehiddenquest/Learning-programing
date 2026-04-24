// Merge sort on array 
/* Author : Rahul Biswas
   Modification date : 24-04-2026
   Name: mergesortArr.c
   Summery: Implementation of merge sort of an integer array in recursive way.
*/

#include <stdio.h>
#include <stdlib.h>

// proto-type declaration
void insertArr(int*, int);
void displayArr(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(){
	int numArr; // Number of element in array
	int* Arr = NULL; // Pointer to the array
	
	printf("\nEnter the number of element in array: ");
	scanf("%d",&numArr);
	if(numArr <= 0) // If input is non-Natural
 		return 1;

	Arr = (int*)malloc(numArr*sizeof(int)); // Creating location in heap
	insertArr(Arr,numArr);
	displayArr(Arr,numArr);

	mergeSort(Arr,0,numArr-1);

	displayArr(Arr,numArr);

	return 0;
}

void insertArr(int* Arr,int n){
	/* Insert element into the array 
	Input: 
		int* Arr = Pointer to the array(first element)
		int n = size of array
	Output:
		void.(Directly update the memory)
	*/
	int i;
	printf("Insert elements: \n");
	for(i = 0; i < n; i++){
		printf("\nEnter element %d: ",i+1);
		scanf("%d",(Arr+i));
	}
}

void displayArr(int* Arr,int n){
/* Display the elements of the array 
	Input: 
		int* Arr = Pointer to the array(first element)
		int n = size of array
	Output:
		void.
	*/
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
void merge(int* Arr, int left_idx, int mid_idx, int right_idx){
    int i,j,k;
    int numLeftArr = mid_idx - left_idx + 1;
    int numRightArr = right_idx - mid_idx;
    
    int* leftArr = (int* )malloc(numLeftArr*sizeof(int));
    int* rightArr = (int* )malloc(numRightArr*sizeof(int));
    
    for(i = 0; i < numLeftArr; i++){
        *(leftArr+i) = *(Arr+left_idx+i);
    }
    for(j = 0; j < numRightArr; j++){
        *(rightArr+j) = *(Arr+mid_idx+1+j);
    }
    
    i = 0;
    j = 0;
    k = left_idx;
    
    while(i < numLeftArr && j < numRightArr){
        if(*(leftArr+i) <= *(rightArr+j)){
            *(Arr+k) = *(leftArr+i);
            i++;
        }
        else{
            *(Arr+k) = *(rightArr+j);
            j++;
        }
        k++;
    }
    
    while(i < numLeftArr){
        *(Arr+k) = *(leftArr+i);
        i++;
        k++;
    }
    while(j < numRightArr){
        *(Arr+k) = *(rightArr+j);
        j++;
        k++;
    }
}
