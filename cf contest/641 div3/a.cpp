#include<stdio.h>
#define li long long int

int main()
{
    li n,m,t,ans,temp,pr;

    scanf("%lld",&t);
    while(t--)
    {
        ans=0LL;

        scanf("%lld %lld",&n,&m);

        if(n==1)
            printf("0\n");
        else if(n==2)
            printf("%lld\n",m);
        else
            printf("%lld\n",m*2);
    }
    return 0;
}
