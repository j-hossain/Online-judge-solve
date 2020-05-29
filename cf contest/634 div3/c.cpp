#include<stdio.h>
#include<string.h>

int main()
{
    long long int arr[200010],i,n,mx1,mx2,num,mx;
    long long int tk;
    scanf("%lld",&tk);
    while(tk--)
    {
        mx1=0;

        scanf("%lld",&n);
        memset(arr,0,sizeof(arr));
        mx=n;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&num);
            if(!arr[num])
            {
                mx1++;
            }
            arr[num]++;
        }
        mx2=0;
        for(i=0;i<=n;i++)
        {
            if(arr[i]>mx2)
                mx2=arr[i];
        }
        //printf("%d %d\n",mx1,mx2);
        if(mx1>mx2)
        {
            printf("%lld\n",mx2);
        }
        else if(mx1<mx2)
        {
            printf("%lld\n",mx1);
        }
        else if(mx1==mx2)
            printf("%lld\n",mx1-1);
    }
    return 0;
}
