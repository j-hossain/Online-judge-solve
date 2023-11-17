// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

//<shortcut macros>
#define ll long long int
#define dll long double
#define ull unsigned long long int

// most used numbers
const ll MM = 1e6 + 3;
const ll MD = 1e9 + 7;
const double PI = acos(-1.0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// runs test cases
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS " " 
#define NN "\n"
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"

// template declarations simplified
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define All(x) x.begin(), x.end()

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1
//</shortcut macros>

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

vector<ll> g[MM];
ll dis[MM], par[MM][20];

void dfs(ll u, ll p){
    for(auto v:g[u]){
        if(v==p) continue;
        par[v][0] = u;
        dis[v] = dis[u]+1;
        dfs(v,u);
    }
}

ll myLca(ll u, ll v){
    ll dif = dis[u]-dis[v];
    for(int i=0;i<20;i++){
        if((1LL<<i)&dif) u = par[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void precalc(){
    
}

void answer(){
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis[1] = 0;
    par[1][0] = -1;
    dfs(1,-1);
    for(int j=1;j<20;j++){
        for(ll i=0;i<=n;i++){
            par[i][j] = par[i][j-1]==-1?-1:par[par[i][j-1]][j-1];
        }
    }
    while(q--){
        ll u,v;
        cin>>u>>v;
        if(dis[u]<dis[v]) swap(u,v);
        ll lc = myLca(u,v);
        // cerr<<lc<<NN;
        if(lc==v){
            cout<<dis[u]-dis[v]<<NN;
        }
        else{
            cout<<dis[u]+dis[v]-(2*dis[lc])<<NN;
        }
    }
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
    // inout();
    precalc();
    //     for no test case
    answer();

    //     when test cases exist
    // test()
    // {
    //     // cout<<"Case "<<TK<<":"<<NN;
    //     // pcs;
    //     answer();
    // }

    return 0;
}