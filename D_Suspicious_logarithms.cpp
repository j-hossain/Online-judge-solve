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

const int mx2 = 61;

ll preAns[mx2];

ll getRangeSum(ll a, ll b, ll pw)
{
    ll ret = 0LL;
    ll cnt = 0LL;
    ll cur = pw;
    do
    {
        if (cur > a)
        {
            ll x = (cnt * ((min(cur, b + 1) - a + MD) % MD)) % MD;
            ret = (ret + x) % MD;
            // cout << cur << SS << pw << SS << cnt << SS << x << "--\n";
            a = min(cur, b + 1);
        }
        if (cur < 1e18 / pw)
            cur *= pw;
        else
            cur = 4e18 + 10;
        cnt++;
    } while (a <= b);
    return ret;
}

ll getSum(ll a)
{
    if (a <= 3)
        return 0LL;
    ll ret = 0LL;
    for (int i = 2; i < mx2; i++)
    {
        if (a >= ((1LL << (i + 1)) - 1))
            ret = (ret + preAns[i]) % MD;
        else
        {
            ret = (ret + getRangeSum((1LL << i), a, i) % MD) % MD;
            break;
        }
    }
    // cout << a << SS << ret << NN;
    return ret;
}

void precalc()
{
    preAns[1] = 0;
    for (int i = 2; i < mx2; i++)
    {
        preAns[i] = getRangeSum((1LL << i), (1LL << (i + 1)) - 1, i) % MD;
        // cout << i << SS << preAns[i] << NN;
    }
}

void answer()
{
    ll a, b;
    cin >> a >> b;
    ll ans = getSum(b) - getSum(a - 1);
    if (ans < 0)
        ans += MD;
    ans %= MD;
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
        // pcs;
        answer();
    }

    return 0;
}