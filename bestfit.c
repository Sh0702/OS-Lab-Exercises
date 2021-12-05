#include <stdio.h>

int bestFit(int m,int n,int a[])
{
    int i,diff,bestIdx = n-1;
    for(i=0;i<n;i++)
    {
        if(m <= a[i])
        {
            diff = a[i]-m;
            if(diff <= a[bestIdx] - a[i])
                bestIdx = i;
        }
    }
    return bestIdx;
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
        int bIdx = bestFit(p[i],b,b1);
        alloc[i] = bIdx;
        b1[bIdx] -= p[i];
    }
    
    printf("P\tB\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\n",p[i],alloc[i]);
    return 0;
}