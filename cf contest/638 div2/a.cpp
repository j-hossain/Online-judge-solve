#include<stdio.h>

long long int dif(long long int a,long long int b)
{
    return a<b?(b-a):(a-b);
}

int main()
{
    int t,i,n;
    long long int sum1,sum2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum1=sum2=0;
        sum1=1<<n;
        for(i=1;i<n/2;i++)
            sum1+=(1<<i);
        for(i=n/2;i<n;i++)
            sum2+=(1<<i);
        printf("%lld\n",dif(sum1,sum2));
    }
    return 0;
}
