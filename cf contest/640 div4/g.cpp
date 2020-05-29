#include<stdio.h>

int main()
{
    int t,n,i,h,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=3)
        {
            printf("-1\n");
            continue;
        }
        if(!(n%2))
            h=n-1;
        else
            h=n;
        for(i=h;i>0;i-=2)
        {
            printf("%d ",i);
        }

        x=i+5;
        printf("%d ",x);
        for(i=2;i<=n;i+=2)
        {
            if(i!=x)
                printf("%d ",i);
        }

        printf("\n");
    }
}
