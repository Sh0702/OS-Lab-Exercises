#include <stdio.h>

int max(int n,int arr[])
{
    int i,m=-1;
    for(i=0;i<n;i++)
        if(arr[i] > m)
            m = arr[i];
    return m;
}

int main()
{
    int i,j,n,m,pagefaults=0,flag=0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter number of string elements: ");
    scanf("%d",&m);
    int pages[n],index[n],refstring[m];
    for(i=0;i<m;i++)
    {
        printf("Enter string value %d: ",i+1);
        scanf("%d",&refstring[i]);
    }
    for(i=0;i<n;i++)
        index[i] = 0;
    if(n < m)
    {
        int temp;
        for(i=0;i<n;i++)
        {
            pages[i] = refstring[i];
            for(j=0;j<i;j++)
                index[j]++;
            pagefaults++;
        }
        for(i=n;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(refstring[i] == pages[j])
                {
                    temp = j;
                    flag++;
                }
            }
            if(flag == 0) //miss
            {
                int lru = max(n,index);
                pages[lru] = refstring[i];
                index[lru] = 0;
                pagefaults++;
            }
            else
            {
                flag = 0;
                index[temp] = 0;
            }
        }
    }
    else
    {
        for(i=0;i<m;i++)
            pages[i] = refstring[i];
            pagefaults++;
    }
    printf("Number of page faults: %d\n",pagefaults);
    printf("Page Table\n");
    if(n < m)
        for(i=0;i<n;i++)
            printf("%d\t",pages[i]);
    else
        for(i=0;i<m;i++)
            printf("%d\t",pages[i]);
    return 0;
}