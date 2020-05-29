#include<stdio.h>
#include<math.h>

int main()
{
    long long int n,i,j,low,high,temp;
    long long int sum1,sum2,cnt;
    scanf("%lld",&n);
    low=pow(10,n/2);
    high=pow(10,n);
    printf("%lld %lld\n",low,high);
    cnt=1;
    for(i=low;i<=high;i++)
    {
        j=1;
        temp=i;
        sum1=sum2=0;
        while(j<=n/2)
        {
            sum1+=(temp%10);
            temp/=10;
            j++;
        }
        while(temp)
        {
            sum2+=(temp%10);
            temp/=10;
            j++;
        }
        if(sum1==sum2)
        {
            cnt++;
            //printf("%lld\n",i);
        }

    }
    printf("%lld\n",cnt);
}
