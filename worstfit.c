#include<stdio.h>
#define max 25
void main()
{
    int i,j,temp,nb,nf,b[max],f[max],frag[max],highest=0;
   static int ff[max],bf[max];
    printf("\nEnter no.of blocks : ");
    scanf("%d",&nb);
    printf("\nEnter no,of files");
    scanf("%d",&nf);
    printf("\nEnter sizo of blocks");
    for(i=0;i<nb;i++)
    {
        printf("\nsize of block %d : ",i+1);
        scanf("%d",&b[i]);
    }
    printf("\nEnter sizo of files");
    for(i=0;i<nf;i++)
    {
        printf("\nsize of file %d : ",i+1);
        scanf("%d",&f[i]);
    }

    for(i=0;i<nf;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                if(highest<temp)
                {
                    ff[i]=j;
                    highest=temp;
                }
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }
    printf("\nFile\tFile_Sz\tBlock_no\tBlock_sz\tFragment");
    for(i=0;i<nf;i++)
    {
        printf("\n%d\t%d\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
    }
}