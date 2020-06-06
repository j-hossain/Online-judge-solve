#include<stdio.h>

int main()
{
    int a,b,c,d;
    long long int ans,rem,cnt,x,y,z,i,j,l,r;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    y=(long long int)b;
    z=(long long int)c;
    ans=0LL;
    while(z<=d)
    {
        x=z-y+1;
        while(b<x && y<=c)
        {
            y++;
            x=z-y+1;
        }
        if(y>c)
            break;
        if(x<a)
            x=a;

        cnt=x-a;
        l=b-x+1;

        if(y+cnt<=c)
        {
            r=l+cnt;
            rem=c-y-cnt;
            cnt=b-a+1;
            ans+=(long long int)(cnt*rem);
        }
        else
            r=c-y+l;

        ans+=(long long int)((r*(r+1))/2-(l*(l-1))/2);
        z++;
    }

    printf("%lld\n",ans);
    return 0;
}
