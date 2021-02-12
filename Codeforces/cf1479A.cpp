#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//accepted

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

// void inline inout()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
//     freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
//     #endif
// }


DN
{
    //fast();
    //inout();

    int n,k,ans,m;
    test(){
      cin>>n>>k;
      if(n>k){
        m=n/k;
        if(n%k!=0){
          m++;
        }
        k*=m;
      }
      ans=k/n;
      if(k%n!=0){
        ans++;
      }
      cout<<ans<<nn;
    }


    return 0;
}
