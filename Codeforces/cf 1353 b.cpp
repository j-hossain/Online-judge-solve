#include<stdio.h>
int main()
{
    int arr[35],brr[35],n,k,sum,j,i,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
            scanf("%d",&brr[i]);

        for(i=0;i<n-1;i++)
        {
            for(j=i;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    arr[i]=arr[i]+arr[j];
                    arr[j]=arr[i]-arr[j];
                    arr[i]=arr[i]-arr[j];
                }
            }
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i;j<n;j++)
            {
                if(brr[i]<brr[j])
                {
                    brr[i]=brr[i]+brr[j];
                    brr[j]=brr[i]-brr[j];
                    brr[i]=brr[i]-brr[j];
                }
            }
        }

        for(i=0;i<k;i++)
        {
            if(arr[i]<brr[i])
                arr[i]=brr[i];
            else
                break;
        }
        sum=0;
        for(i=0;i<n;i++)
            sum+=arr[i];
        printf("%d\n",sum);
    }
    return 0;
}
