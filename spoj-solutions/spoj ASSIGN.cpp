#include<stdio.h>

#define li long long int
#define mx 1<<20
int arr[21][21],n;
li dp[21][mx];

li dpRun(int now, int taken)
{
    int i;
    li cnt=0LL;

    if(now==n)
        return 1;

    if (dp[now][taken]!=-1)
    {
        return dp[now][taken];
    }

    int flag = 0;

    for(i=0;i<n;i++)
    {
        if(arr[now][i]==1 && !(taken&(1<<i)))
        {
            flag=1;
            cnt+=dpRun(now+1,(taken|(1<<i)));
        }
    }

    if(!flag)
        return 0;
    dp[now][taken]=cnt;
    return cnt;
}

int main()
{
    int t,i,j;
    li ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0LL;
        for(i=0;i<21;i++)
            for(j=0;j<mx;j++)
                dp[i][j]=-1;

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        }

        for(i=0;i<n;i++)
        {
            if(arr[0][i])
            {
                ans+=dpRun(1,1<<i);
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
