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
    int isSorted=0;//assuming array isn't sorted
    for (int i = 0; i < n-1 ; i++)//for doing the passes.for size n there will be n-1 passes so loop runs from 0th pass to n-1 pass
    {
        printf("Working on pass number %d \n",(i+1));//to show which pass the control is working on
      for(int j=0;j<n-1-i;j++) //for doing comparisions to check whether two subsequent elements are sorted or not,we are doing n-i-1 because for size=n we need to do n-i-1 comparisions we can make a table to understand why this is done
      {
          isSorted=1;//if control does'nt get inside if block then it is sorted
          if(A[j]>A[j+1])//for j=0 we check if A[0]>A[1] then swap because we are doing ascending order sort
          {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
               isSorted=0;//array isn't sorted
          }//swapping two consecutive numbers
      }
      //in every pass we are checking if it got sorted,if it is already sorted then we won't do anymore passes
      if(isSorted) return;//if array is sorted after i th pass then don't do next pass
    }
    
}
int main()
{
    // int A[]={1,2,3,4,5,6};
    int A[]={1,5,2,6,8,7};
    int n=6;
    printf("Before sorting:\n");
    printArray(A,n);//prints the elements of array
    bubbleSort(A,n);//function to sort array
    printf("After sorting:\n");
    printArray(A,n);//print array after bubble sort is performed

    return 0;
    
}