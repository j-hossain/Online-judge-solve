#include<stdio.h>

#define li long long int
li arr[6];

li gcd(li a,li b)
{
    if(!(b%a))
        return a;
    return gcd(b%a,a);
}

li lcm(li a, li b)
{
    return (a*b)/gcd(a,b);
}

li divisable(li a)
{
    li i,lc,tempCnt,mask,temp;
    li cnt=0;
    for(mask=1; mask<(1<<5); mask++)
    {
        lc=1;
        for(i=0; i<5; i++)
        {
            if(mask&(1<<i))
            {
                lc=lcm(lc,arr[i]);
            }
        }
        tempCnt= __builtin_popcount(mask);
        temp=a/lc;

        if(tempCnt%2)
            cnt+=temp;
        else
            cnt-=temp;
    }
    return cnt;
}
int main()
{
    li a,b,n,m,t,i;
    li cnt,cnt2;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&m,&n,&a,&b);
        cnt2=0;
        arr[0]=a;
        if(n%arr[0]==0)
            cnt2++;
        for(i=1; i<5; i++)
        {
            arr[i]=arr[i-1]+b;
            if(n%arr[i]==0)
                cnt2++;
        }
        cnt=(n-divisable(n))-(m-divisable(m-1));

        if(cnt2!=5)
            cnt++;

        printf("%lld\n",cnt);
    }
    return 0;
}
