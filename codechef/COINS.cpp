#include<stdio.h>

long long int mx[1000005];

int mxof(long long int a)
{
    long long int x;

    if(a<10)
        return a;
    if(a<1000000)
    {
        if(mx[a])
            return mx[a];

        x=mxof(a/2)+mxof(a/3)+mxof(a/4);
        mx[a]=a>x?a:x;

        return mx[a];
    }
    x=mxof(a/2)+mxof(a/3)+mxof(a/4);
    return a>x?a:x;
}

int main()
{
    long long int n,ans;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",mxof(n));
    }
    return 0;
}
