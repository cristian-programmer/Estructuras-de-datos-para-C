#include <stdio.h>
#include <stdio.h>

struct QNode {
    int key;
    struct QNode *next;
};


struct Queue { 
    struct QNode *front, *rear;
};

struct QNode* newNode(int key){
    struct QNode *temp = (struct QNode*) malloc( sizeof(struct QNode) );
    temp->key = key;
    temp->next= NULL; 
    return temp;
}

struct Queue* createQueue(){
    struct Queue *q = (struct Queue*) malloc( sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, int key){
    struct QNode *temp = newNode(key);
    if(q->rear == NULL){
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue *q){
    if(q->front == NULL) return NULL;

    struct QNode *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    return temp;
}

int main(){
     struct Queue *q = createQueue(); 
    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    struct QNode *n = deQueue(q); 
    if (n != NULL) 
      printf("Dequeued item is %d", n->key); 
    return 0;
}