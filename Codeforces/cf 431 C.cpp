#include<stdio.h>
#define li long long int
#define md 1000000007

li dp[105][2];
int n,k,d;

li dpRunn(int sum, int flag)
{
    li cnt=0LL;
    if(sum==n)
    {
        if(flag)
           return 1;
        return 0;
    }

    if(sum>n)
    {
        return 0;
    }

    if(dp[sum][flag]!=-2)
    {
        return dp[sum][flag];
    }

    for(int i=1;i<=k;i++)
    {
        if(i>=d || flag)
            cnt+=(dpRunn(sum+i,1)%md);
        else
            cnt+=(dpRunn(sum+i,0)%md);
    }
    dp[sum][flag]=cnt%md;
    return cnt%md;
}

int main()
{
    li ans=0LL;
    int flag=0;
    scanf("%d %d %d",&n,&k,&d);
    for(int i=0;i<105;i++)
        for(int j=0;j<2;j++)
            dp[i][j]=-2;

    for(int i=1;i<=k;i++)
    {
        if(i>=d)
            ans+=(dpRunn(i,1)%md);
        else
            ans+=(dpRunn(i,0)%md);
        ans%=md;
    }
    printf("%lld\n",ans);
    return 0;
}
