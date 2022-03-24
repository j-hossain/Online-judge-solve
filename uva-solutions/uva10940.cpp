#include<stdio.h>
int main()
{
    long long int top,bottom,n;
    while(scanf("%lld",&n) && n)
    {
        if(n%2)
        {
            top=4;
            bottom=n-1;
            n=(n/2)-1;
        }
        else
        {
            top=2;
            bottom=n;
            n/=2;
        }
        printf("%lld %lld\n",top,bottom);
        while(n>=2)
        {
            bottom-=top;
            printf("%lld %lld %lld\n",top,bottom,n);
            if(n%2)
            {
                n=(n/2)-1;
                top+=top;
            }
            else
                n=n/2;
            top+=top;
            printf("%lld %lld %lld\n",top,bottom,n);
        }
    }
}
