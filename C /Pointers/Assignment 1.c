#include<stdio.h>
#include<stdlib.h>
int main(){
    int x = 5;
    int *px = (int*)malloc(sizeof(int*));
    px = &x;
    
    int **ppx = (int**)malloc(sizeof(int**));
    ppx = &px;

    printf("\nValue of x = %d",x);
    printf("\nValue of x using px = %d", *px);
    printf("\nValue of x using ppx = %d", *(*(ppx)));
}