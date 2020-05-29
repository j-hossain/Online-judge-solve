#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> dp;

int main()
{
    long int n,k,t,i,j;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&k);
        fill (dp.begin(),dp.begin()+n,0);
        dp[0]=1;
        for(j=1;j<=k;j+=2)
        {
            for(i=n;i>=1;i--)
            {
                if(i>j && dp[i-j])
                    dp[i]=1;
            }
        }
        printf("%d\n",dp[n]);
    }
}
