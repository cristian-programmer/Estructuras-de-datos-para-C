#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int data;
    struct Nodo *next;
};


void printList(struct Nodo *first){
    struct Nodo *temp = first;

    if(first != NULL){
        do {
            printf("%d", temp->data);
            temp = temp->next;
        }while (temp != first);
    }
}

void push(struct Nodo **head_ref, int new_data) {
    struct Nodo *new_nodo = (struct Nodo*) malloc( sizeof(struct Nodo));
    struct Nodo *temp = *head_ref;
    new_nodo->data = new_data;
    new_nodo->next = *head_ref;

    if(*head_ref !=NULL){
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_nodo;

    }else {
        new_nodo->next = new_nodo;
    }

    *head_ref = new_nodo;
}

int main() {
    struct Nodo *head = NULL;
    push(&head, 12); 
    push(&head, 56); 
    push(&head, 2); 
    push(&head, 11); 
    printf("\n Contents of Circular Linked List \n");
    printList(head);
    return 0;
}