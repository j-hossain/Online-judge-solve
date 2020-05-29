#include<stdio.h>
int main()
{
    int a,b,t,tk;
    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        tk++;
        scanf("%d %d",&a,&b);
        if((a%2))
            a-=1;
        a=(a)/2;
        b=(b+1)/2;
        printf("Case %d: %d\n",tk,b*b-a*a);
    }
    return 0;
}
