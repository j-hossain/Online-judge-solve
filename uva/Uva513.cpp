#include<stdio.h>
int main()
{
    int h,u,d,f,i;
    double pu,ff,sh;
    while(scanf("%d %d %d %d",&h,&u,&d,&f) && h!=0)
    {
        pu=u;
        ff=u*(f/100.0);
        i=sh=0;
        while(1)
        {
            i++;
            sh+=pu;
            if(pu>0)
                pu-=ff;
            //printf("%lf\n",sh);
            if(sh>h)
                break;
            sh-=d;
            if(sh<0)
                break;
        }
        if(sh>0)
            printf("success on day %d\n",i);
        else
            printf("failure on day %d\n",i);
    }
}
