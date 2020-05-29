#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,temp,i;
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=4;i<1000000000;i*=2)
        {
            temp=i-1;
            if(n%temp==0)
                break;

        }
        printf("%d\n",n/temp);
    }
    return 0;
}
