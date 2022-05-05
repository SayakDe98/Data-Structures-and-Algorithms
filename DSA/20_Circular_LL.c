#include <stdio.h>
#include <stdlib.h> //using this cause we are doing malloc

struct Node
{
    int data;
    struct Node *next; // this is a struct Node type of pointer and it points to this type of structures
};


void circularLinkedListTravsersal(struct Node *head) // passing parameter pointer *ptr of struct Node data type so that this function can travserse this linked list
{   
    struct Node* ptr=head;
    do{
        printf("Element : %d \n", ptr->data); // printing data of current node
        ptr = ptr->next;                      // pointer points to next address after printing the data of current node
      }while(ptr!=head);
}


struct Node* insertAtFirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));//requesting memory for 1 node
    ptr->data=data;//after making node set data
    struct Node* p=head->next;//p points to second node
    while(p->next!=head)//we want to move p to last node
    {
        p=p->next;
    }
    //at this point p points to last node of this circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;//now ptr becomes head

    return head;
}




 
int main()
{
    // Allocating memory of nodes of linked list in the heap memory cause dynamic memory allocation
    struct Node *head;
    struct Node *third;
    struct Node* fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    // linked first and second node
    head->data = 7;
    head->next = second;

    // linked second and third node
    second->data = 11;
    second->next = third;

    // linked third and fourth node
    third->data = 66;
    third->next = fourth;

    // terminate the linked list at fourth node
    fourth->data=111;
    fourth->next=head;//fourth->next is head means after fourth node we have traversed once and we point to head to show its circular

    printf("Circular Linked List before Insertion :\n ");
    // calling function linkedListTraversal to traverse the linkedlist
    circularLinkedListTravsersal(head); // passing argument head(which is a pointer of struct Node* type) (since we start travsersal) from head to the function

    head=insertAtFirst(head,56);
    
    printf("After inserting in circular linked list : \n");
    circularLinkedListTravsersal(head);
    return 0;
}