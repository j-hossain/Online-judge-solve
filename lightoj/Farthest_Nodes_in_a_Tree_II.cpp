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
const ll MM = 30000 + 3;
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

vector<pll> g[MM];
int vis[MM];
ll far[MM];

void precalc(){
    
}

void dfs2(ll u, ll curMx){
    vis[u] = 1;
    ll mx1,mx2;
    mx1 = mx2 = 0LL;
    for(auto [v,w]: g[u]){
        if(vis[v]) continue;
        if(far[v]+w>=mx1){
            mx2 = mx1;
            mx1 = far[v]+w;
        }
        else if(far[v]+w>mx2){
            mx2 = far[v]+w;
        }
    }
    for(auto [v,w]:g[u]){
        if(vis[v]) continue;
        if(far[v]+w==mx1){
            dfs2(v,max(mx2,curMx)+w);
        }
        else{
            dfs2(v,max(mx1,curMx)+w);
        }
    }
    far[u] = max(far[u],curMx);
}

ll dfs(ll u, ll p){
    vis[u] = 1;
    ll mx = 0LL;
    for(auto [v,w]:g[u]){
        if(vis[v]) continue;
        ll ans = dfs(v,u)+w;
        mx = max(mx,ans);
    }
    // cout<<u<<SS<<mx<<NN;
    return far[u] = mx;
}

void answer(){
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        // cout<<u<<SS<<v<<SS<<w<<NN;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(0,-1);
    for(int i=0;i<n;i++) vis[i] = 0;
    dfs2(0,0);
    for(int i=0;i<n;i++){
        cout<<far[i]<<NN;
        g[i].clear();
        vis[i] = 0;
        far[i] = 0;
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
    inout();
    precalc();
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}