#include<stdio.h>
int main()
{
    int n,i,mx,arr[10001],sum,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mx=0;
    for(i=0;i<n;i++)
    {
        sum=1;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<=arr[j-1])
                sum++;
            else
                break;
        }
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]<=arr[j+1])
                sum++;
            else
                break;
        }
        if(sum>mx)
            mx=sum;
    }
    printf("%d\n",mx);
    return 0;
}
