//joshephus problem

#include<stdio.h>

int main()
{
    int i,n;

    while(scanf("%d",&n) && n)
    {
        for(i=0;i<32;i++)
        {
            if(1<<(i+1)>=n)
                break;
        }
        if(n>1)
        {
            n-=(1<<i);
            n*=2;
        }
        printf("%d\n",n);
    }
    return 0;
}
