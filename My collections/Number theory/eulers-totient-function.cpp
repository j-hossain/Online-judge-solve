// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;
// <for runtime show>
using namespace std::chrono;
#define t_start \
    auto start = high_resolution_clock::now();
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<microseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
// </for runtime show>

//<for debug config>
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
template <typename _er>
void _print(_er t)
{
    cerr << t;
}
//</for debug config>

//<shortcut macros>
#define li long long int
#define uli unsigned long long int

// loops
#define ff(i, e) for (int i = 0; i < e; i++)
#define bf(i, s) for (int i = s - 1; i >= 0; i--)
#define ff2(j, s, e) for (int j = s; j < e; j++)
#define bf2(j, s, e) for (int j = s - 1; j >= e; j--)

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
#define pno cout << "NO\n"
#define pys cout << "YES\n"
#define out(x) cout << x << " "
#define outln(x) cout << x << "\n"
#define out2(x, y) cout << x << " " << y << "\n"
#define pcs cout << "Case " << TK << ": "
#define SS ' '
#define NN "\n"

// inputs simplified
#define ar_in(arr, n)  \
    ff(i, n)           \
    {                  \
        cin >> arr[i]; \
    }
// most used numbers
#define MM 100005
#define MD 1000000007
#define PI acos(0)
// template declarations simplified
#define vcc(x) vector<x>
#define qq(x) queue<x>
#define MP(a, b) make_pair(a, b)
//</shortcut macros>

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class mtup
{
    int i;
    int v;
    mtup(int a, int b)
    {
        i = a;
        v = b;
    }
    bool operator<(const mtup &a) const
    {
        return v < a.v;
    }
    bool operator>(const mtup &a) const
    {
        return v > a.v;
    }
};

vcc(int) phi_1_to_n(int n)
{
    vcc(int) phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}