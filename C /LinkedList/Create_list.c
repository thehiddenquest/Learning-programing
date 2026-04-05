#include <stdio.h>
#include <stdlib.h>
//Structure of node
struct node{
    int value;
    struct node* next;
};
//Prototype declaration 
void addnode(struct node*);
void displaylist(struct node*);



int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    addnode(head);
    displaylist(head);
}

void addnode(struct node* head){
    int in;
    struct node* head_copy = NULL;
    head_copy = head;
    printf("\nEnter values(9999 to stop): ");
    while(1){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter value: ");
        scanf("%d",&in);
        if(in == 9999)
            break;
        newnode->value = in;
        newnode->next = NULL;
        head_copy->next = newnode;
        head_copy = newnode;
        
    }
}
void displaylist(struct node* head){
    if(head == NULL){
        printf("\nNo list found");
        return;
    }
    printf("\nList is :: \n");
    struct node* new = NULL;
    new = head->next;
    while(new != NULL){
        printf("%d->",new->value);
        new= new->next;
    }
    printf("NULL");
}
