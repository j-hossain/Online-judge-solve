#include<stdio.h>
int main()
{

    long long int a,b,c,d,time,t;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

        time=b;
        a-=b;
        if(a>0)
        {
            if(c>d)
            {
                d=c-d;
                if(a%d!=0)
                    d=(a+(d-(a%d)))/d;
                else
                    d=a/d;
                time+=c*d;
            }
            else
                time=-1;
        }
        printf("%lld\n",time);
    }
    return 0;
}
