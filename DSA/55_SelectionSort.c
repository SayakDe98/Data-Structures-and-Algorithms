#include<stdio.h>

void printArray(int* A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void selectionSort(int* A,int n)//we took A as a pointer so that we can change array later
{
    int indexOfMin,temp;
    for (int i = 0; i < n-1; i++)//for n-1 cases we do this loop
    {
        indexOfMin=i;//assuming that element at current index has least value among remaing unsorted array
        for(int j=(i+1);j<n;j++)//a loop to check if any other element in unsorted array has lesser value than at current position that is position i
        {
            if(A[j]<A[indexOfMin])//if we find any element smaller than indexofMin
            {
                indexOfMin=j;//now indexofMin is updated to j as j's index has an element which is lesser than indexofMin.means we are chaning indexes here
            }
        }
        //swapping A[i] and A[indexOfMin] when we get a minimum element after searching for lesser element in remaning unsorted array 
        temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp; 
    }
    
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int A[]={3,5,2,3,2};
    int n=5;

    printf("Array before Sorting : \n");
    printArray(A,n);
    
    selectionSort(A,n);
    
    printf("Array after Sorting : \n");
    printArray(A,n);

    return 0;
    
}