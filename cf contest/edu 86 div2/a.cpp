#include<stdio.h>

int main()
{
    long long int a,b,x,y,t,mn,ans;
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;

        scanf("%lld %lld",&x,&y);
        scanf("%lld %lld",&a,&b);

        if(2*a>b)
        {
            mn=x<y?x:y;
            ans+=(mn*b);
            x-=mn;
            y-=mn;
            if(x||y)
            {
                mn=x>y?x:y;
                ans+=(mn*a);
            }
        }
        else
        {
            mn=x+y;
                //printf("%d\n",mn);
            ans+=(mn*a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
