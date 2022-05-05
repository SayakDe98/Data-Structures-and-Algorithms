#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next; // this is a struct Node type of pointer and it points to this type of structures
};

void linkedListTravsersal(struct Node *ptr) // passing parameter pointer *ptr of struct Node data type so that this function can travserse this linked list
{
    while (ptr != NULL) // stops printing when pointer points to address which is NULL
    {
        printf("Element : %d \n", ptr->data); // printing data of current node
        ptr = ptr->next;                      // pointer points to next address after printing the data of current node
    }
}

struct Node* deleteAtBeginning(struct Node* head)//just need parameter of head
{
    struct Node *ptr=head;//storing address of head in ptr
    head=head->next;//second node is now head
    free(ptr);//we are freeing ptr

    return head;
}

struct Node* deleteNodeInBetween(struct Node* head,int index)//we need index parameter too
{
    struct Node *p=head;//storing address of head in p
    int i=0;//we need integer type variable since we need to iterate the while loop
    while(i!=index-1){//we are traversing linked list till we reach index-1th position 
        p=p->next;//p points to next node after each iteration
        i++;//incrementing i every time loop runs
    }
    struct Node* q=p->next;//q is pointing to next node of p
    p->next=q->next;//p next is now linked to q next
    free(q);//deleting q from heap

    return head;
}

struct Node* deleteAtEnd(struct Node* head)//taking only head parameter as input
{
    //using two pointers
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){//till we reach end of linked list we keep iterating
        q=q->next;//q now points to next node
        p=p->next;//p now points to next node that is q
    }
    p->next=NULL;//making p node last node
    free(q);//deleting q from heap

    return head;
}

struct Node* deleteFirstNodeWithGivenValue(struct Node* head,int data)//data is the value
{
    struct Node *p=head;//p pointer points to head
    struct Node*q=head->next;//q pointer points to next node
    while(p->data!=data&&q->data!=data &&q->next!=NULL){//if p has the correct data means its head,if q->next ==NULL means we traversed the whole linked list and the value wasn't present in it
        p=p->next;//pointing p to next node
        q=q->next;//pointing q to next node
    }
    if(p->data==data)//if we get data at head
    {
        head=q;//q's value is in head as we are making 2nd element head
        free(p);//deallocating p from heap memory
    }
    if(q->data==data)//if we get the data at q
    {
        p->next=q->next;//p's next points to q's next node
        free(q);//deallocating q
    }    

    return head;
}



int main()
{
    //Allocating dynamic memory for the Nodes of Linked List in heap
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //linked head and second Nodes of Linked List
    head->data=11;
    head->next=second;

     //linked second and third Nodes of Linked List
    second->data=20;
    second->next=third;

     //linked third and fourth Nodes of Linked List
    third->data=51;
    third->next=fourth;

     //terminated the Linked List at fourth Node
    fourth->data=111;
    fourth->next=NULL;

    printf("Linked List Before Deletion:\n");
    linkedListTravsersal(head);
    
    //head=deleteAtBeginning(head);
    
    //head=deleteNodeInBetween(head,2);
    
    //head=deleteAtEnd(head);
    
    head=deleteFirstNodeWithGivenValue(head,51);
    printf("Linked List after deletion:\n");
    linkedListTravsersal(head);
    return 0;
}