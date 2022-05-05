#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[],int n)//function to find maximum element from given(main) array
{
    int max=INT_MIN;//initialzing max with least value of integer
    for(int i=0;i<n;i++)//loop to find maximum element in given array
    {
        if(max<A[i])
            max=A[i];
    }
}

void countSort(int* A,int n)
{
    int max=maximum(A,n);//variable to store maximum element
    int i,j;

    int* count=(int*)malloc((max+1)*sizeof(int));//dynamically allocating count array
    
    //initiazlize the array elements of count array to 0
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }

    //increment the corresponding index in count array.
    for(int i=0;i<n;i++)
    {
        count[A[i]]=count[A[i]]+1;//if we get any element say k is the element in main array then we increase the value of kth index in count array 
    }

    //initializing counters
    i=0;//i is counter for count array 
    j=0;//j is counter for given array(A array) 

    while(i<=max)//keep iterating count array till we reach end of count array
    {
        if(count[i]>0)//if in count array there is any non zero element at an index means in main array there is an element of that index 
        {//we are moving elements from count array to original array in a sorted order
            A[j]=i;//copying elements to main array
            count[i]--;//decrementing value of ith index by 1 
            j++;//incrementing index of main array so that we can insert element from count array to main array
        }
        else 
        {
            i++;//if there is no non zero element in particular index of count array we move to next index of count array
        }
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};//given/main array

    int n;
    n = 7;//size of array
    printf("Array before sorting : \n");
    printArray(A, n);
    countSort(A,  n);
    printf("Array after sorting : \n");
    printArray(A, n);
    return 0;
    
}