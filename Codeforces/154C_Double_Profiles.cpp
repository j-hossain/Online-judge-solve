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

const ll b = 29;
const ll b2 = 31;
const ll MD2 = 1e9+9;
pll g[MM];
ll pw[MM],pw2[MM];

void add(ll u, ll v){
    g[u].first = (g[u].first+pw[v])%MD;
    g[u].second = (g[u].second+pw2[v])%MD2;
}

pll remove(ll u, ll v){
    pll hs = g[u];
    hs.first = ((hs.first-pw[v])+MD)%MD;
    hs.second = ((hs.second-pw2[v])+MD2)%MD2;
    return hs;
}

void precalc(){
    pw[0] = 1LL;
    for(int i=1;i<MM;i++) pw[i] = (pw[i-1]*b)%MD;
    pw2[0] = 1LL;
    for(int i=1;i<MM;i++) pw2[i] = (pw2[i-1]*b2)%MD2;
}

void answer(){
    ll n, m;
    cin>>n>>m;
    vector<pll> ed;
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
        ed.push_back({u,v});
    }
    ll ans = 0LL;
    for(auto [u,v]:ed){
        pll hs1 = remove(u,v);
        pll hs2 = remove(v,u);
        if(hs1==hs2) ans++;
    }
    map<pll, int> mp;
    mp[g[1]]++;
    for(int i=2;i<=n;i++){
        ans+=mp[g[i]];
        mp[g[i]]++;
    }
    cout<<ans<<NN;
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