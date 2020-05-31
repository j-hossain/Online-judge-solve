//not accepted

#include<stdio.h>
double dif(double a, long long int b)
{
    return a>b?(a-b):(b-a);
}

int main()
{
    long long int r,l,m,x,y,ans,te;
    int tk,t,h,c;
    double temp,mn,now;

    scanf("%d",&tk);
    while(tk--)
    {
        scanf("%d %d %d",&h,&c,&t);

        if(h==t)
        {
            printf("1\n");
            continue;
        }
        mn=h-t;
        l=0;
        r=100000000;
        ans=1;
        while(l<r)
        {
            m=(l+r)/2;
            x=m+1;
            y=m;

            now = (double)(h*x+c*y)/((double)x+y);

            if(now<t)
            {
                if(t-now<=mn)
                {
                    mn=t-now;
                    ans=x+y;
                }
                r=m-1;
            }
            else
            {
                if(now-t<mn)
                {
                    mn=now-t;
                    ans=x+y;
                }
                l=m+1;
            }
        }

        temp = (h+c)/2.0;
        if(dif(temp,t)<mn)
            ans=2;

        printf("%lld\n",ans);
    }
}











