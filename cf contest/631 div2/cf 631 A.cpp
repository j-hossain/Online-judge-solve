#include<stdio.h>
int main()
{
    int num[300],n,a,i,cnt,temp,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<300;i++)
            num[i]=0;
        scanf("%d %d",&n,&a);
        while(n--)
        {
            scanf("%d",&temp);
            if(!num[temp])
                num[temp]=1;
        }
        cnt=0;
        i=1;
        while(cnt<a)
        {
            if(!num[i++])
                cnt++;
        }
        while(num[i])
            i++;
        printf("%d\n",i-1);
    }
    return 0;
}
