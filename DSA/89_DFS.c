#include<stdio.h>
#include<stdlib.h>

    
    int visited[7]={0,0,0,0,0,0,0};//initiazling all elements as 0 means all elements are unvisited
    
    //Making the graph global for doing DFS
    int A[7][7]={
                {0,1,1,1,0,0,0},//for node 0
                {1,0,1,0,0,0,0},//for node 1
                {1,0,0,1,1,0,0},//for node 2
                {1,1,1,1,1,0,0},//for node 3
                {0,0,1,1,0,1,1},//for node 4
                {0,0,0,0,1,0,0},//for node 5
                {0,0,0,0,1,0,0}//for node 6
    };

void DFS(int i)
{
    int j;
    printf("%d ", i );//print the current node 

    visited[i]=1;//node which is visited is marked 1

    for(int j = 0 ; j < 7 ; j++)
    {
        if(A[i][j] == 1 && !visited[j])//A[i][j] ==1 i  is the node where we are present and the node which is going to the present node and the the node to which it is connecting is unvisited
        {
            DFS(j);//call the function itself for j
        }
    }
}
 
int main()
{

    //DFS implementation
    DFS(0);//starting from node 0

    return 0;
}