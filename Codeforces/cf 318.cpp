#include<stdio.h>
int main()
{
    long long int n,k,d;
    scanf("%lld %lld",&n,&k);
    d=n/2+(n%2);
    if(k>d)
    {
        k-=d;
        printf("%lld\n",2*k);
        return 0;
    }
    printf("%lld\n",2*k-1);
    return 0;
}
