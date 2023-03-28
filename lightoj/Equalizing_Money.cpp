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
const ll MM = 1e3 + 3;
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

ll mon[MM];
vector<ll> g[MM];
ll siz;
int vis[MM];

ll dfs(ll u){
    vis[u] = 1;
    ll ret = mon[u];
    for(auto v:g[u]){
        if(vis[v]) continue;
        ret+=dfs(v);
    }
    siz++;
    return ret;
}

void precalc(){
    
}

void answer(){
    ll n,m;
    cin>>n>>m;
    ll tot = 0LL;
    for(int i=1;i<=n;i++){
        cin>>mon[i];
        tot+=mon[i];
        vis[i] = 0;
        g[i].clear();
    }
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(tot%n){
        cout<<"No\n";
        return;
    }
    ll need = tot/n;
    int f=1;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        siz = 0LL;
        ll sum = dfs(i);
        // cout<<i<<SS<<sum<<SS<<siz<<NN;
        if(sum%siz) f=0;
        else if(sum/siz!=need) f=0;
    }
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
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
        // cout<<"Case "<<TK<<":"<<NN;
        pcs;
        answer();
    }

    return 0;
}