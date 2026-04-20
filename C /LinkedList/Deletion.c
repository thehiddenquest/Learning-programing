// Delete first element of the list
#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node* next;
};

void wait();
void menu();
void createlinkedlist(struct node**);
void displaylinkedlist(struct node*);
void deletefirstnode(struct node**);
void deletelist(struct node**);

int main(){
    int op=0,i;
    struct node* head = NULL;
    do{
       printf("\033[H\033[2J");
        menu();
        scanf("%d",&op);
        switch(op){
            case 1: createlinkedlist(&head);break;
            case 2: displaylinkedlist(head);break;
            case 3: deletefirstnode(&head);break;
            case 4: deletelist(&head);break;
            case 5: return 0;
            default: printf("\nPlease, Insert an valid option!!!");
        }   
    }while(1);
    return(1);
}
void wait(){
        getchar();
        getchar();
}
void menu(){
        printf("\n------------------------------------------");
        printf("\n              Menu                       \n");
        printf("------------------------------------------");
        printf("\n\n1: Create a linked list.");
        printf("\n2: Display linked list.");
        printf("\n3. Delete first node.");
        printf("\n4. Delete entire list.");
        printf("\n5. Exit.");
        printf("\n------------------------------------------\n");
        printf("\nEnter option: ");
}
void createlinkedlist(struct node** head){
    int i=0,value;
    struct node* temp = NULL;
    printf("\n\nEnter values to store[999 to stop] : \n");
    while(1){
        printf("\nEnter value %d: ",++i);
        scanf("%d",&value);
        if(value == 999) break;
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = value;
        newnode->next = NULL;
        if(*head == NULL){
            *head = newnode;
            temp = *head;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }
    printf("\nLinked list created.");
    wait();
}
void displaylinkedlist(struct node* head){
    if(head == NULL){
        printf("\nNo Linked list exist.");
        wait();
    }
    else{
        printf("\nLinked list:  \n");
        struct node* temp = head;
        while(temp != NULL){
            printf("%d->",temp->value);
            temp=temp->next;
        }
        printf("NULL");
        wait();
    }
}
void deletefirstnode(struct node** head){
    if(*head ==NULL){
        printf("\nNo Linked list exist.");
        wait();
    }
    else{
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("\nFirst node removed.");
        wait();
    }
}
void deletelist(struct node** head){

}
