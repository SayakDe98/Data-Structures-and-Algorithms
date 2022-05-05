#include<stdio.h>

void printArray(int *A,int n)//function to print array
{
    for(int i=0;i<n;i++)//traverses whole array
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubbleSort(int* A,int n)
{
    int temp;
    for (int i = 0; i < n-1 ; i++)//for doing the passes.for size n there will be n-1 passes so loop runs from 0th pass to n-1 pass
    {
      for(int j=0;j<n-1-i;j++) //for doing comparisions to check whether two subsequent elements are sorted or not,we are doing n-i-1 because for size=n we need to do n-i-1 comparisions we can make a table to understand why this is done
      {
          if(A[j]>A[j+1])//for j=0 we check if A[0]>A[1] then swap because we are doing ascending order sort
          {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
          }//swapping two consecutive numbers
      }
    }
    
}
int main()
{
    int A[]={12,54,65,7,23,9};
    int n=6;
    printf("Before Sorting : \n");
    printArray(A,n);//prints the elements of array
    bubbleSort(A,n);//function to sort array
    printf("After Sorting : \n");
    printArray(A,n);//print array after bubble sort is performed

    return 0;
    
}