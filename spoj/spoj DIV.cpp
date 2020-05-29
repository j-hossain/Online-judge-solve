#include<stdio.h>
#include<math.h>

#define mx 1000008

int mem[mx];
int prime[mx];
int sz;

void seive()
{
    int i,j;
    mem[1]=1;
    for(i=2;i<mx;i++)
        mem[i]=2;
    int sq=sqrt(mx);
    for(i=2;i<mx;i++)
    {
        for(j=2*i;j<mx;j+=i)
            mem[j]++;
    }

    sz=0;
    for(i=1;i<mx;i++)
    {
        if(mem[i]==2)
            prime[sz++]=i;
    }
}

int main()
{
    seive();

    int n,i,sq,x,y,j;
    n=0;
    for(i=4;i<1000000;i++)
    {
        x=mem[i];
        sq=sqrt(x);
        for(j=0;prime[j]<=sq && x!=2;j++)
        {
            y=prime[j];
            if(x%y==0 && mem[x/y]==2 && x/y!=y)
            {
                n++;
                if(n%9==0)
                    printf("%d\n",i);
                break;
            }
        }
    }

}
