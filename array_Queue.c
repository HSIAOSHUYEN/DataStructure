#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
//queue 特性FIFO front刪 rear加

typedef struct{
    int front;
    int rear;
    int arr[CAPACITY];
}Queue;

Queue* createQueue(void);
void printQueueData(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void push(Queue *, int);
int pop(Queue *);

int main()
{
    printf("Hello world!\n");
    Queue *queue = createQueue();
    //printQueueData(queue);

    push(queue,10);
    push(queue,20);
    push(queue,30);
    push(queue,40);
    printQueueData(queue);

    printf("pop : %d\n",pop(queue));
    printf("pop : %d\n",pop(queue));

    push(queue,50);
    push(queue,60);

    printQueueData(queue);
    printf("pop : %d\n",pop(queue));
    printf("pop : %d\n",pop(queue));

    printQueueData(queue);
    return 0;
}


Queue* createQueue(void){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;

    return queue;
}


void printQueueData(Queue *queue){

    if(isEmpty(queue)){//Queue為空
        return;
    }

    int i = queue->front; //要先do否則 (front+1)%CPACITY 剛好 == rear 這個case會跑不出來
    do{
        i = (i+1)%CAPACITY;
        printf("arr[%d] : %d\n", i,queue->arr[i]);
    }while(i != queue->rear);


}


int isFull(Queue *queue){
    if( (queue->rear+1)%CAPACITY == queue->front){
        printf("Queue is Full\n");
        return 1;
    }
    return 0;
}
int isEmpty(Queue *queue){

    if(queue->front == queue->rear){
        printf("Queue is Empty\n");
        return 1;
    }
    return 0;
}

void push(Queue *queue, int data){ //都重rear+1%CAPACITY的index開始

    if(isFull(queue)){
        return;
    }
    int pushIndex = (queue->rear+1)%CAPACITY;
    queue->rear = (queue->rear+1)%CAPACITY;
    queue->arr[pushIndex] = data;
}

int pop(Queue *queue){
    if(isEmpty(queue)){
        return -1;
    }
    int popIndex = (queue->front+1)%CAPACITY;
    int popvalue = queue->arr[popIndex];
    queue->arr[popIndex] = -1;
    queue->front = (queue->front+1)%CAPACITY;
    return popvalue;
}
