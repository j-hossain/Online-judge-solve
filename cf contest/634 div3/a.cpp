#include<stdio.h>
int main()
{
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n%2)
        {
            n-=1;
            n/=2;
        }
        else
        {
            n/=2;
            n-=1;
        }
        printf("%lld\n",n);
    }
    return 0;
}
