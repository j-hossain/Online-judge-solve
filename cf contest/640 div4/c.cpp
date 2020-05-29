#include<stdio.h>

int main()
{
    int t,n,k;
    long long int l,h,mid,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        l=1LL;
        h=(long long int)n*k;
        mid=(l+h)/2;
        while(l<h)
        {
            mid=(l+h)/2;
            i=mid-(mid/n);

            if(i<k)
            {
                l=mid;
            }
            else if(i>k)
            {
                h=mid;
            }
            else
                break;
        }

            if(!(mid%n))
            {
                mid--;
            }
        printf("%lld\n",mid);
    }
}
