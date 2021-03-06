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
    li z;
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

mymy blk[mx];

void logic(){
    li i,j,n,m,x,ans[mx],ms[mx];
    cin>>n>>m>>x;
    ff(0,n){
        inp(blk[i].y);
        blk[i].x=i;
        ms[i+1]=0LL;
    }

    sort(blk,blk+n,cmp);

    i=0;
    while(i<n){
        j=0;
        while(j<m && i+j<n){
            blk[i+j].z=j+1;
            ms[j+1]+= blk[i+j].y;
            j++;
        }
        i+=j;

    }
    int flag=1;
    ff(2,m){
        if(abs(ms[i]-ms[i-1])>x || abs(ms[i]-ms[i+1])>x){
            flag=0;
            break;
        }
    }

    if(!flag){
        pno;
        return;
    }
    else{
        pys;
        ff(0,n){
            ans[blk[i].x] = blk[i].z;
        }
        ff(0,n)
            outsp(ans[i]);
        outln("");
    }

}

DN
{
    fast();
    inout();
 
    test()
        logic();

    return 0;
}
