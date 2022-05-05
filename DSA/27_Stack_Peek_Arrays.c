#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)//means stack is full
        return 1;
    else
        return 0;
}

int push(struct stack *ptr,int value)//we are passing arguments ptr and value
{
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else{
        ptr->top++;//incrementing top by 1
        ptr->arr[ptr->top]=value;//arr's value at top is value
    }
    return value;//returning new top's value
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
        printf("Stack Underflow\n");
    
    else{
        int value=ptr->arr[ptr->top];//value of arr at top index is stored in value
        ptr->top--;//decrementing top by 1
        return value;
    }
}

int peek(struct stack *ptr,int i)//i is the position of the element
{
    int arrayIndex=ptr->top - i +1;
    if(arrayIndex < 0) {printf("Invalid Position");return -1;}
    else{
        return ptr->arr[arrayIndex];
    }
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=80;//assume a large size of stack
    s->top=-1;//initializing top as -1 a stack is empty initially
    s->arr=(int*)malloc(s->size*(sizeof(int)));
    printf("Stack created successfully\n");

 if(isFull(s))
    {
        printf("Stack is full\n");

    }
    else
    {
        printf("Stack is not full\n");
    }

    if(isEmpty(s))
        printf("Stack is empty\n");
    else    
        printf("Stack is not empty\n");

    push(s,57);
    push(s,59);
    int a=pop(s);
    printf("%d\n",a);
    push(s,555);
    push(s,66);
    push(s,89);
    if(isFull(s))
    {
        printf("Stack is full\n");

    }
    else
    {
        printf("Stack is not full\n");
    }

    if(isEmpty(s))
        printf("Stack is empty\n");
    else    
        printf("Stack is not empty\n");

    //the elements will get printed in LIFO manner 
    for (int i = 1; i <= s->top+1; i++)
    {
         printf("The value at position %d is : %d\n",i,peek(s,i));
    }
    
    
    return 0;
    
}