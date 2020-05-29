#include<stdio.h>

int main()
{
    int a,b,t,h,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);

        h=a>b?a:b;
        l=a<b?a:b;

        if(h>=2*l)
            printf("%d\n",h*h);
        else
            printf("%d\n",4*l*l);
    }
    return 0;
}
