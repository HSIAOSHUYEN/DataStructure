#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

struct node *top;

void push(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
void pop(){
    Node *temp = top;
    if(top == NULL){
        printf("stack is empty\n");
        return;
    }
    else{
        top = top->next;
    }
    free(temp);
}

void printStack(){
    Node *current = top;
    if(current == NULL){
        printf("stack is empty\n");
    }
    while(current != NULL){
        printf("%4d",current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{

    top = NULL;
    push(30);
    push(40);
    push(50);

    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    pop();

    return 0;
}
