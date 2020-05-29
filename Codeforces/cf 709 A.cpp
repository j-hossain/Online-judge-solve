#include<stdio.h>
int main()
{
    long long int a,n,b,d,i,sum,cnt;
    scanf("%lld %lld %lld",&n,&b,&d);
    sum=0;
    cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a);
        if(a<=b)
            sum+=a;
        if(sum>d)
        {
            sum=0;
            cnt++;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}
