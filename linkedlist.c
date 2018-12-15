#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data ){
    struct Node *new_node = (struct Node*) malloc( sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void pushAfter(struct Node **prev_node, int new_data){
    if(prev_node == NULL) 
        printf("the given previus node cannot be NULL")
        return;

    struct Node *new_node = 
    (struct Node*)
    malloc( sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_data;

}

void pushAppend(struct Node **head_ref, int new_data){
    struct Node *new_node = 
    (struct Node*)
    malloc( sizeof(struct Node));

    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref ==NULL) *head_ref = new_node
        return;

    while(last->next !=NULL)
        last = last->next;
    last->next = new_node;
}

void getLinkedList(struct Node *node){

    while(node !=NULL)
        printf(node->new_data)
        node = node->next;

}

int main(){
    struct Node *head = NULL;
    pushAppend(&head, 6);
    push(&head, 7);
    push(&head, 7);
    pushAfter(head->next,8);
    printf("\n created linked list in: ");
    getLinkedList(head);
}

