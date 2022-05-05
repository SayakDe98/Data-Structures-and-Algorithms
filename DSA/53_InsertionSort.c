#include<stdio.h>

void printArray(int *A,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertionSort(int* A,int n)//int* A means its an pointer and we are bringing an array
{ int j;
    for (int i = 1; i <= n-1; i++)//loop for passes
    {
        int key=A[i];//A[i] is the element which we will be moving from non sorted array to sorted array
        j=i-1;//j has previous index to check the current element with previous element to check later if prev element has lesser value or not
        while(j>=0 && A[j]>key)//when prev element has larger value than current element.means comparision happens here.if we do a[j]<key then we do descending order sort
         {//j can't be -1 if j=-1 then it won't be operated inside this loop
             A[j+1]=A[j];//we make prev element as current element
             j--;//decrementing value of j so that we can reach the index to insert current element
         }
         A[j+1]=key;//key will be inserted in j+1th index since key is smallest element
    }
    
}
int main()
{
    // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 

    int A[]={12,54,65,7,23,9};
    int n=6;//size=6
    
    printf("Before Sorting : ");
    printArray(A,n);
    insertionSort(A,n);

    printf("After Sorting : ");
    printArray(A,n); 
    return 0;
    
}