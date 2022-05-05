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

int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=8;//assume a large size of stack
    s->top=-1;//initializing top as -1 a stack is empty initially
    s->arr=(int*)malloc(s->size*(sizeof(int)));
    printf("Stack created successfully\n");
printf("Checking if stack is empty/full before pushing any element :\n");
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
    push(s,696);
    push(s,616);
    push(s,266);
    push(s,660);
    push(s,661);
    push(s,665);
    push(s,63);
    push(s,67);//pushed 10 values in stack
    
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));
    printf("Element %d was poped from stack\n",pop(s));printf("Element %d was poped from stack\n",pop(s));

    printf("Checking whether stack is full/empty after performing push and pop operations\n");
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

    


    return 0;
    
}