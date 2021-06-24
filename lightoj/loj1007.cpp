#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define DN          int main()
#define li          unsigned long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define nn          "\n"
#define spc         ' '
#define mx          5000005

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

li phi[mx];

void elttn(){
  phi[0]=0;
  phi[1]=0;
  for(li i=2;i<mx;i++){
    phi[i]=i;
  }
  
  for(li i=2;i<mx;i++){
    if(phi[i]==i){
      for(li j=i;j<=mx;j+=i){
        phi[j]-=(phi[j]/i);
      }
    }
  }
  for(li i=2;i<mx;i++){
    phi[i]=phi[i]*phi[i]+phi[i-1];
  }
}


DN
{
    fast();
    //inout();

    elttn();
    int t,a,b,tk=0;
    cin>>t;
    while(t--){
      tk++;
      cin>>a>>b;
      cout<<"Case "<<tk<<": ";
      cout<<(phi[b]-phi[a-1])<<nn;
    }


    return 0;
}
