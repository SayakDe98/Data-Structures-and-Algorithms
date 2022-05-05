#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];//making first element as pivot
    int i = low + 1;//i finds position of element greater than element at pivot
    int j = high;//j finds position of element lesser than element at pivot
    int temp;//making a temporary variable to swap elements later

    do
    {
        while (A[i] <= pivot)
        {
            i++;//when we get an element at ith index which is less than equal to element at pivot then we increment the index of i
        }

        while (A[j] > pivot)
        {
            j--;//when we get an element at jth index which is less than element at pivot we decrement index of j
        }

        if (i < j)//this is executed atleast once so let's use do while loop
        {
            //swap A[i] and A[j] when i<j
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

   //swap A[low] i.e. element at pivot with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); //partitionIndex stores index of partition after partitioning
        quickSort(A, low, partitionIndex - 1);  //quick sorting left sub array after partitioning
        quickSort(A, partitionIndex + 1, high);//quick sorting right sub array after partitioning
           //we didn't sort partitionIndex because element at partitionIndex is already sorted
    }
}

int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int n = 9;
    n =7;
    printf("Array before sorting : \n");
    printArray(A, n);
    quickSort(A, 0, n - 1);
     printf("Array after sorting : \n");
    printArray(A, n);
    return 0;
}
