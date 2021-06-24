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
    li t,tk,n,i,sq,x,y;
    vector<li> va,vb;
    
    cin>>t;
    for(tk=1;tk<=t;tk++){
      cin>>x>>y;
      n=x-y;
      sq=sqrt(n);
      
      for(i=1;i<=sq;i++){
        if(n%i==0){
          x=n/i;
          
          if(x!=i){
            if(x>y){
              vb.push_back(x);
            }
          }
          if(i>y)
            va.push_back(i);
        }
      }
      cout<<"Case "<<tk<<": ";
      if(va.empty() and vb.empty()){
        cout<<"impossible\n";
      }
      else{
        for(i=0;i<va.size();i++){
          if(i==va.size()-1){
            cout<<va[i];
            if(!vb.empty())
              cout<<" ";
            
            break;
          }
          cout<<va[i]<<" ";
        }
        for(i=vb.size()-1;i>=0;i--){
          if(i==0){
            cout<<vb[i];
            break;
          }
          cout<<vb[i]<<" ";
        }
        cout<<nn;
      }
      va.clear();
      vb.clear();
    }


    return 0;
}
