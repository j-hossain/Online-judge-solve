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
#define test() \
    int TT;    \
    cin >> TT; \
    for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS " "
#define NN "\n"
#define pyes cout << "YES\n"
#define pno cout << "NO\n"

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
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int par[MM], c[MM];
set<int> g[MM];
int vis[MM];
vector<int> ans;

void revDfs(int u)
{
    if (!g[u].empty())
        return;
    vis[u] = 1;
    ans.push_back(u);
    g[par[u]].erase(u);
    if (par[u] != -1)
        revDfs(par[u]);
}

pair<int, int> dfs(int u)
{
    vis[u] = 1;
    if (vis[par[u]])
        return {u, c[u]};
    pii x = dfs(par[u]);
    if (c[u] < x.second)
        return {u, c[u]};
    return x;
}

void precalc()
{
}

void answer()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        g[i].clear();
    }
    ans.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> par[i];
        g[par[i]].insert(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            revDfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // cout << i << SS;
            pii lw = dfs(i);
            int pp = par[lw.first];
            par[lw.first] = -1;
            g[pp].clear();
            revDfs(pp);
        }
    }
    for (auto i : ans)
        cout << i << SS;
    cout << NN;
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    // fast();
    // inout();
    precalc();
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        // cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}