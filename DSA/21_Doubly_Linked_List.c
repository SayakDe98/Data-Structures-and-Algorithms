#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* traversal(struct Node* head)
{
    struct Node* ptr=head;
    struct Node* p;
    int i=1;
    while(ptr!=NULL)
    {
        printf("Element %d : %d \n",i,ptr->data);
        if(ptr->next==NULL)
        {
            p=ptr;
        }
        ptr=ptr->next;
        i++;
        
    }
    printf("Traversing in reverse order now :\n");
    i--;;
    while(p!=NULL)
    {
        printf("Element %d : %d\n",i,p->data);
        p=p->prev;
        i--;
    }
    
}

int main()
{
    //allocating memory for nodes in heap memory
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));

    //linking the first with second nodes
    head->data=21;
    head->prev=NULL;
    head->next=second;

    //linking the second,head and third nodes
    second->data=55;
    second->prev=head;
    second->next=third;

    //linking third,second and fourth nodes
    third->data=77;
    third->prev=second;
    third->next=fourth;

    //linking the fourth ,third nodes
    fourth->data=8;
    fourth->prev=third;
    fourth->next=NULL;

    //travesersing the double linked list and printing it
    printf("Elements in Linked List : \n");
    traversal(head);
    return 0;
    
}