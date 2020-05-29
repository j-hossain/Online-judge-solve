#include<stdio.h>
int main()
{
    int arr[200005],peak[200005];
    int n,k,i,t,total,mx,index;
    scanf("%d",&t);
    while(t--)
    {
        mx=0;
        index=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            peak[i]=0;
        scanf("%d",&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        peak[0]=peak[n-1]=0;
        for(i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                peak[i]=peak[i-1]+1;
            else
                peak[i]=peak[i-1];
        }

        for(i=0;i<=n-k;i++)
        {
            total=peak[i+k-2]-peak[i];
            if(total>mx)
            {
                mx=total;
                index=i;
            }
        }
        printf("%d %d\n",mx+1,index+1);
    }
}
