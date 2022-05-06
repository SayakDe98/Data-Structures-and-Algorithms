#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}

int inOrder(struct Node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    
}


int isBST(struct Node* root)
{
    //we don't want each stack to have its own previous so we declared static.
    //at the root our prev will be NULL and as we go down in the tree we get prev!=NULL
    static struct Node* prev=NULL;//helps to check its children.since root is not anyone's children so it is initiated as NULL
    if(root!=NULL)//if this is actually a tree then do the operations below:
    {
        //basically we are doing inorder traversal to check if elements are in ascending order
        if(!isBST(root->left))  //check if its left subtree is BST.think we called isBST function for left subtree
            return 0;
        
    
    if(prev!=NULL && root->data <= prev->data) //prev data is NULL for first element so we used condition prev!=NULL and root data must be less than prev data then this B tree can be BST
        return 0;
    
    prev=root;//setting prev to root

    return isBST(root->right);//run same function for right subtree
    
    }
    else return 1;//if root is NULL then also assume it is BST
}

struct Node* searchIter(struct Node* root,int key)
{
    while(root!=NULL){
    if(root->data==key)
        return root;//we have found out the key in the BST
    else if(key<root->data)
        root=root->left;//we are using recursion to find the left subtree since current node's data is greater than the key
    else    
        root=root->right;//we are using recursion to find the right subtree since current node's data is lesser than the key
    }
    return NULL;//we have reached leaf node without being able to find the node which contains key as data
}

int main()
{
         /*
          5
         / \
        3   6
       /\
      1  4

      */
    struct Node* p=createNode(5);
    struct Node* p1=createNode(3);
    struct Node* p2=createNode(6);
    struct Node* p3=createNode(1);
    struct Node* p4=createNode(4);

    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");
    if(isBST(p)) printf("This is BST\n");
    else printf("This is not a BST\n");

    struct Node*n= searchIter(p,6);
    if(n!=NULL)
        printf("Found : %d \n",n->data);
    else printf("Element not found\n");
}