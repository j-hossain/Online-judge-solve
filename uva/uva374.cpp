#include<stdio.h>
typedef long long int li;

li b,p,m,ans;

li bigMod(li t)
{
    if(t==0)
        return 1;
    if(!(t%2))
    {
        li an=bigMod(t/2);
        return ((an%m)*(an%m))%m;
    }
    else
    {
        li an=bigMod(t-1);
        return ((b%m)*(an%m))%m;
    }
}

int main()
{

    while(scanf("%lld %lld %lld",&b,&p,&m)!=EOF)
    {
        printf("%lld\n",bigMod(p));
    }
    return 0;
}
