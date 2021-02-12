#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//not accepted

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
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();
    
    li n,pp,p[105],mi,sum,msi,ans;
    double pr,mp;
    
    test(){
      cin>>n>>pp;
      sum=0;
      mp=pp;
      mi=-1;
      for(int i=0;i<n;i++){
        cin>>p[i];
        if(i>0){
          pr=((double)p[i]/sum)*100;
        //   cout<<pr<<nn;
          if(pr>mp){
            mp=pr;
            mi=i;
            msi=sum;
          }
          
        }
        sum+=p[i];
      }
      ans=0;
      if(mi!=-1){
        ans=ceil((100.00*p[mi])/pp);
        ans-=msi;
      }
      cout<<ans<<nn;
    }


    return 0;
}
