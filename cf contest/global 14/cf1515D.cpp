#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
//accepted

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inp(x)      cin>>x
#define inp1(x,y)   cin>>x>>y
#define inp2(x,y,z) cin>>x>>y>>z
#define pno         cout<<"No\n"     
#define pys         cout<<"Yes\n"      
#define out(x)      cout<<x;
#define outsp(x)    cout<<x<<" "
#define outln(x)    cout<<x<<"\n"
#define out2(x,y)   cout<<x<<" "<<y<<"\n";

#define mx          100005
#define mx2         200005
#define spc         ' '
#define nn          "\n"

#define vcc(x)      vector<x>
#define qq(x)       queue<x>

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e)      for(j=s;j<e;j+=1)
#define bf2(j,s,e)      for(j=s-1;j>=e;j-=1)


typedef struct{
    li x;
    li y;
    // li z;
}mymy;

int cmp(mymy a, mymy b){
    return a.y>b.y;
}

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

map<int, int> mp[2];

void logic(){
    int n,lr[2],i,temp;
    mp[0].clear();
    mp[1].clear();

    inp2(n,lr[0],lr[1]);
    ff(0,lr[0]){
        inp(temp);
        mp[0][temp]++;
    }

    ff(0,lr[1]){
        inp(temp);
        if(mp[0][temp]>0){
            mp[0][temp]--;
            lr[0]--;
            lr[1]--;
            i--;
        }
        else
            mp[1][temp]++;
    }

    int dif = abs(lr[0]-lr[1]);
    if(dif==0){
        outln(lr[0]);
        return;
    }
    int cst = 0;
    int mm = lr[0]>lr[1]?0:1;
    dif/=2;
    for(auto at:mp[mm]){
        if(at.second>1){
            int x = at.second/2;
            x = min(dif,x);
            dif-=x;
            cst+=x;
            lr[mm]-=2*x;
            at.second-=2*x;
        }
        if(dif==0)
            break;
    }
    // outln(cst);
    cst+=lr[mm];

    outln(cst);
}

DN
{
    fast();
    inout();
 
    test()
        logic();

    return 0;
}
