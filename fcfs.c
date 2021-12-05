#include<stdio.h>

struct fcfs
{
    int p,at,wt,bt,tat,bt1,ct;
};

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i,j,n,t;
    struct fcfs f[20];
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Enter Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        f[i].p = i+1;
        scanf("%d%d",&f[i].at,&f[i].bt);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(f[j].at > f[j+1].at)
            {
                swap(&f[j].at,&f[j+1].at);
                swap(&f[j].bt,&f[j+1].bt);
                swap(&f[j].p,&f[j+1].p);
            }
            else if(f[j].at == f[j+1].at)
            {
                if(f[i].p > f[j].p)
                    swap(&f[j].p,&f[j+1].p);
                else
                    continue;
            }
            else
                continue;
        }
    }
    t = f[0].bt;
    f[0].ct = t;
    for(i=1;i<n;i++)
    {
        if(f[i].at > t)
            t = f[i].at;
        f[i].ct = t + f[i].bt;
        t = f[i].ct;
    }
    
    for(i=0;i<n;i++)
    {
        f[i].tat = f[i].ct - f[i].at;
        f[i].wt = f[i].tat - f[i].bt;
    }
    printf("P\tAT\tBT\tCT\tWT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",f[i].p,f[i].at,f[i].bt,f[i].ct,f[i].wt);
    return 0;
} 