#include<stdio.h>
int main()
{
    int t,a1,b1;
    int a2,b2;
    scanf("%d",&t);
    while(t--)
    {
        a2=b2=0;
        scanf("%d %d",&a1,&b1);
        while(a1>0)
        {
            a2*=10;
            a2+=(a1%10);
            a1/=10;
        }
        while(b1>0)
        {
            b2*=10;
            b2+=(b1%10);
            b1/=10;
        }
        a1=a2+b2;
        b1=0;
        while(a1>0)
        {
            b1*=10;
            b1+=(a1%10);
            a1/=10;
        }
        printf("%d\n",b1);
    }
    return 0;
}
