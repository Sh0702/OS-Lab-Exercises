#include <stdio.h>

int main()
{
    int i,j,n,m,pagefaults=0,flag=0,front=0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter number of reference string values: ");
    scanf("%d",&m);
    int pages[n],refstring[m];
    for(i=0;i<m;i++)
    {
        printf("Enter string value %d: ",i+1);
        scanf("%d",&refstring[i]);
    }
    for(i=0;i<n;i++)
        pages[i] = -1;
    if(n < m)
    {
        for(j=0;j<n;j++)
        {
            if(pages[j] == -1)
            {
                pages[j] = refstring[j];
            }
        }
        for(j=n;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                if(refstring[j] == pages[i])
                    flag++;
            }
            if(flag == 0)
            {
                pagefaults++;
                pages[front] = refstring[j];
                front++;
                if(front > n-1)
                    front = 0;
            }
            else
                flag = 0;
        }
    }
    else
    {
        for(i=0;i<m;i++)
            pages[i] = refstring[i];
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