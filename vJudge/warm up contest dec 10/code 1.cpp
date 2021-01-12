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
    inout();

    li n,m,k,r,c,temp;

    cin>>n>>m>>k;

    if(k<n){
        r=k+1;
        c=1;
        goto print;
    }

    k-=(n-1);
    r = k/(m-1);
    temp = k%(m-1);
    r = n-r+1;
    r-=temp>0;
    temp = temp==0?m-1:temp;
    if(r%2)
        c=m-temp+1;
    else
        c = temp+1;


    print:
        cout<<r<<spc<<c<<nn;

    return 0;
}
