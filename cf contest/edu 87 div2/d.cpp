#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    long long tc;
    scanf("%lld",&tc);
    while(tc--)
    {
        long long a,b,c,d,x,y,z;
        int m;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(b>=a)
        {
            printf("%lld\n",b);
            continue;
        }
        else
        {
            if(c<d)
            {
                printf("-1\n");
                continue;
            }
            else
            {
                x=a-b;
                y=c-d;
                if(x%y==0)
                {
                    m=x/y;
                }
                else
                {
                    m=(x/y)+1;
                }
                z=b+c*m;
                printf("%lld\n",z);
            }
        }
    }
   return 0;
}
