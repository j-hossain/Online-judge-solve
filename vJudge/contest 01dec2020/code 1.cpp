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

    li n,x,i,taken,amount;
    string ch;
    li mapi[26];
    ff(0,26)
        mapi[i]=0;
    cin>>n>>x;
    cin>>ch;
    ff(0,n){
        mapi[ch[i]-'A']++;
    }
    sort(mapi,mapi+26);

    taken = 0;
    amount = 0;
    bf(25,-1){
        if(taken==x)
            break;
        if(taken+mapi[i]<=x){
            taken+=mapi[i];
            amount += mapi[i]*mapi[i];
        }
        else{
            amount += (x-taken)*(x-taken);
            taken = x;
        }
    }

    cout<<amount<<nn;
    return 0;
}
