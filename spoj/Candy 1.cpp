#include<stdio.h>

int main()
{
    int n,i,mx,arr[10005],sum;

    while(1)
    {

        scanf("%d",&n);
        sum=0;
        if(n==-1)
            break;

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }

        mx = sum/n;
        if(mx*n != sum)
        {
            printf("-1\n");
            continue;
        }

        sum=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]>mx)
                sum+=(arr[i]-mx);
        }

        printf("%d\n",sum);
    }
}
