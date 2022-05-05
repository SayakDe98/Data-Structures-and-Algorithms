#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    int C[high+1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        C[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        C[k] = A[j];
        k++;
        j++;
    }
    
    for(int i=low;i<=high;i++) 
        A[i]=C[i];
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};

    int n;
    n = 7;
    printf("Array before sorting : \n");
    printArray(A, n);
    mergeSort(A, 0, n-1);
    printf("Array after sorting : \n");
    printArray(A, n);
    return 0;
}
