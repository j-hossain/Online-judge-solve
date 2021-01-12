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

int a[100005];
int b[100005];

DN
{
    fast();
    inout();

    int n,i,j,k,h;

    cin>>n;

    ff(0,n){
        cin>>a[i]>>b[i];
    }


    for(k=0,i=0,j=0;k<n;k++){
        if(a[i]<b[j]){
            a[i++]=-1;
        }
        else
            b[j++]=-1;
    }

    h=n/2;
    h--;

    ff(0,n){
        if(i<=h || a[i]==-1)
            cout<<"1";
        else
            cout<<"0";
    }
    cout<<nn;
    ff(0,n){
        if(i<=h || b[i]==-1)
            cout<<"1";
        else
            cout<<"0";
    }
    cout<<nn;

    return 0;
}
