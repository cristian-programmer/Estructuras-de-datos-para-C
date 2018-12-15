#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*) malloc( sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
   if( (*head_ref) !=NULL){ (*head_ref)->prev = new_node;}
    (*head_ref) = new_node;
}

void pushAfter(struct Node *prev_node, int new_data){
    if(prev_node == NULL) {
        printf(" the given previus node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if(new_node->next !=NULL){
        new_node->next->prev = new_node;
    }
}


void pushAppend(struct Node** head_ref, int new_data ){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void printList(struct Node *node){
    struct Node *last, *now;
    int cont = 0;
     last = node->next;
     now = node->prev;
    
    while(last != now->next){
   
    printf("%d\n", now);
    printf("%s\n", "-----------");
    printf("%d\n",last);    
    last = node->next;
    now = node->prev;
    node = node->next;
    }  
     printf("\n Transversal in forward direction \n");
}

void reverse(struct Node **head_ref){
    struct Node *temp = NULL;
    struct Node *current = *head_ref;
    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if( temp != NULL){
        *head_ref = temp->prev;
    }
}


int main() {
    struct Node *head = NULL;

    
    push(&head, 7);
    push(&head, 1);
    pushAppend(&head, 4);
    push(&head, 8);
    //pushAfter(head->next, 8);
    
    printf("Created DLL is: "); 
    printList(head); 
  
    getchar(); 
    return 0;
}