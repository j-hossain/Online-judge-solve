#include<stdio.h>
#define li long long int

int main()
{
    li n,sum,i,j,t;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld",&n);
        for(i=3,j=1;i<=n;i+=2,j++)
        {
            sum+=((2*j*i)+(2*j*(i-2)));
        }

        printf("%lld\n",sum);
    }
    return 0;
}
