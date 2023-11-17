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

ll dis[20][20];
ll mem[1 << 16];
int n;

ll getAns(ll par)
{
    if (par == 0)
        return 0LL;
    if (mem[par] != -1)
        return mem[par];
    mem[par] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        if (!(par & (1LL << i)))
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (!(par & (1LL << j)))
                continue;
            mem[par] = min(mem[par], dis[i][j] + getAns(par ^ (1LL << i) ^ (1LL << j)));
        }
    }
    // cout << bitset<7>(par) << SS << mem[par] << NN;
    return mem[par];
}

void precalc()
{
}

void answer()
{
    ll par;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 1e16;
        }
        dis[i][i] = 0LL;
    }
    par = 0;
    ll ans = 0LL;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        ans += w;
        if (u == v)
            continue;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
        par ^= (1LL << u);
        par ^= (1LL << v);
    }
    if (par == 0)
    {
        cout << ans << NN;
        return;
    }
    // cout << bitset<7>(par) << SS << ans << NN;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    memset(mem, -1, sizeof(mem));
    cout << ans + getAns(par) << NN;
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
        // cout<<"Case "<<TK<<":"<<NN;
        pcs;
        answer();
    }

    return 0;
}