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

li getIt(li a){
  li ans, i ;
  
  ans=a;
  
  if(ans==1) return 0LL;
  
  for(i=2;i*i<=a;i++){
    if(a%i==0)
      ans-=ans/i;
    while(a%i==0)
      a/=i;
  }
  if(a>1)
    ans-=ans/a;
    
  return ans;
}


DN
{
    fast();
    //inout();
    
    li x;
    while(cin>>x){
      if(!x)
        break;
      
      cout<<getIt(x)<<nn;
    }

    return 0;
}
