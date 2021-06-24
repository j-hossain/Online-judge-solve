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

#define nn          "\n"
#define spc         ' '
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=1)
#define bf(s,e)         for(i=s;i>e;i-=1)
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
    //fast();
    //inout();

    int t,n,cnt;
    string st;
    
    cin>>t;
    while(t--){
      cin>>n>>st;
      cnt=0;
      for(int i=0;i<n;i++){
        cnt+=(st[i]=='0');
      }
      if(!cnt)
        cout<<"DRAW\n";
      else if(cnt%2==0 || cnt==1)
        cout<<"BOB\n";
      else
        cout<<"ALICE\n";
    }


    return 0;
}
