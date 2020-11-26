#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80

int prioirty(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void intopostfix(char *infix, char *postfix ){
    char stack[MAX] = {'\0'}; //先讓stack裡優先權最小
    int i, j, top;
    for(i = 0,j = 0, top = 0; infix[i] != '\0';i++){
        switch(infix[i]){
            case '(': //隱含括號在infix優先權最大
                   stack[++top] = infix[i];
                   break;
            case '+': case '-': case '*' :case '/':
                while(prioirty(stack[top]) >= prioirty(infix[i])){
                        postfix[j] = stack[top];
                        top--;
                        j++;
                }
                stack[++top] = infix[i];
                break;
            case ')':
                while(stack[top] != '('){
                        postfix[j++] = stack[top--];
                }
                top--; //遇到左括號但是不放到postfix[]中
                break;
            default:
                postfix[j++] = infix[i];
        }
    }
     while(top > 0){ //最後會把stack[0]的'\0'放到postfix最後一個index
            postfix[j++] = stack[top--];
    }
}


double cal(char op,double p1,double p2){
    switch(op){
        case '+' : return p1+p2;
        case '-' : return p1-p2;
        case '*' : return p1*p2;
        case '/' : return p1/p2;
    }
}


int eva(char *postfix){

    double stack[MAX] = {0.0};
    int i , top, operand;
    for( i = 0,  top = 0; postfix[i] != '\0'; i++){
        switch(postfix[i]){
            case '+': case'-': case'*': case'/':
               stack[top-1] =  cal(postfix[i],stack[top-1],stack[top]);
               top--;
               break;
            default:
                operand = postfix[i] - 48;
                stack[++top] = operand;
        }
    }
    return stack[top];
}

int main()
{

    char infix[] = {"(4+8)/(2+2)"};
    char postfix[MAX] ={'\0'};

//    char infix[] = {"((a/(b-c+d))*(e-a)*c)"};
//    char infix[] = {"((8/(7-6+3))*(9-8)*6)"};

    intopostfix(infix,postfix);

    for(int i = 0; postfix[i] != '\0'; i++){
        printf("%c",postfix[i] );
    }
    printf("\n");


    printf("((4+8)/(2+2) = %d\n",eva(postfix));



    return 0;
}
