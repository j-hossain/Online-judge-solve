#include<stdio.h>
#include<math.h>

#define mx 100000008

int mark[mx];
int mem[mx];

double dif(double x, double a)
{
    if(x>a)
        return x-a;
    return a-x;
}

void seive()
{
    int i,j;

    mark[0]=mark[1]=1;

    for(i=4;i<mx;i+=2)
        mark[i]=1;

    int sq=sqrt(mx);
    for(i=3;i<=sq;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<mx;j+=(i*2))
                mark[j]=1;
        }
    }
    mem[2]=1;
    for(i=3;i<mx;i++)
    {
        mem[i]=mem[i-1];
        if(!mark[i])
            mem[i]++;
    }
}

int main()
{
    int n;
    double ans,x,y;
    seive();
    while(scanf("%d",&n) && n)
    {
        x=mem[n];
        //printf("%f\n",mark[n]);
        y=double(n)/log(double(n));
        y=dif(x,y);
        ans=(y/x)*100;

        printf("%0.1f\n",ans);
    }
    return 0;
}
