#include<stdio.h>
#include<stdlib.h>

#define inc(x) x+1   // This is takes x as a argument and return x+1

#define printn printf("\n") //This replaces the printn in main function

#define printA printf("\nThis line is printed by preprocessor\n");


// This can be used for generic purposes 
#define maxArr(array,size) ({\
	typeof(array[0]) max = array[0] ;\
	int i ;\
	for(i = 0;i<size;i++)\
		if(array[i] > max)\
			max = array[i];\
	max;\
})



int main(){
	printA
	int a = 0;
	
	int arr[] = {1,2,3,4,5};
	double arr_double[] = {0.1,0.4,0.9,0.8};

	int size = 10;
	int* arr_int = (int*)malloc(size*sizeof(int));

	for(a = 0; a<size; a++){
		scanf("%d",arr_int+a);
	}

	char Student[] = {'R','A','H','U','L'};

	printf("\nNew value of a is %d",inc(a));
	printn;

	int max_int = maxArr(arr,5);
	printf("\nMax int is: %d",max_int);
	printn;

	double max_dub = maxArr(arr_double,4);
	printf("\nMax double is: %f",max_dub);
	printn;
	
	int max_int_num = maxArr(arr_int,size);
	printf("\nMax pointer array is : %d",max_int_num);
	printn;

	char max_char = maxArr(Student,6);
	printf("\nMax character is : %c",max_char);
	printn;

	return 0;
}
