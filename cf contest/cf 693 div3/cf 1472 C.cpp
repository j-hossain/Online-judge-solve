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

    li n,arr[200005],i,mm;

    test(){
        cin>>n;

        ff(0,n){
            cin>>arr[i];
        }

        bf(n-1,-1){
            if(arr[i]+i<n)
                arr[i]=arr[i]+arr[i+arr[i]];
        }
        mm=0;
        ff(0,n){
            if(mm<arr[i])
                mm=arr[i];
        }

        cout<<mm<<endl;
    }

    return 0;
}
