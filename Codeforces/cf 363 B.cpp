#include<stdio.h>
int main()
{
    int arr[150005],i,n,k,a,index;
    long long int sum,mn;
    scanf("%d %d",&n,&k);
    arr[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        arr[i]=arr[i-1]+a;
    }
    mn=arr[k]-arr[0];
    index=1;
    for(i=k+1;i<=n;i++)
    {
        sum=arr[i]-arr[i-k];
        if(sum<mn)
        {
            index=i-k+1;
            mn=sum;
        }
    }
    printf("%d\n",index);
    return 0;
}
