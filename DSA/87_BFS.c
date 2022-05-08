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
    q.size=400;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*(sizeof(int)));//dynamically allocating an integer array to store queue

    int u;
    int i=0;//to start from node 0
    int visited[7]={0,0,0,0,0,0,0};//initiazling all elements as 0 means all elements are unvisited
    int a[7][7]={
                {0,1,1,1,0,0,0},//for node 0
                {1,0,1,0,0,0,0},//for node 1
                {1,0,0,1,1,0,0},//for node 2
                {1,1,1,1,1,0,0},//for node 3
                {0,0,1,1,0,1,1},//for node 4
                {0,0,0,0,1,0,0},//for node 5
                {0,0,0,0,1,0,0}//for node 6
    };

    printf("%d ",i);//printing the starting index i
    visited[i]=1;//visited node is used 

    enqueue(&q,i);//enqueue i for exploration

    while(!isEmpty(&q))//until our queue is empty
    {
        int node = dequeue(&q);

        for(int j=0;j<7;j++)
        {
            if(a[node][j] == 1 && visited[j]== 0)//a[node][j]=1 means the node is connected to current node and visited[j]==0 means that node is unvisited
            {
                printf("%d ",j);//print the new node which we are visiting
                visited[j]=1;//means this node is now visited after we printed it
                enqueue(&q,j);//we insert this node into queue since it is explored
            }
        }
    }



    return 0;
}
