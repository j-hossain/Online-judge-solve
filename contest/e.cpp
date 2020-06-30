#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int digCnt(int a)
{
    int cnt=0;
    while(a>0)
    {
        a/=10;
        cnt++;
    }
    return cnt;
}

DN
{
    fast();

    char inp[1005];
    int num,ans,i,sum,len,d;
    int tk=0;

    test()
    {
        tk++;
        cin>>inp;
        len = strlen(inp);
        sum=0;
        for(i=0;i<len;i++)
                sum+=(inp[i]-'0');

        d=digCnt(sum);

        while(d>1)
        {
            num=sum;
            sum=0;
            while(num>0)
            {
                sum+=(num%10);
                num/=10;
            }
            d=digCnt(sum);
        }

        if(sum==9)
            cout<<"Case "<<tk<<": "<<"YES\n";
        else
            cout<<"Case "<<tk<<": "<<"NO\n";
    }

    return 0;
}
