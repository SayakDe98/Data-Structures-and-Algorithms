#include<stdio.h>
#include<stdlib.h>
//ADT is custom data type which is made of set of values and set of operations(functions)
struct myArray{//creating an abstract data type myArray to store some numbers
    int total_size;//we declared a variable which stores total size of array
    int used_size;//we declared a variable stores size of array which will be used to store data
    int *ptr;//a pointer to point to the base address of myArray
};

void createArray(struct myArray* a, int tSize,int uSize)//making this function to define the total_size,used_size and *ptr.this has a structure pointer parameter,tSize parameter to get the totalSize and uSize to get the used size 
{//by using parameter struct myArray *a,we can change other values(total_size,used_size) and use them
    //we can use the below three lines or use this operator
    // (*a).total_size=tSize;//dereferncing the pointer a and access the total_size and set it to tSize
    // (*a).used_size=uSize;//dereferncing the pointer a and access the used_size and set it to uSize
    // (*a). ptr=(int* )malloc(tSize*sizeof(int));//allocating memory dynamically using pointer
     //we have used this operator below and they do same operation
     a->total_size=tSize;//dereferncing the pointer a and access the total_size and set it to tSize
     a->used_size=uSize;//dereferncing the pointer a and access the used_size and set it to uSize
     a-> ptr=(int* )malloc(tSize*sizeof(int));//requests dynamic memory in heap and points to first memory location of myArray
    //by using malloc we request memory in heap and gives a pointer which points to 0th element,
    //by doing that the memory will stay occupied even after createArray fnction is returned and we can keep accessing it .
    //we have to manually deallocate this memory using free ,if we want to free that memory
//we were type casting int * here
}

void show(struct myArray* a)//function to show myArray's elments,*a is done to access all values(total_size,used_size) inside structure by derefercing  whereas & is for referencing
{
    for(int i=0;i<a->used_size;i++)//a->used_size means we are using the pointer a to point to the location of used_size so we can get its value
    {
        printf("%d ",(a->ptr)[i]);//(a->ptr)[i] is used to point to the ith index of myArray using pointer
    }
}

void setVal(struct myArray* a)//passing myArray *a as a parameter
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter the %d element : ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;//assigning value of (a->ptr)[i] as n
    }
}
int main()
{
    struct myArray Btree;//creating an instance of the ADT myArray named marks.as we do this compiler makes a struture and memory is allocated for the data members inside structure like total_size,used_size and pointer*ptr
    createArray(&Btree,20,7);//we passed address of marks to the pointer and we pass the total size of myArray and used size of myArray 
    setVal(&Btree);
    printf("The values of myArray : \n");
    show(&Btree);//we get garbage value if we don't use setVal function to set the values
    return 0;
    
}