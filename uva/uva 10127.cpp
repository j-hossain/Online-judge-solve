#include<stdio.h>

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main()
{
    inout();
    long long int n,i,cnt,j;
    char num[100005];
    while(scanf("%lld",&n)!=EOF)
    {
        i=1;
        cnt=1;
        while(i%n!=0)
        {
            i%=n;
            i*=10;
            i++;
            cnt++;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
