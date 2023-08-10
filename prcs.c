#include<stdio.h>
void swap();
void main()
{
    int i,n,j,at[10],bt[10],ct[10],tat[10],wt[10],p[10],pr[10];
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter AT BT PR PID");
        scanf("%d%d%d%d",&at[i],&bt[i],&pr[i],&p[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(pr[j]>pr[j+1])
            {
                swap(&pr[j],&pr[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    ct[i]=ct[i-1]+bt[i];
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

}
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}