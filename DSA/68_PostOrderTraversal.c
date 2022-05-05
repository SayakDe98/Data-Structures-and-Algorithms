#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//Created a function which returns a node after creating it
struct Node* createNode(int data)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;//setting data for the node
    n->left=NULL;//setting the left child to NULL
    n->right=NULL;//setting the right child to NULL

    return n;
}

void postOrder(struct Node* root)
{
    if(root!=NULL)//base condition of recursion
    {
        postOrder(root->left);//printing left node first
        postOrder(root->right);//printing right node next
        printf("%d ",root->data);//printing root at last
    }
}

int main()
{
    //Using functions to create root and child nodes
    struct Node* p=createNode(4);
    struct Node* p1=createNode(1);
    struct Node* p2=createNode(6);
    struct Node* p3=createNode(5);
    struct Node* p4=createNode(2);
    
    //Linking the root nodes with its children
    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    postOrder(p);


}