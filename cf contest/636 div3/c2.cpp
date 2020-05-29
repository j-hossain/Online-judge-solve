
#include<stdio.h>

int main()
{
    int t,i,n,arr,mx1,mx2;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        mx1=mx2=sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr);
            if(arr>0)
            {
                if(mx1==0)
                    mx1=arr;
                else if(arr>mx1)
                    mx1=arr;
                if(mx2!=0)
                {
                    sum+=mx2;
                    mx2=0;
                }
            }
            if(arr<0)
            {
                if(mx2==0)
                    mx2=arr;
                else if(arr>mx2)
                    mx2=arr;
                if(mx1!=0)
                {
                    sum+=mx1;
                    mx1=0;
                }
            }
        }
        sum+=(mx1+mx2);
        printf("%lld\n",sum);
    }
    return 0;
}
