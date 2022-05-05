#include <stdio.h>
#include <stdlib.h> //using this cause we are doing malloc

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
    fourth->next=NULL;//fourth->next is NULL means after fourth node we have completely traversed the full linked list

    // calling function linkedListTraversal to traverse the linkedlist
    linkedListTravsersal(head); // passing argument head(which is a pointer of struct Node* type) (since we start travsersal) from head to the function

    return 0;
}