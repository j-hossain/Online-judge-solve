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
#define mx          1000005

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
  phi[1]=1;
  for(int i=2;i<mx;i++){
    phi[i]=i;
  }
  
  for(int i=2;i<mx;i++){
    if(phi[i]==i){
      for(int j=i;j<=mx;j+=i){
        phi[j]-=(phi[j]/i);
      }
    }
  }
}


DN
{
    //fast();
    //inout();

    elttn();
    int n,t;
    cin>>t;
    while(t--){
      cin>>n;
      cout<<phi[n]<<nn;
    }


    return 0;
}
