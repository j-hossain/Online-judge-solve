#include<stdio.h>

int main()
{
    int n,i,num[101],x,p,cnt;

    for(i=0;i<101;i++)
        num[i]=0;
    cnt=0;

    scanf("%d",&n);

    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%d",&x);
        if(!num[x])
        {
            num[x]=1;
            cnt++;
        }
    }

    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%d",&x);
        if(!num[x])
        {
            num[x]=1;
            cnt++;
        }
    }
    if(n==cnt)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    return 0;
}
