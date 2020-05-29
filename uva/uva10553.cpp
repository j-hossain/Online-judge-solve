#include<stdio.h>
#include<math.h>

#define mx 1000005

int prime[mx];
int num[mx];

void seive()
{
    int i,sq,j;
    sq=sqrt(mx);

    prime[1]=1;

    for(i=4;i<mx;i+=2)
        prime[i]=1;

    for(i=3;i<=sq;i+=2)
    {
        if(!prime[i])
        {
            for(j=i*i;j<mx;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}

int primedg(int a)
{
    int sum=0;
    while(a>0)
    {
        sum+=(a%10);
        a/=10;
    }
    if(!prime[sum])
        return 1;
    else
        return 0;
}

void primed()
{
    num[0]=0;
    for(int i=1;i<mx;i++)
    {
        if(!prime[i] && primedg(i))
            num[i]=num[i-1]+1;
        else
            num[i]=num[i-1];
    }
}
int main()
{
    int t,a,b,ans;
    scanf("%d",&t);
    seive();
    primed();
    while(t--)
    {
        scanf("%d %d",&a,&b);
        ans=num[b]-num[a-1];
        printf("%d\n",ans);
    }
    return 0;
}
