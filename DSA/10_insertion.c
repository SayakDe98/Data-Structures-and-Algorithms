#include<stdio.h>

void display(int arr[],int n)
{   //code for Traversal
    for(int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);//we can do  printf("%d\n",arr[i]);to display in next line
    }
    printf("\n");
}

int indexInsertion(int arr[],int size,int element,int capacity,int index)
{
    //code for Insertion
    if(size>=capacity) return -1;//if we return -1 means our insertion is unsuccessful

    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
   // size+=1;//increase size by 1 since we have added one extra element
    //display(arr,size);
    
    return 1;
    
}

int main()
{
    int arr[100]={1,2,6,78};//we allocated a memory for 100 elements but we used only 4 elements such that we can use other 96 elements at later point of time
    int size=4;//we are using only size out of 100 elements
    display(arr,size);
    int element=45;//we want to insert element into array
    int index=3;//insert at index 3
    int a=indexInsertion(arr,size,element,100,index);//we want to insert an element at an index of an array of capacity 100
    if(a==1) {size+=1;display(arr,size);};

    return 0;
    
}