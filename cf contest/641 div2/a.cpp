#include<stdio.h>
#include<math.h>
#define li long long int

int main()
{
    li n,k,i,sq,flag;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        while(n%2 && k)
        {
            flag=0;
            sq = sqrt(n);
            for(i=3;i<=sq;i++)
            {
                if(n%i==0)
                {
                    flag=1;
                    n+=i;
                    k--;
                    break;
                }
            }
            if(!flag)
            {
                n*=2;
                k--;
            }

        }
        n+=(k*2);
        printf("%lld\n",n);
    }
    return 0;
}
