#include<stdio.h>
int main()
{
    int t,n,i,j,sum1,sum2,arr[1005],cnt,m,s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        cnt=j=n;
        i=1;
        m=1;
        sum1=sum2=s1=s2=0;
        while(cnt>0 && i<=j)
        {
            if(m%2)
            {
                sum1=0;
                while(sum1<=sum2 && i<=j)
                {
                    sum1+=arr[i];
                    i++;
                    cnt--;
                }
                s1+=sum1;
            }
            else
            {
                sum2=0;
                while(sum2<=sum1 && i<=j)
                {
                    sum2+=arr[j];
                    j--;
                    cnt--;
                }
                s2+=sum2;
            }
            m++;
        }
        printf("%d %d %d\n",m-1,s1,s2);
    }
}
