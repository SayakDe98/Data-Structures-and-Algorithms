#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue* cq)
{
    if(cq->f==cq->r) return 1;//cq is empty
    else return 0;//cq not empty
}

int isFull(struct circularQueue* cq)
{
    if((cq->r+1)%cq->size==cq->f)   return 1;
    else return 0;
}

void enqueue(struct circularQueue* cq,int val)
{
    if(isFull(cq)) printf("Queue is full\n");
    else{
        cq->r=(cq->r+1)%cq->size;
        cq->arr[cq->r]=val;
        printf("Enqueued element %d\n",val);
    }
}

int dequeue(struct circularQueue* cq)
{
    int val=-1;
    if(isEmpty(cq)) return val;
    else{
        cq->f=(cq->f+1)%cq->size;
        val=cq->arr[cq->f];
    } 
    return val;
}

int main()
{   
    struct circularQueue cq;
    cq.size=4;
    cq.f=cq.r=0;//0 will never be used.circular queue can have size-1 elements in it
    cq.arr=(int*)malloc(cq.size*(sizeof(int)));

    if(isEmpty(&cq)) printf("Queue is empty\n");
    
    enqueue(&cq,66);
    enqueue(&cq,78);
    enqueue(&cq,789);

    if(isFull(&cq)) printf("Queue is full\n");

    printf("%d was poped\n",dequeue(&cq));
    printf("%d was poped\n",dequeue(&cq));
    printf("%d was poped\n",dequeue(&cq));
    if(isEmpty(&cq)) printf("Queue is empty\n");
 
    enqueue(&cq,1);
    enqueue(&cq,21);
    enqueue(&cq,12);

    if(isFull(&cq)) printf("Queue is full\n");

    return 0;
}