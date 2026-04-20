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
void deletefirstval(struct node**);
void deleteval(struct node**);

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
            case 5: deletefirstval(&head);break;
            case 6: deleteval(&head);break;
            case 7: return 0;
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
        printf("\n5. Delete first occurance of a value.");
        printf("\n6. Delete value from the list.");
        printf("\n7. Exit.");
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
    if(*head == NULL){
        printf("No linked list exists.");
        wait();
    }
    else{
        struct node* temp = NULL;
        while(*head !=NULL){
            temp = *head;
            *head=( *head)->next;
            free(temp);
        }
        printf("\nLinked list removed completely.");
        wait();
    }
}
void deletefirstval(struct node** head_adr){
    if(*head_adr == NULL){
        printf("No linked list exists.");
        wait();
        return;
    }

    int val;
    printf("\nEnter the value to be deleted: ");
    scanf("%d", &val);

    struct node *temp = *head_adr, *prev = NULL;

    if(temp->value == val){
        *head_adr = temp->next;
        free(temp);
        printf("\nFirst occurrence of %d is deleted.", val);
        wait();
        return;
    }

    while(temp != NULL && temp->value != val){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nValue not found.");
        wait();
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nFirst occurrence of %d is deleted.", val);
    wait();
}
void deleteval(struct node** head_adr){
    if(*head_adr == NULL){
        printf("No linked list exists.");
        wait();
        return;
    }

    int val, count = 0;
    printf("\nEnter the value to be deleted: ");
    scanf("%d", &val);

    struct node *temp = *head_adr, *prev = NULL;

    while(temp != NULL){
        if(temp->value == val){
            struct node* del = temp;

            if(prev == NULL){
                *head_adr = temp->next;
                temp = *head_adr;
            }
            else{
                prev->next = temp->next;
                temp = temp->next;
            }

            free(del);
            count++;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }

    if(count == 0)
        printf("\nValue not found.");
    else
        printf("\nDeleted %d occurrence(s) of %d.", count, val);

    wait();
}
