#include<stdio.h>

int main()
{
    int k,arr[105],mid,m,ans;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
            if(arr[i]>arr[j])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
    }
    mid=k/2+1;
    ans=0;
    for(int i=1;i<=mid;i++)
    {
        ans+=(arr[i]/2+1);
    }
    printf("%d\n",ans);
    return 0;
}
