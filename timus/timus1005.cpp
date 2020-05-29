#include<stdio.h>

int dif(int a,int b)
{
    return a>b?(a-b):(b-a);
}

int main()
{
    int n,i,arr[28],sum,tsum,ans;
    sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

    int m,mem[(1<<n)+10];
    ans=sum;
    mem[0]=0;

    for(i=0;i<n;i++)
    {
        for(m=1<<i;m<(1<<(i+1));m++)
        {
            mem[m]=mem[m^(1<<i)]+arr[i];
            tsum=dif(sum,mem[m]*2);
            if(tsum<ans)
                ans=tsum;
        }

    }

    printf("%d\n",ans);
    return 0;
}
