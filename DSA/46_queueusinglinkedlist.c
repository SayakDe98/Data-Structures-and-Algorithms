#include<stdio.h>
#include<stdlib.h>
//declaring global variables because only copies were sent to the other functions like enqueue,dequeue and the values were not changing
 struct Node* f=NULL;//front pointer
    struct Node* r=NULL;//rear pointer


struct Node{
    int data;
    struct Node* next;//self referencing structure
};

void linkedListTravsersal(struct Node *ptr) // passing parameter pointer *ptr of struct Node data type so that this function can travserse this linked list
{
    printf("Prining the elments of this linked list:\n");
    while (ptr != NULL) // stops printing when pointer points to address which is NULL
    {
        printf("Element : %d \n", ptr->data); // printing data of current node
        ptr = ptr->next;                      // pointer points to next address after printing the data of current node
    }
}

void enqueue(int value)
{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL) printf("Queue is full\n");
    else{
        n->data=value;
        n->next=NULL;

        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue()
{
    int val=-1;
    struct Node* ptr=f;
    if(f==NULL) printf("Queue is empty\n");
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);

    }
    return val;
}


int main()
{

   
    linkedListTravsersal(f);

    enqueue(4);   
    enqueue(7);

     linkedListTravsersal(f);
     printf("Dequeueing element %d \n",dequeue());
     
     linkedListTravsersal(f);

    return 0;
}