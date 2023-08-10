#include<stdio.h>
int max[10][10],need[10][10],alloc[10][10];
int avail[10];
int n,r;
void read();
void display();
void calc();
void banker();
int main()
{
    int j;
    printf("\nEnter no.of processes  ");
    scanf("%d",&n);
    printf("\nEnter no.of resources  ");
    scanf("%d",&r);
    printf("\nEnter Max ");
    read(max);
    printf("\nEnter alloc ");
    read(alloc);
    printf("\nEnter avail ");
    for(j=0;j<r;j++)
    {
        scanf("%d",&avail[j]);
    }
    
    
    printf("\nAlloc: \n");
    display(alloc);
    printf("\nMax\n");
    display(max);
    printf("\nAvail\n");
    for(j=0;j<r;j++)
    {
        printf("%d",avail[j]);
    }
    calc();
    display(need);
    banker();
    
}

void read(int matrix[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<r;j++)
        scanf("%d",&matrix[i][j]);

}

void display(int matrix[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\n P%d",i);
        for(j=0;j<r;j++)
        {
            printf(" %d",matrix[i][j]);
        }
    }
}

void calc()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
}

void banker()
{
    int i,j,k=0,flag;
    int finish[10],safe[10];
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        if(finish[i]==0)
        {
        for(j=0;j<r;j++)
        {
            if(need[i][j]>avail[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            finish[i]==1;
            safe[k]=i;
            k++;
            for(j=0;j<r;j++)
            avail[j]+=alloc[i][j];
            i=-1;  
        }
    
        }
    }
    flag=0;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
        printf("\nSystem is in deadlock");
        flag=1;
        break;
        }
    }
    if(flag==0)
    {
        printf("\nThe system is safe \n seq : ");
        for(i=0;i<n;i++)
         printf("P%d",safe[i]);
    }
}