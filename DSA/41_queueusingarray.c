#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;//stores size of queue
    int f;//helps to store index of front
    int r;//helps to store index of rear
    int *arr;//array to store the queue elements
};

int isEmpty(struct queue *q)
{
    if(q->f==q->r) return 1;//queue is empty
    else return 0;//queue is not empty
}

int isFull(struct queue *q)
{
    if(q->r==q->size-1) return 1;//queue is full
    else return 0;//queue is not full
}

void enqueue(struct queue* q,int val)
{   
    if(isFull(q)) printf("Queue is full\n");
    else{
        q->r++;//incrementing the value of r to point to next index of queue(array)
        q->arr[q->r]=val;//assigning val to rth index of array
    }
}

int dequeue(struct queue* q)
{
    int a=-1;
    
    if(isEmpty(q)) printf("Queue is empty\n");
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;//static allocation of queue q
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*(sizeof(int)));//dynamically allocating an integer array to store queue

    if(isEmpty(&q)) printf("Queue is empty\n");//we have to provide address of q because we are using pointer in isEmpty function

    enqueue(&q,15);
    enqueue(&q,19);
    enqueue(&q,18);
    if(isEmpty(&q)) printf("Queue is empty\n");//we have to provide address of q because we are using pointer in isEmpty function
    printf("%d is dequeued/removed\n",dequeue(&q));
    printf("%d is dequeued/removed\n",dequeue(&q));
    printf("%d is dequeued/removed\n",dequeue(&q));
    return 0;
}
