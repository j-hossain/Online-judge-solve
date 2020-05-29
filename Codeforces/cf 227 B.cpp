#include<stdio.h>
int main()
{
    long long int n,m,i,pos[100001],sum,num;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        pos[num]=i;
    }
    scanf("%lld",&m);
    sum=0;
    for(i=0;i<m;i++)
    {
        scanf("%lld",&num);
        sum+=pos[num];
    }
    printf("%lld ",sum);
    sum=m*(n+1)-sum;
    printf("%lld\n",sum);
    return 0;
}
