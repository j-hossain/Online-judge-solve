#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
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
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

struct edge{
    int i;
    int j;
};


DN
{
    fast();
    //inout();
    queue<int> sq;
    int n,i,arr[5005],u,v,vis[5005];
    struct edge ed[5005];
    test(){
        while(!sq.empty())
            sq.pop();
        cin>>n;
        for(i=0; i<n; i++){
            vis[i] = 0;
            cin>>arr[i];
        }
        int k = 0;
        sq.push(0);
        while(!sq.empty()){
            i = sq.front();
            sq.pop();
            vis[i] = 1;
            for(int j=0; j<n; j++){
                if(!vis[j] && arr[i]!=arr[j]){
                    ed[k].i = i+1;
                    ed[k++].j = j+1;
                    sq.push(j);
                    vis[j] = 1;
                }
            }
        }
        int flag = 0;
        for(i=0; i<n; i++){
            if(!vis[i]){
                flag = 1;
            }
        }

        if(flag){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i=0;i<k;i++){
            cout<<ed[i].i<<" "<<ed[i].j<<"\n";
        }
    }

    return 0;
}
