#include<stdio.h>
#include<stdlib.h>

struct DEqueue{
    int size;//stores size of queue
    int f;//helps to store index of front
    int r;//helps to store index of rear
    int *arr;//array to store the queue elements
};

int isEmpty(struct DEqueue *q)
{
    if(q->f==q->r) return 1;//queue is empty
    else return 0;//queue is not empty
}

int isFull(struct DEqueue *q)
{
    if(q->r==q->size-1) return 1;//queue is full
    else return 0;//queue is not full
}

void enqueueRear(struct DEqueue* q,int val)
{   
    if(isFull(q)) printf("DE Queue is full\n");
    else{
        q->r++;//incrementing the value of r to point to next index of DE queue(array)
        q->arr[q->r]=val;//assigning val to rth index of array
    }
}

void enqueueFront(struct DEqueue* q,int val)
{   
    if(isFull(q)) printf("DE Queue is full\n");
    else{
        q->arr[q->f]=val;
        q->f--;
    }
}

int dequeueFront(struct DEqueue* q)
{
    int a=-1;
    
    if(isEmpty(q)) printf("DE Queue is empty\n");
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}


int dequeueRear(struct DEqueue* q)
{
    int a=-1;
    
    if(isEmpty(q)) printf("DE Queue is empty\n");
    else{
        a=q->arr[q->r];
        q->r--;
    }
    return a;
}

int main()
{
    struct DEqueue q;//static allocation of DEqueue q
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*(sizeof(int)));//dynamically allocating an integer array to store DEqueue

    if(isEmpty(&q)) printf("DE Queue is empty\n");//we have to provide address of q because we are using pointer in isEmpty function

    enqueueRear(&q,15);
    enqueueRear(&q,99);
    enqueueRear(&q,18);
    enqueueRear(&q,18);
    
    if(isEmpty(&q)) printf("DE Queue is empty\n");//we have to provide address of q because we are using pointer in isEmpty function
    
    printf("%d is dequeued/removed\n",dequeueRear(&q));
    printf("%d is dequeued/removed\n",dequeueFront(&q));
    
    enqueueFront(&q,55);
    
    printf("%d is dequeued/removed\n",dequeueFront(&q));

    return 0;
}
