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

mymy cd[200005];
map<li,vcc(li)>mp;
li ans[200005];
vcc(li)temp;

void logic(){
    
    li i,j,n,u,s,sz,msz;
    inp(n);
    ff(0,n){
        inp(cd[i].x);
    }
    ff(0,n){
        inp(cd[i].y);
    }

    sort(cd,cd+n,cmp);

    ff(0,n){
        ans[i+1]=0LL;
        u=cd[i].x;
        s=cd[i].y;
        mp[u].push_back(s);
        sz = mp[u].size();
        if(sz>1){
            mp[u][sz-1]+=mp[u][sz-2];
        }
    }
    // for(auto mm:mp){
    //     outln(mm.first);
    //     ff(0,mm.second.size())
    //         outsp(mm.second[i]);
    //     outln("");
    // }

    for(auto at:mp){
        sz = at.second.size();
        ff(1,sz+1){
            j=sz/i;
            j*=i;
            j--;
            ans[i]+=at.second[j];
        }
    }

    ff(1,n+1)
        outsp(ans[i]);

    outln("");
    mp.clear();
}

DN
{
    // fast();
    inout();
 
    test()
        logic();

    return 0;
}
