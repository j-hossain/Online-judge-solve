#include<stdio.h>
#include<math.h>

#define pi 3.14159265358

int main()
{
    double a,b,c;
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n*=2;
        a=pi/n;
        b=sin(a);
        c=cos(pi/(2*n));
        printf("%f\n",c/b);
    }
    return 0;
}
