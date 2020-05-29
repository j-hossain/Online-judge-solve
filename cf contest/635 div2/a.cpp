#include<stdio.h>
int main()
{
    long long int a,b,c,d,s1,s2,t;
    scanf("%lld",&t);
    while(t--)
    {

    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    if(b+c>=d)
    {
        printf("%lld %lld %lld\n",b,c,d);
    }
    else if(2*b>=c)
    {
        printf("%lld %lld %lld\n",b,b,c);
    }
    else if(b+c>=c)
        printf("%lld %lld %lld\n",b,c,c);

    }
    return 0;
}
