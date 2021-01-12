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

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}


li n,x,arr[mx],mapi[mx],ans,i,test;

DN
{
    fast();
    inout();

    cin>>n>>x;
    ff(0,n){
        cin>>arr[i];
    }
    ans=0LL;
    bf(n-1,-1){
        test = arr[i]^x;
        if(test>mx)
            continue;
        ans += mapi[test];
        mapi[arr[i]]++;
    }

    cout<<ans<<nn;

    return 0;
}
