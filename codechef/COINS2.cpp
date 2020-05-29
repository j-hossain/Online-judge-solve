#include<bits/stdc++.h>
using namespace std;

long long int calculate(vector<long long int> &dp, long long int n)
{
    if(n<10)
        return n;

    if(n<1000000)
    {
        if(dp[n])
            return dp[n];

        else
        {
            //now, calculate
            long long int x=calculate(dp, n/2)+calculate(dp, n/3)+calculate(dp, n/4);
            dp[n]=max(n,x);

            return dp[n];
        }
    }

    long long int x=calculate(dp, n/2)+calculate(dp, n/3)+calculate(dp, n/4);

    return max(n,x);
}

int main()
{
    long long int n;
    int t;

    vector<long long int> dp(1000000,0);

    while(scanf("%lld",&n)!=EOF)
    {
        cout<<calculate(dp,n)<<endl;;
    }

    return 0;
}
