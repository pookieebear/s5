#include<stdio.h>
#include<math.h>
int size=8;

int main()
{
    int arr[8]={176,79,34,60,92,11,41,114};
    int head =50;
    fcfs(arr,head);
}

void fcfs(int arr[8],int head)
{
    int dis,seek=0,track;
    for(int i=0;i<size;i++)
    {
        track=arr[i];
        dis=fabs(head-track);
        seek+=dis;
        head=track;
    }
    printf("\nTotal = %d",seek);
    
}