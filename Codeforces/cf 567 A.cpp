#include<stdio.h>

int main()
{
    int n,a[100001],i,mx,mn,temp1,temp2;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        temp1=a[i]-a[1];
        temp2=a[n]-a[i];
        mx=(temp1>temp2)?temp1:temp2;

        if(i==1)
            mn=a[i+1]-a[i];
        else if(i==n)
            mn=a[i]-a[i-1];
        else
        {
            temp1=a[i]-a[i-1];
            temp2=a[i+1]-a[i];
            mn=(temp1<temp2)?temp1:temp2;
        }
        printf("%d %d\n",mn,mx);
    }
    return 0;
}
