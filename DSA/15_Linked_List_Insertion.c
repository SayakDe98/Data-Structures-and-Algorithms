#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;//self referencing structure
};

void linkedListTraversal(struct Node* ptr)
{
    for(;ptr!=NULL;ptr=ptr->next)//using for loop instead of while loop
    {
        printf("Element : %d \n",ptr->data);
        //ptr=ptr->next;//this is valid if we don't use this same thing in updation statement
    }

}
//Case 1:
struct Node* insertAtBeginnning(struct Node* head,int data)//we make a function to insert at begin having parameter *head and data
{
    //Dynamically allocate ptr in heap using malloc
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));

    //pointing the next of ptr to head's memory location
    ptr->next=head;
    //assigning value of ptr as data
    ptr->data=data;
    return ptr;
}
//Case 2:
struct Node* insertInBetween(struct Node* head,int data,int index)//a function to insert at an index which is not at beginning
{//we need parameters head,data,index at which we want to insert the new node
    //Dynamically allocating pointers of struct Node* data type
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    //p points to head
    struct Node* p=head;

    int i=0;//a variable to be used as an iterator from head till the index-1 because we want to place the new node at index so we reach the node just before it by doing index-1
    while(i!=index-1)
    {
        p=p->next;//p has now value of next index
        i++;//increasing till we reach index-1
    }
    ptr->data=data;//setting data of new node
    ptr->next=p->next;//the new node has it next pointer pointed to index+1 as the p was pointing to index+1 node previously so now ptr points to node@index+1 
    p->next=ptr;//p's pointer now points to ptr as p is @ index-1 and ptr is at index

    return head;//we return the head at the end of function as head hasn't changed
}
//Case 3:
struct Node* insertAtEnd(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//dynamically allocating a new node
    
    ptr->data=data;//assigning ptr's data as data

    struct Node* p=head;//making the pointer p as head

    while(p->next!=NULL)
    {
        p=p->next;//keep incrementing p till we reach the last node
    }
    p->next=ptr;//p's next is pointing ptr
    ptr->next=NULL;//ptr's next pointer points to NULL to denote end of linked lit

    return head;//we are returning head as there is no work of head done 
}
//Case 4:
struct Node* insertAfterNode(struct Node *head,struct Node *prevNode,int data)//we don't even need head node here its here for simplicity
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//ptr is the current node or new node which is to be inserted
    ptr->data=data;//assigning value of ptr as data
    ptr->next=prevNode->next;//ptr's next pointer points to prevNode's next which is nextNode.first we connect the next properly then in next line we see we make the prevnode point to ptr
    prevNode->next=ptr;//disconnecting the next pointers connection from nextNode to currentNode/ptr
    

    return head;//because this function is of struct Node* type so we return head
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

    printf("Linked List Before Insertion:\n");
    linkedListTraversal(head);
    //head=insertAtBeginnning(head,77);//we are updating head to the new head that we will get from the insertAtBeginning
    int data=59,index=2;
    //head=insertInBetween(head,data,index);
    //head=insertAtEnd(head,data);
    head=insertAfterNode(head,third,data);
    printf("After inserting new node the linked list looks like : \n");
    linkedListTraversal(head);
    
    return 0;
    
}