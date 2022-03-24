#include<stdio.h>
#include<math.h>

typedef long long int ll;

int main()
{
    ll t,n,i,sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        i=1;
        sum=0;
        while(n/pow(5,i))
        {
            sum+=(n/pow(5,i));
            i++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
