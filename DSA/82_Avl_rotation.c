#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node* left;//self referencing left node
    struct Node *right;//self referencing left node
    int height;//to get absolute value of balance factor.if bf is>2 then imbalance occurs else tree is balanced
};

void preOrder(struct Node* root)
{
    if(root!=NULL)//base condition of recursion
    {
        printf("%d ",root->key);//printing root first
        preOrder(root->left);//printing left node next
        preOrder(root->right);//printing right node next
    }
}

int max(int a,int b)
{
    return a>b? a:b;
}

int getHeight(struct Node* n)
{
    if(n==NULL)
    {
        return 0;//Avl tree has no height
    }
    return n->height;//if n!=Null then we return n node's height
}

//let's create an utility function
struct Node* createNode(int key)//function to create a node and parameter is key
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));//dynamically allocating memory & creating a node
    node->key=key;//setting value of node
    node->left=NULL;//left child is kept NULL
    node->right=NULL;//right child is kept NULL
    node->height=1;//whenever we make a node and we insert in a tree it is a leaf node.hence the node above it has height 1 

    return node;
}

int getBalanceFactor(struct Node* n)
{
    if(n==NULL)//balance factor of leaf node is 0.this node is alone without any child
        return 0;
    
    return getHeight(n->left) - getHeight(n->right);//to get balance factor of node n
}

struct Node* rightRotate(struct Node* y)//rotate right wrt y & y is root node
{
    //x is going to become root and T2 is going to be connected to completely different node
    struct Node* x=y->left;//before rotation x is present as y's left child
    struct Node* T2=x->right;//before rotation T2 is x's right child

    //rewiring
    x->right=y;//after rotation 
    y->left=T2;//after rotation

    //update heights (T1,T2 heights are same)
    y->height=max(getHeight(y->right),getHeight(y->left))+1;//maximum height among y->right and y->left and add +1 because y itself is a node too and has height 1
    x->height=max(getHeight(x->right),getHeight(x->left))+1;//maximum height among x->right and x->left and add +1 because x itself is a node too and has height 1

    return x;//after rotation x is root node
}

struct Node* leftRotate(struct Node* x)//rotate left wrt x & x is root node
{
    //y is going to become root and T2 is going to be connected to completely different node
    struct Node* y=x->right;//before rotation
    struct Node* T2=y->left;//before rotation

    //rewiring
    y->left=x;//after rotation
    x->right=T2;//after rotation

    //update heights (T1,T2 heights are same)
    y->height=max(getHeight(y->right),getHeight(y->left))+1;//maximum height among y->right and y->left and add +1 because y itself is a node too and has height 1
    x->height=max(getHeight(x->right),getHeight(x->left))+1;//maximum height among x->right and x->left and add +1 because x itself is a node too and has height 1

    return y;//after rotation y is root node
}

struct Node* insert(struct Node* node,int key)
{
    if(node==NULL)
        return(createNode(key));//if there is nothing then make a node

    if(key < node->key)//if key is smaller than node's key then:
        node->left = insert(node->left,key);//insert at left subtree
    else if(key > node->key)//if key is bigger than node's key then:
        node->right=insert(node->right,key);//insert at right subtree
        
        return node;

    node->height=1+max(getHeight(node->left),getHeight(node->right));//we are updating from leaf node to root. 1+ is used since this node has height too
    int bf=getBalanceFactor(node);//finds the balance factor of node

//if the balance factor is greater than 1 or less than -1 that is the node is unbalanced then we have 4 cases as shown below:
    //Left left case
    if(bf > 1 && key < node->left->key)//LL case
    {
        return rightRotate(node);//right rotation of node once for LL
    }

    //right right case
    if(bf < -1 && key > node->right->key)//RR case
    {
        return leftRotate(node);//left rotation once for node for RR
    }

    //left right case
    if(bf > 1 && key > node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    //right left case
    if(bf < -1 && key < node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;//we didn't change node and we return it back 
}

int main()
{
    struct Node* root=NULL;//root node created

    //Constructing nodes to form a tree by doing insertions
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);

    //doing preorder traversal
    preOrder(root);

    return 0;
}

