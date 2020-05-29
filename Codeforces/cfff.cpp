#include<stdio.h>
int main()
{
    int n,t,i,cnt,rt;
    scanf("%d %d",&n,&t);
    rt=240-t;
    i=1;
    cnt=0;
    while((i<=n) && (rt>=(i*5)))
    {
        rt-=(i*5);
        i++;
        cnt++;
    }
    printf("%d\n",cnt);
}
