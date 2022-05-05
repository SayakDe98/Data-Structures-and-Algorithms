#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int *arr;
    int top;
};

int push(struct stack* ptr,int value)
{
    if(ptr->top==ptr->size-1){
        printf("Stack Overflow\n");return 0;}
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
    return value;
}

int pop(struct stack* ptr)
{
    if(ptr->top==-1){
                printf("Stack Underflow\n");
    return 0;}
    else
    {
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
    
}


int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size*(sizeof(int)));
    printf("Stack created successfully\n");
    push(s,55);
    push(s,77);
    push(s,89);
    printf("Element %d was poped\n",pop(s));

    printf("Element at stack top : %d\n",stackTop(s));
    printf("Element at stack bottom : %d\n",stackBottom(s));
}