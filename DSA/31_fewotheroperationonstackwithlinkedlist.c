#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node* top)
{
    if(top==NULL) return 1;
    else return 0;
}

int isFull(struct Node* top)
{
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL) return 1;//if we are unable to allocate any more memory then stack is full
    else return 0;
}

struct Node* push(struct Node* top,int data)
{
    if(isFull(top)){ printf("Stack Overflow\n");}
    else
    {
        struct Node* n=(struct Node*)malloc(sizeof(struct Node));//making a new node
    n->data=data;//assigning data to n node
    n->next=top;//making current top as next node 
    top=n;//making n the top node
    }
    return top;//returning new top element
}

int pop(struct Node** top)//treating top as pointer of pointer
{
    if(isEmpty(*top)) printf("Stack underflow\n");
    else{
        struct Node* n=*top;
        *top=(*top)->next;//i.e. first dereference then do top->next.Making next node of top as top
        int x=n->data;//putting previous top's value in a variable
        free(n);//deallocating the data of previous top
        return x;//returning the old value of top to tell user that previous top is poped
    }
}

int peek(struct Node* top,int pos)
{
    struct Node*ptr=top;
    for(int i=0;(i<pos-1&&ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else return -1;
}

int stackTop(struct Node* top)
{
    return top->data;
}
int stackBottom(struct Node*top)
{
    struct Node*ptr=top;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node* top=(struct Node*)malloc(sizeof(struct Node));//top is a pointer
    top=NULL;//initializing top as NULL
    top=push(top,8);
    top=push(top,66);
    top=push(top,99);
    linkedListTraversal(top);
    int element=pop(&top);//pass by reference done
    printf("Element poped is %d\n",element);
    printf("Stack after poping element is : \n");
    linkedListTraversal(top);
    int pos=2;
    int p=peek(top,pos);
    if(p==-1)   printf("Invalid position\n");
    else printf("Element at position %d is %d\n",pos,p);

    printf("Element at stack top : %d\n",stackTop(top));
    printf("Element at stack bottom : %d\n",stackBottom(top));
    for(int i=1;i<=2;i++)
    {
        printf("Element at position %d is %d\n",i,peek(top,i));
    }
    return 0;
}