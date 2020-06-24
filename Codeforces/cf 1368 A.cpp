#include<stdio.h>

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main()
{
    inout();
    int a,b,n,t,i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&n);
        i=0;
        while(a<=n && b<=n)
        {
            if(a>b)
            {
                a=a+b;
                b=a-b;
                a=a-b;
            }
            i++;
            a+=b;
        }

        printf("%d\n",i);
    }
}
