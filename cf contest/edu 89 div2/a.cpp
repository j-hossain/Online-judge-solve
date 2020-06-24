#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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
    //inout();

    int a,b,ans,mmx,mn;
    test()
    {
        cin>>a>>b;
        mmx=a>b?a:b;
        mn=a<b?a:b;
        if(mn>=mmx/2)
            ans=(mmx+mn)/3;
        else
            ans=mn;

        cout<<ans<<endl;
    }


    return 0;
}
