#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

struct node *front;
struct node *rear;

void enqueue(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void pop(void){
    Node *temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

void printqueue(){
    Node *current = front;
    if(current == NULL){
        printf("queue is empty\n");
        return;
    }
    while(current != NULL){
        printf("%4d",current->data);
        current = current->next;
    }
    printf("\n");
}

int pfront(){
    int a;
    a = front->data;
    printf("front->data : %4d\n",a);
    return a;
}

int main()
{
    printf("Hello world!\n");
    front = NULL;
    rear = NULL;
    enqueue(100);
    enqueue(200);
    enqueue(300);
    pfront();
    printqueue();
    pop();
    pfront();
    printqueue();
    pop();
    printqueue();
    pop();
    printqueue();
    return 0;
}
