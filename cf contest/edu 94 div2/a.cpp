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
//    inout();

    char st[105];
    int i,n;

    test(){
        cin>>n;
        cin>>st;
        for(i=0;i<2*n-1;i+=2){
            cout<<st[i];
        }
        cout<<endl;
    }


    return 0;
}
