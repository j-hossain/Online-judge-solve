#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
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
    inout();

    li w,h,n,a,b;

    test(){
        cin>>w>>h>>n;
        a=1;
        while(a<n && w>0){
            if(w%2)
                break;
            w/=2;
            a*=2;
        }
        b=1;
        while(b*a<n && h>0){
            if(h%2)
                break;
            h/=2;
            b*=2;
        }

        if(a*b>=n)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}
