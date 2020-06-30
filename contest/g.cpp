#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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


DN
{
    fast();

    int n;
    int ans;
    int tk=0;
    test()
    {
        tk++;
        ans=0;
        cin>>n;
        ans+=(n/403)*(4*47);
        n%=403;
        if(n>=302)
        {
            n-=302;
            ans+=(47*3);
        }
        else if(n>=201)
        {
            n-=201;
            ans+=(47*2);
        }
        else if(n>=101)
        {
            n-=101;
            ans+=47;
        }
        if(n>0)
        {
            ans+=((n/5)*4);
            n%=5;
            if(n!=0)
            {
                if(n<=2)
                    ans+=n;
                else if(n==3)
                    ans+=2;
                else
                    ans+=3;
            }
        }
        cout<<"Case "<<tk<<": "<<ans<<endl;
    }
    return 0;
}
