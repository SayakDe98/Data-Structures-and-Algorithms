#include<stdio.h>

int linearSearch(int arr[],int size,int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i]==element)return i;
    }
    return -1;
    
}

int binarySearch(int arr[],int size,int element)
{
    int low=0;//low is assigned the 0th index
    int high=size-1;//size is assigned the last index,we are doing size-1 instead of size because array starts from 0 and ends at size-1
    int mid;
    while(low<=high)//we are going to keep searching till the low and high becomes same in such case we got the element or low becomes more than high in that case element is not present in array
    {
        mid=(low+high)/2;//we are not declaring mid here cause it will keep getting initialized everytime we run while loop
        if(arr[mid]==element)return mid;//if we got the element we return the index of mid

        else if(arr[mid]<element) low=mid+1;//if the element in array is less than that of the required element we assign (mid+1)'s index to low's index
//we are doing mid+1 instead of mid since mid is not having the element so we are searching exclusive of mid
        else if(arr[mid]>element) high=mid-1;//if the element in array is more than that of the required element we assign (mid-1)'s index to high
        //we are doing mid-1 instead of mid since mid is not having the element so we are searching exclusive of mid
    }
    return -1;//return -1 as we were unable to find the required element inside the array as it is absent in the array 

}

int main()
{
    //int arr[]={1,44,222,89,99,2,45};//array containing elements(unsorted) for linear search
    //int size=sizeof(arr)/sizeof(int);//sizeof(arr) gives size of elments * size of int so we divide by sizeof(int)
    int arr[]={1,4,22,89,99,255,455};//array containing sorted elements for binary search
    int size=sizeof(arr)/sizeof(int);//sizeof(arr) gives size of elments * size of int so we divide by sizeof(int)
    int element=99;
    //int searchIndex=linearSearch(arr,size,element);//storing the value of search index in local variable to print it later
    int searchIndex=binarySearch(arr,size,element);//storing the value of search index in local variable to print it later
    if(searchIndex==-1) printf("Element not found in array");
    else printf("Element %d found at index %d ",element,searchIndex);

    return 0;
    
}