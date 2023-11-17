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
const ll MM = 3e4 + 3;
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

int ar[MM], seg[6 * MM], tms[2 * MM], rn[2][MM];
vector<int> g[MM];
int par[MM][16];
int cur;

void dfs(int u, int p)
{
    rn[0][u] = cur;
    tms[cur++] = ar[u];
    par[u][0] = p;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }
    rn[1][u] = cur;
    tms[cur++] = -ar[u];
}

void buildLca(int n)
{
    for (int l = 1; l < 16; l++)
    {
        for (int i = 0; i < n; i++)
        {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
}

bool is_ancestor(int u, int v)
{
    return rn[0][u] <= rn[0][v] && rn[1][u] >= rn[1][v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = 15; i >= 0; --i)
    {
        if (!is_ancestor(par[u][i], v))
            u = par[u][i];
    }
    return par[u][0];
}

void build(int st, int en, int nd)
{
    if (st == en)
    {
        seg[nd] = tms[st];
        return;
    }
    build(left);
    build(right);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}

void update(int st, int en, int nd, int p, int v)
{
    if (st == en)
    {
        if (st == p)
        {
            seg[nd] = v;
        }
        return;
    }
    if (en < p or p < st)
        return;
    update(left, p, v);
    update(right, p, v);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}

int query(int st, int en, int nd, int i, int j)
{
    if (en < i or j < st)
        return 0;
    if (i <= st and en <= j)
        return seg[nd];
    return query(left, i, j) + query(right, i, j);
}

void precalc()
{
}

void answer()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cur = 0;
    dfs(0, 0);
    build(0, cur - 1, 1);
    buildLca(n);
    int q;
    cin >> q;
    while (q--)
    {
        int tp, a, b;
        cin >> tp >> a >> b;
        if (tp == 0)
        {
            int lc = lca(a, b);
            cout << query(0, cur - 1, 1, rn[0][lc], rn[0][a]) + query(0, cur - 1, 1, rn[0][lc], rn[0][b]) - ar[lc] << NN;
        }
        else
        {
            ar[a] = b;
            tms[rn[0][a]] = b;
            tms[rn[1][a]] = -b;
            update(0, cur - 1, 1, rn[0][a], b);
            update(0, cur - 1, 1, rn[1][a], -b);
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
    // answer();

    //     when test cases exist
    test()
    {
        cout << "Case " << TK << ":" << NN;
        // pcs;
        answer();
    }

    return 0;
}