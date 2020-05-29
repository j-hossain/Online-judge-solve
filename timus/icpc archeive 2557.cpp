#include<stdio.h>
int main()
{
    int arr[101],i,j,n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            arr[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j+=i)
                arr[j]=arr[j]^1;
        }
        j=0;
        for(i=1;i<=n;i++)
        {
            if(arr[i])
                j++;
        }
        printf("%d\n",j);
    }
    return 0;
}
