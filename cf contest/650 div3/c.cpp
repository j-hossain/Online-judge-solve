#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define MM          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


MM
{
    fast();
    inout();

    int n,k,i,j,dis,d,ans,flag,p;
    char inp[200005];
    int pos[200005];

    test()
    {
        cin>>n>>k;
        cin>>inp;
        ans=0;
        dis=2*k+1;

        if(inp[0]=='0')
        {
            flag=1;
            for(i=0;i<=k && i<n;i++)
            {
                if(inp[i]=='1')
                    flag=0;
            }
            if(flag)
            {
                inp[0]='1';
                ans++;
            }

        }
        if(inp[n-1]=='0')
        {
            flag=1;
            for(i=n-1,j=0;j<=k && i>=0;i--,j++)
            {
                if(inp[i]=='1')
                {
                    flag=0;
                }
            }
            if(flag)
            {
                inp[n-1]='1';
                ans++;
            }

        }
        j=0;
        for(i=0;i<n;i++)
        {
            if(inp[i]=='1')
                pos[j++]=i;
        }

        p=0;
        for(i=0;i<n;i++)
        {
            if(pos[p]<=i)
                p++;
            if(inp[i]=='1')
            {
                i+=k;
            }
            else
            {
                if(pos[p]-i-1>=k)
                {
                    ans++;
                    i+=k;
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
