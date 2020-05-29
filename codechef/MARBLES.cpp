#include<stdio.h>

long long int C (long long int n, long long int r)
{
    long long int res = 1,i;

    if(r > n/2)
        r = n-r;

    for(i = 0; i < r; i++)
    {
        res *=n;
        res /= i+1;
        n--;
    }
    return res;
}

int main()
{
    int n,k,t,i;
    long long int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        n-=k;
        ans=1;
        if(n>0)
            ans=C(n+k-1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
