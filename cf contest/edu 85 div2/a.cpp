#include<stdio.h>
typedef struct
{
    int p;
    int c;
}stat;
int main()
{
    int t,n,i,flag,d1,d2;
    stat prev, now;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        prev.c=0;
        prev.p=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&now.p,&now.c);
            d1=now.p-prev.p;
            d2=now.c-prev.c;
            if(now.p<now.c || now.p<prev.p || now.c<prev.c || d1<d2)
                flag=1;
            prev=now;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
