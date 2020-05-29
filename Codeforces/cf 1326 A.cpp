#include<stdio.h>

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<n-1;i++)
            printf("3");
        printf("4\n");
    }
    return 0;
}
