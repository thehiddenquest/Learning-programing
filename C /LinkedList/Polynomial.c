#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    int expo;
    struct node* next;
};

void insertpoly(struct node**);
void displaypoly(struct node*);
void sortpoly(struct node*);
int main(){
    struct node* poly1 = NULL;
    insertpoly(&poly1);
    sortpoly(poly1);
    displaypoly(poly1);
}

void insertpoly(struct node** poly1){
    int expon, coff;
    struct node* temp = NULL;

    printf("\nInsert the polynomial (9999 to stop): \n");

    while(1){
        printf("\nExponent of x: ");
        scanf("%d",&expon);

        printf("Coeff: ");
        scanf("%d",&coff);

        if(coff==9999 || expon==9999){
            break;
        }

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = coff;
        newnode->expo = expon;
        newnode->next = NULL;

        if(*poly1 == NULL){
            *poly1 = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }

}

void displaypoly(struct node* poly){
    while(poly != NULL){
        printf("%dx^%d", poly->value, poly->expo);
        poly = poly->next;
        if(poly != NULL)
            printf(" + ");
    }
}
void sortpoly(struct node* head){
    struct node *i, *j;
    int temp_val, temp_exp;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->expo < j->expo){   // descending order
                temp_exp = i->expo;
                temp_val = i->value;

                i->expo = j->expo;
                i->value = j->value;

                j->expo = temp_exp;
                j->value = temp_val;
            }
        }
    }
}
