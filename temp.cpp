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


DN
{
    fast();
    //inout();

    int n,m,a,b,sa,sb,ma,mb,ans,i;

    test(){
        cin>>n;
        ma=sa=0;
        ff(0,n){
            cin>>a;
            sa+=a;
            if(sa>ma)
                ma=sa;
        }
        cin>>m;
        mb=sb=0;
        ff(0,m){
            cin>>b;
            sb+=b;
            if(sb>mb)
                mb=sb;
        }

        cout<<(ma+mb)<<nn;
    }

    return 0;
}
