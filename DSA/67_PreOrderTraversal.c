#include<stdio.h>
#include<stdlib.h>//for malloc

struct Node
{
    int data;
    struct Node* left;//self referencial structure
    struct Node* right;//self referencial structure
};

//Created a function which returns a node after creating it
struct Node* createNode(int data)
{
     //Constructing a node
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));//memeory allocation of a node in heap
    n->data=data;//setting data for the node
    //Setting the left & right children to NULL
    n->left=NULL;//setting the left child to NULL
    n->right=NULL;
    
    
    return n;//returning the created node at end of function
}
void preOrder(struct Node* root)
{
    if(root!=NULL)//base condition of recursion
    {
        printf("%d ",root->data);//printing root first
        preOrder(root->left);//printing left node next
        preOrder(root->right);//printing right node next
    }
}

int main()
{
    /*
    //Constructing the root node
    struct Node* p;
    p=(struct Node*)malloc(sizeof(struct Node));//memeory allocation of a node in heap
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    //Constructing the second node
    struct Node* p1;
    p1=(struct Node*)malloc(sizeof(struct Node));//memeory allocation of a node in heap
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    //Constructing the third node
    struct Node* p2;
    p2=(struct Node*)malloc(sizeof(struct Node));//memeory allocation of a node in heap
    p2->data=4;
    p2->left=NULL;
    p2->right=NULL;
    
    //Linking the root nodes with its children
    p->left=p1;
    p->right=p2;
    */

   // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

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

    preOrder(p);

    return 0;
    
}