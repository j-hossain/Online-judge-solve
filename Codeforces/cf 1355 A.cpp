#include<stdio.h>

int main()
{
    long long int n,k,t,temp,ttemp,mn,mx;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        k--;
        while(k--)
        {
            temp=n;
            mn=mx=-1;

            while(temp)
            {
                ttemp=temp%10;
                if(ttemp<mn || mn==-1)
                    mn=ttemp;

                if(ttemp>mx)
                    mx=ttemp;
                temp/=10;
            }

            if(mn==0 || mx==0)
                break;

            else
                n+=(mn*mx);
        }
        printf("%lld\n",n);
    }
    return 0;
}
