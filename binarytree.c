#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * newNode( int newdata){
    struct Node* node = (struct Node*) malloc( sizeof(struct Node));
    node->data  = newdata;
    node->left  = NULL;
    node->right = NULL;

    return (node);
}


void printPostOrder(struct Node* node){
    if(node == NULL) {
        return;
    }

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d", node->data);
}

void printInOrder(struct Node* node){
    if(node == NULL) {
        return;
    }

    printInOrder(node->left);
    printf("%d", node->data);
    printInOrder(node->left);
}

void printPreOrder(struct Node* node){
    if(node == NULL) {
        return;
    }

    printf("%d", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}




int main(){

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);

    printf("\nPreorder traversal of binary tree is \n"); 
    printPreOrder(root); 

    getchar();
    return 0;   
}
