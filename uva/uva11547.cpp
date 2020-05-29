#include<stdio.h>

int main()
{
    long long int a,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&a);
        a*=567;
        a/=9;
        a+=7492;
        a*=235;
        a/=47;
        a-=498;
        a/=10;
        a%=10;
        if(a<0)
            a=-a;
        printf("%lld\n",a);
    }
    return 0;
}
