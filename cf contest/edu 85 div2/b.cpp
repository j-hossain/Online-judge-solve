#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,s,i,t,arr[100001],smll[100001],j;
    long long int extra,cnt;
    scanf("%lld",&t);
    while(t--)
    {
        extra=cnt=0;

        scanf("%lld %lld",&n,&s);
        for(i=0,j=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i]>=s)
            {
                extra+=(arr[i]-s);
                arr[i]=s;
            }
            else
            {
                smll[j++]=arr[i];
            }
        }

        cnt=n-j;
        n=j;
        //printf("%d\n",cnt);

        sort(smll,smll+n);

        for(i=n-1;i>=0 && extra>0;i--)
        {
                if(smll[i]+extra>=s)
                {
                    extra-=(s-smll[i]);
                    cnt++;
                }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
