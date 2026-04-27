// Stack implementation using array
//Basic operations


void push(int* arr,int arrSize, int* top_adr){
  int val;
  if(*top_adr == arrSize){
    printf("\nStack overflow!!");
    return ;
  }
  printf("Enter element : ");
  scanf("%d",(arr+1+*(top_adr)));
  ++(*top_adr);
}
int peek(int* arr, int top){
  return (*(arr+top));
}
int pop(int* arr, int arrSize, int* top_adr){
  if((*top_adr)< 0){
    printf("\nStack underflow!!");
    return -1;
  }
  int popVal = *(arr+((*top_adr)));
  *(arr+(*top_adr)) = -1; 
  --(*top_adr);
  return popVal ;
}

int main() {
  int top = -1,i=0;
  int s = 5;
  int* arr = (int*)malloc(5*sizeof(int));
  while(i != 4){
    push(arr,s,&top);
    i++;
  }
  printf("\nTop element is : %d",peek(arr,top));
  printf("\nElement popped : %d",pop(arr,s,&top));
  printf("\nTop element is : %d",peek(arr,top));
  return 0;
}
