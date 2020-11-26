#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5


typedef struct{
    int top;
    int arr[CAPACITY];
}Stack;

Stack* create_stack(void);
void printStackData(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
void push(Stack *, int data);
int pop(Stack *);

int main()
{

    printf("Hello world!\n");

    Stack *stack1 = create_stack();
    printStackData(stack1);

    push(stack1,200);
    printStackData(stack1);

    pop(stack1);
    printStackData(stack1);
    pop(stack1);
    printStackData(stack1);

    push(stack1,200);
    push(stack1,200);
    push(stack1,200);
    push(stack1,200);
    push(stack1,200);
    printStackData(stack1);
    pop(stack1);
    pop(stack1);
    pop(stack1);
    pop(stack1);
    pop(stack1);
    printStackData(stack1);
    return 0;
}
Stack* create_stack(void){

    Stack *stack1 = (Stack*) malloc(sizeof(Stack));
    stack1->top = -1;  //正常應該要寫(*stack).top
//    for(int i = 0; i < CAPACITY; i++){
//            stack1->arr[i] = i+200; //正常應該要寫(*stack).arr[]   stack-> 取代 (*stack).
//            //printf("stack1.arr[%d] : %d\n",i,stack1.arr[i]);
//    }
    //printf("\n");
    return stack1;
}

void printStackData(Stack *stack){
    printf("stack->top : %d\n",stack->top);//正常應該要寫(*stack).top

    for(int i = 0; i < CAPACITY;i++){
        printf("stack->arr[%d] : %d\n",i,stack->arr[i]);//正常應該要寫(*stack).arr[]   stack-> 取代 (*stack).
    }
    printf("\n");
}

int isEmpty(Stack *stack){

    if( (*stack).top == -1){
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}

int isFull(Stack *stack){

    if( (*stack).top ==  CAPACITY-1){
        printf("stack is full\n");
        return 1;
    }
    else
        return 0;
}

void push(Stack *stack, int data){

    if(isFull(stack)){
        return;
    }

    stack->top++;
    int index = stack->top;
    stack->arr[index] = data;
}

int pop(Stack *stack){

    if(isEmpty(stack)){
        return ;
    }
    int popindex = stack->top;
    stack->top--;
    int popvalue = stack->arr[popindex];
    stack->arr[popindex] = -1;
    return popvalue;
}
