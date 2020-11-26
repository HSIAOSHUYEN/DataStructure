#include <stdio.h>
#include <stdlib.h>
//Insertion and deletion in Binary Search Tree
typedef struct node
{
	struct node* left;
	int data;
	struct node* right;
}Node;

int countNode(Node *root){
    int nl = 0;
    int nr = 0;
    int count = 0;
    if(root != NULL){
        nl = countNode(root->left);
        nr = countNode(root->right);
        count = nl+nr+1;
        return count;
    }
    return 0;
}

int high(Node *root){
    int hl = 0;
    int hr = 0;

    if(root != NULL){
        hl = high(root->left);
        hr = high(root->right);
        return (hl>=hr) ? hl+1 : hr+1;
    }
    return 0;
}


Node* NewNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->left = NULL;
	temp->data = data;
	temp->right = NULL;

	return temp;
}

void PostOrder(Node* root)
{
	if(root==NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ",root->data);
}

Node* FindMin(Node* root)
{
	while(root->left!=NULL)
		root = root->left;

	return root;
}
int FindNumber(Node* root,int data){
    int findNumber = -1;
    if(root != NULL){
        if(root->data == data){
            return root->data;
        }
        else if(data < root->data){
             findNumber = FindNumber(root->left,data);
        }
        else{
            findNumber = FindNumber(root->right,data);
        }
    }

    return findNumber;
}

//struct Node* Delete(struct Node* root,int data)
//{
//	if(root==NULL)
//		return root;
//
//	else if(data < root->data)
//		root->left = Delete(root->left,data);
//
//	else if(data > root->data)
//		root->right = Delete(root->right,data);
//
//	else
//	{
//		if(root->left==NULL && root->right==NULL)
//		{
//			free(root);
//			root = NULL;
//		}
//
//		else if(root->left!=NULL && root->right==NULL)
//		{
//			struct Node* temp = root->left;
//			free(temp);
//			root = root->left;
//		}
//		else if(root->right!=NULL&& root->left==NULL)
//		{
//			struct Node* temp = root->right;
//			free(temp);
//			root = root->right;
//		}
//
//		else
//		{
//			struct Node* temp = FindMin(root->right);
//			root->data = temp->data;
//			root->right = Delete(root->right,temp->data);
//		}
//
//	}
//	return root;
//}

void InOrder(Node* root)
{
	if(root==NULL)
		return;

	InOrder(root->left);
	printf("%d ",root->data);
	InOrder(root->right);
}

void PreOrder(Node* root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

Node* insert(Node* root,int data)
{
	if(root==NULL)
		root =  NewNode(data);

	else if(data <= root->data)
		root->left = insert(root->left,data);

	else root->right = insert(root->right,data);

	return root;

}

void traverse(Node* root)
{
	//printf("\n\nPreOrder traversal : "); PreOrder(root);
	printf("\nInorder traversal  :   "); InOrder(root);
	//printf("\nPostOrder traversal:   "); PostOrder(root);
}

int main()
{
	Node* root = NULL;
	root = insert(root,26);
	root = insert(root,5);
	root = insert(root,77);
	root = insert(root,43);
	root = insert(root,19);
	root = insert(root,2);
	root = insert(root,8);

	traverse(root);

	printf("\n%d\n",FindNumber(root,19));
	printf("\n%d\n",countNode(root));
	printf("\n%d\n",high(root));


//	Delete(root,8);
//
//	traverse(root);

	return 0;
}
