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

li getIt(li n){
  li r, l, mid, x;
  //cout<<n<<nn;
  l=1;
  r=100000000;
  
  while(l<r-1){
    //cout<<l<<spc<<r<<nn;
    mid=(l+r)/2;
    x=mid*mid;
    if(x==n){
      l=mid;
      break;
    }
    if(x<n){
      l=mid;
    }
    else {
      r=mid;
    }
  }
  
  return l;
}

DN
{
    //fast();
    //inout();

    li t,tk,n,ans,num,dis,r,c;
    
    cin>>t;
    for(tk=1;tk<=t;tk++){
      //cout<<"hello\n";
      cin>>n;
      ans = getIt(n);
      if(ans*ans==n)
        ans--;
      num=2*ans+1;
      dis=n-ans*ans;
      
      if(dis<=(num+1)/2){
        r=ans+1;
        c=dis;
      }
      else{
        c=ans+1;
        r=num-dis+1;
      }
      if((ans+1)%2){
        swap(r,c);
      }
      cout<<"Case "<<tk<<": ";
      cout<<c<<spc<<r<<nn;
    }

    return 0;
}
