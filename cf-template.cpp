#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

const ll MD = 1e9+7;

vector<ll> g[30];
ll mem[22][(1<<21)];
ll n, m;

ll getAns(ll u, ll msk){
    if(u==n) return (msk==((1LL<<n)-1));
    if(mem[u][msk]!=-1) return mem[u][msk];
    
    ll ret = 0LL;
    for(auto v: g[u]){
        if(msk&(1LL<<v)) continue;
        ret = (ret+getAns(v,msk|(1LL<<v)))%MD;
    }
    return mem[u][msk] = ret;
}


int main(){
    memset(mem,-1,sizeof(mem));
    cin>>n>>m;
    ll u,v;
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
    }
    cout<<n<<" "<<m<<"\n";
    cout<<getAns(0,1)<<"\n";
    for(int i=0;i<n;i++){
        g[i].clear();
    }
    return 0;
}