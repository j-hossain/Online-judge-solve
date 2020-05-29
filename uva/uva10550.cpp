#include<stdio.h>
int main()
{
    int p1,p2,p3,p4,cnt;
    while(scanf("%d %d %d %d",&p1,&p2,&p3,&p4))
    {
        if(p1==0 && p2==0 && p3==0 && p4==0)
            break;
        if(p1<p2)
        {
            cnt=p1+(40-p2);
        }
        else
        {
            cnt=p1-p2;
        }
//        printf("%d\n",cnt);
        if(p2<=p3)
            cnt+=(p3-p2);
        else
            cnt+=((40-p2)+p3);
//        printf("%d\n",cnt);
        if(p3<p4)
        {
            cnt+=(p3+(40-p4));
        }
        else
        {
            cnt+=(p3-p4);
        }
        cnt*=9;
        cnt+=1080;
        printf("%d\n",cnt);
    }
    return 0;
}
