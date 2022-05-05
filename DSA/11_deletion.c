#include<stdio.h>

void display(int arr[],int n)
{   //code for Traversal
    for(int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);//we can do  printf("%d\n",arr[i]);to display in next line
    }
    printf("\n");
}

int indexDeletion(int arr[],int size,int index)
{
    //code for Deletion
    //if(size<=capacity) return -1;//if we return -1 means our deletion is unsuccessful

    for (int i = index; i <= size-1; i++)//<size-1 means upto size -2 
    {
        arr[i]=arr[i+1];
    }

   // size+=1;//increase size by 1 since we have added one extra element
    //display(arr,size);
    
    return 1;
    
}

int main()
{
    int arr[100]={1,2,6,78};//we allocated a memory for 100 elements but we used only 4 elements such that we can use other 96 elements at later point of time
    int size=4;//we are using only size out of 100 elements
    display(arr,size);
    int index=1;//delete at index 1
    int a=indexDeletion(arr,size,index);//we want to delete an element at an index 
    size-=1;//we deleted an element so size of array which is being used decreases
    display(arr,size);

    return 0;
    
}