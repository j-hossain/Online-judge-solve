#include<stdio.h>
#include<math.h>

#define mx 1000008

int mem[mx];

void seive()
{
    int i,j,x;
    int sq=sqrt(mx);
    mem[1]=0;
    mem[2]=1;
    for(i=2;i<=sq;i++)
    {
        for(j=i*i,x=2;j<mx;j+=i)
            mem[j]+=x++;
    }
}

int main()
{
    seive();

    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",n-mem[n]);
    }
    return 0;
}

