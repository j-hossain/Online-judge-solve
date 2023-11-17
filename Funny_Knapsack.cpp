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

void generateSums(ll sum, ll p, bool taken, ll *a, ll n, vector<ll> &sa)
{
    if (p == n)
    {
        if (taken)
            sa.push_back(sum);
        return;
    }
    generateSums(sum, p + 1, taken, a, n, sa);
    generateSums(sum + a[p], p + 1, taken | 1, a, n, sa);
}

void precalc()
{
}

void answer()
{
    ll n, w;
    cin >> n >> w;
    ll m = n / 2;
    n = (n + 1) / 2;
    ll a[n + 2], b[m + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<ll> sa, sb;
    generateSums(0LL, 0, false, a, n, sa);
    generateSums(0LL, 0, false, b, m, sb);
    sort(All(sa));
    sort(All(sb));
    ll ans = 1LL;
    for (auto i : sa)
        ans += (i <= w);
    for (auto i : sb)
        ans += (i <= w);
    int j = sb.size() - 1;
    for (int i = 0; i < (ll)sa.size(); i++)
    {
        while (j >= 0 and sa[i] + sb[j] > w)
            j--;
        if (j >= 0)
            ans += (j + 1);
    }
    cout << ans << NN;
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