#include<stdio.h>

int main()
{
    int r,l,h,c,m,x,y,t,i,tk;
    double temp,mx,mn,now;

    scanf("%d",&tk);
    while(tk--)
    {
        scanf("%d %d %d",&h,&c,&t);

        if(h==t)
        {
            printf("1\n");
            continue;
        }

        now=mn=mx=(h+c)/2;
        i=2;
        r=h+c;
        while(mn<=now)
        {
            if(mx==t)
                break;
            if(i%2)
                x=c;
            else
                x=h;
            r+=x;
            i++;
            now=r/i;
            if(now>mx && now<=t)
                mx=now;
        }

        printf("%f %f\n",mn,now);
        printf("%d\n",i-1);
    }
}
