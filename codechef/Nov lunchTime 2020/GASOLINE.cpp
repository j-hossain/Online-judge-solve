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

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}
li cap[400005],cost[400005],best[400005],mxCost[200005];

int getMin(int n){
    li mn = 0;
    int mni = -1;

    for(int i=0;i<n;i++){
        if(cap[i]){
            if(mn==0 || cost[i]<mn){
                mn = cost[i];
                mni = i;
            }
        }
    }
    return mni;
}

DN
{
    fast();
    inout();
    li n,i,bi,cc,mnCost;

    test(){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>cap[i];
            cap[i+n] = cap[i];
        }
        for(i=0; i<n; i++){
            cin>>cost[i];
            cost[i+n] = cost[i];
        }

        bi = 0;
        mxCost[0] = 0;

        for(i=1; i<2*n; i++){
            if(cap[bi]==0){
                bi = getMin(i);
            }
            if(bi==-1){
                mxCost[i] = 0;
                mxCost[i-1] = -1;
                bi = i;
                continue;
            }
            mxCost[i] = cost[bi] + mxCost[i-1];
            cap[bi]--;

            if(cost[i]<cost[bi])
                bi = i;
        }
        mnCost = 0;
        for(i=0; i<n; i++){
            if(mxCost[i]!=-1){
                cc = mxCost[i+n]-mxCost[i];
                if(mnCost==0 || mnCost>cc)
                    mnCost = cc;
            }
        }

        cout<<mnCost<<endl;
    }
    return 0;
}
