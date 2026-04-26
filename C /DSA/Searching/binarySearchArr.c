
/* Author : Rahul Biswas
   Modification date : 25-04-2026
   Name: binarySearchArr.c
   Summery: Implementation of binary search in iterative way.
            This program will return where an element should present if it is not present.
*/

#include <stdio.h>
#include <stdlib.h>

// proto-type declaration
void insertArr(int*, int);
void displayArr(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);
int binarySearch(int*, int, int, int);


int main(){
	int numArr,val; // Number of element in array
	int* Arr = NULL; // Pointer to the array
	
	printf("\nEnter the number of element in array: ");
	scanf("%d",&numArr);
	if(numArr <= 0) // If input is non-Natural
 		return 1;

	Arr = (int*)malloc(numArr*sizeof(int)); // Creating location in heap
	insertArr(Arr,numArr);
	displayArr(Arr,numArr);
	
	//To ensure sorted array
	mergeSort(Arr,0,numArr-1);
	
	printf("\nAfter Sorting: ");
	displayArr(Arr,numArr);
    printf("\nEnter a value to search: ");
    scanf("%d",&val);
	int resIndex = binarySearch(Arr,0,numArr-1,val);
    if(resIndex >= 0){
        printf("\nElement is present in %d index",resIndex);
    }
    else{
        printf("\nElement should be present in %d index",-resIndex);
    }
	free(Arr);
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
	/* Mergesort implementation of array  
	Input: 
		int* Arr = Pointer to the array(first element)
		int left_idx = left index value
		int right_idx = right index value
	*/
	if(left_idx < right_idx){
		int mid_idx = left_idx + (right_idx - left_idx)/2 ;
		// Calculating the middle index 
		/* (left_idx+right_idx)/2 can go beyond range */
		mergeSort(Arr, left_idx, mid_idx);  // Recursive call for left part
		mergeSort(Arr, mid_idx+1, right_idx); // Recursive call for right part
		// Creating a logical separation 
		
		merge(Arr, left_idx, mid_idx, right_idx); // Combine 
	}
}
void merge(int* Arr, int left_idx, int mid_idx, int right_idx){
	/* Combine separated array  
	Input: 
		int* Arr = Pointer to the array(first element)
		int left_idx = left index value
		int mid_idx = middle index value
		int right_idx = right index value
	*/
    int i,j,k;
    int numLeftArr = mid_idx - left_idx + 1; // number of element to 5
    int numRightArr = right_idx - mid_idx; // number of element from 5 to right idx

	// Creating temporary storage for array
    int* leftArr = (int* )malloc(numLeftArr*sizeof(int)); 
    int* rightArr = (int* )malloc(numRightArr*sizeof(int));

	/* Copying the left part into left Arr */
    for(i = 0; i < numLeftArr; i++){
        *(leftArr+i) = *(Arr+left_idx+i);
    } 

	/* Copying the right part into right Arr*/
    for(j = 0; j < numRightArr; j++){
        *(rightArr+j) = *(Arr+mid_idx+1+j);
    }
    
    i = 0;
    j = 0;
    k = left_idx; 

	// Compare and sort 
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


	// Inserting left overs
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
	free(leftArr);
	free(rightArr);
}
int binarySearch(int* Arr, int left_idx, int right_idx, int searchVal){
    int mid_idx = 0;
    while(left_idx <= right_idx){
        mid_idx = left_idx + (right_idx - left_idx)/2;
        if(*(Arr+mid_idx) == searchVal)
            return mid_idx;
        if(*(Arr+mid_idx)< searchVal)
            left_idx = mid_idx + 1;
        else
            right_idx = mid_idx - 1;
    }
    return -left_idx;
}
