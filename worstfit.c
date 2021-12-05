#include <stdio.h>

int worstFit(int m,int b,int b1[])
{
    int i,maxIdx=0,flag=0;
    for(i=0;i<b;i++)
        if(m <= b1[i])
            flag++;
    if(flag == 0)
        maxIdx=-1;
    for(i=1;i<b;i++)
        if(m <= b1[i])
            maxIdx = i;
    return maxIdx;
}

int main()
{
    int bl[10],b1[10],p[10],alloc[10],i,j,b,n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of blocks: ");
    scanf("%d",&b);
    
    printf("Enter process array\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter block array\n");
    for(i=0;i<b;i++)
    {
        scanf("%d",&bl[i]);
        b1[i] = bl[i];
        alloc[i] = -1;
    }
    
    for(i=0;i<n;i++)
    {
        int wIdx = worstFit(p[i],b,b1);
        if(wIdx != -1)
        {
            alloc[i] = wIdx;
            b1[wIdx] -= p[i];
        }
    }
    
    printf("P\tB\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\n",p[i],alloc[i]);
    return 0;
}