#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr)
{
    if (ptr->top == -1)
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
    if(ptr->top==ptr->size-1)//top of the stack points to size-1 we are doing -1 because array starts at 0 ends at size-1 
        return 1;
    else
        return 0;
}

int main()
{
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int*)malloc(s.size*sizeof(int));
    //alternate way
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));//we can pass function using *s as s is pointer
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

  /*  s->arr[0]=11;
    s->top++;*/
   /* s.arr[0]=11;
    s.top++;
    */
    if(isEmpty(s))
    {
        printf("Stack is empty");
    }
    else {printf("Stack is not empty");}
    return 0;
    
}