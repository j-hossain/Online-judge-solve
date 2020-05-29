#include<stdio.h>
int main()
{
    long long int t,n,temp,digit,cnt,divisor;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        temp=n;
        digit=0;
        while(temp)
        {
            temp/=10;
            digit++;
        }
        temp=digit;
        divisor=0;
        while(temp--)
        {
            divisor=divisor*10+1;
        }
        cnt=n/divisor+9*(digit-1);
        printf("%lld\n",cnt);
    }
    return 0;
}
