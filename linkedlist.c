#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
    struct node *next;
}Node;

Node* createlist(void);
void insertNode(Node *head, int insertAftervalue,int data);
void deleteNode(Node *head,int deletedata);

void printLinkedlist(Node *head);

int main()
{

    Node *head = createlist();
    insertNode(head,12,20);
    insertNode(head,20,500);
    insertNode(head,20,400);
    printLinkedlist(head);
    deleteNode(head,20);
    printLinkedlist(head);
    printf("END");
    return 0;
}
Node* createlist(void){
    Node *head = (Node*) malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;

    return head;
}

void insertNode(Node *head, int insertAftervalue ,int insertdata){
    Node *newNode = (Node*)malloc(sizeof(Node)); //要新增的node
    Node *p = head->next;  //輔助指標方便循序找node
    if(head->next == NULL){ //如果list為空就直接串在head的next
        head->next = newNode;
        newNode->next = NULL;
        newNode->data = insertdata;
    }
    while(p != NULL){ //循序找node 的值為insertAftervalue
        if(p->data == insertAftervalue){
            newNode->next = p->next;
            p->next = newNode;
            newNode->data = insertdata;
            break;
        }
        p = p->next;
    }
}

void printLinkedlist(Node * head){
    if(head->next == NULL){
        printf("List is empty\n");
        return;
    }
    Node *current = head->next;
    while(current != NULL){
        printf("%4d",current->data);
        current = current->next;
    }
    printf("\n");

}

void deleteNode(Node * head,int deletedata){ //需要三個指標 current,head, beforeCurrent
    if(head->next == NULL){         //檢查list是否為空
        printf("List is empty\n");
        return;
    }
    Node *current = head->next;
    if(current->data == deletedata){ // 要刪的node在head的next
        head->next = current->next;
        free(current);
        return;
    }
    Node *beforeCurrent = head;
    while(current != NULL){
        if(current->data == deletedata){
            beforeCurrent->next = current->next;
            free(current);
            break;
        }
        beforeCurrent = beforeCurrent->next;
        current = current->next;
    }
}
