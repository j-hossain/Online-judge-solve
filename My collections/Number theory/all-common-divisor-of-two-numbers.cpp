// given two numbers find all the common divisors of them
// the answer is actually the divisor of their GCD
// So the complexity is log(max(a,b))+sq(GCD(a,b))
// this was first used in the problem spoj COMDIV - Number of common divisors

/*
    ▀ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▀
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█▀▀▄▄░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▀▀▄░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▀▄░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▄▀░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▄▄▀░░░░░░░░░░░░░░░
    ░░░░░░░░░█▄▄▀▀░░░░JOKER░░░░░░░░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ▄ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▄
*/

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
#ifndef ONLINE_JUDGE
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<microseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<for debug config>
#ifndef ONLINE_JUDGE
#define debug(x) \
    cout << #x << " " << x << "\n";
#else
#define debug(x)
#endif
template <typename _er>
void _print(_er t)
{
    cout << t;
}
//</for debug config>

//<shortcut macros>
#define li \
    long long int
#define uli \
    unsigned long long int

// loops
#define ff(i, e) \
    for (int i = 0; i < e; i++)
#define bf(i, s) \
    for (int i = s - 1; i >= 0; i--)
#define ff2(j, s, e) \
    for (int j = s; j < e; j++)
#define bf2(j, s, e) \
    for (int j = s - 1; j >= e; j--)

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
#define pno \
    cout << "NO\n"
#define pys \
    cout << "YES\n"
#define out(x) \
    cout << x << " "
#define outln(x) \
    cout << x << "\n"
#define out2(x, y) \
    cout << x << " " << y << "\n"
#define pcs \
    cout << "Case " << TK << ": "
#define SS \
    ' '
#define NN \
    "\n"

// inputs simplified
#define ARIN(arr, n)   \
    ff(i, n)           \
    {                  \
        cin >> arr[i]; \
    }
#define AROUT(arr, n) \
    ff(i, n)          \
    {                 \
        out(arr[i]);  \
    }                 \
    cout << "\n";

// most used numbers
#define MM (int)(1e5 + 3)
#define MD (int)(1e9 + 7)
#define PI acos(0)

// template declarations simplified
#define vcc(x) vector<x>
#define qq(x) queue<x>
#define MP(a, b) make_pair(a, b)
#define PP(vec, x) vec.push_back(x)
#define ALL(x) x.begin(), x.end()
#define VIP(vec, x) \
    cin >> x;       \
    PP(vec, x)
//</shortcut macros>

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// custom tuple class
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
// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

vcc(int) allDivisors(int n, int m)
{
    int GC = __gcd(n, m);
    vcc(int) com;
    int sq = sqrt(GC);
    ff2(i, 1, sq + 1)
    {
        if (GC % i == 0)
        {
            PP(com, i);
            if (GC / i != i)
                PP(com, GC / i);
        }
    }
    return com;
}

void answer()
{
    int n, m;
    cin >> n >> m;
    vcc(int) ans = allDivisors(n, m);
    AROUT(ans, ans.size());
}

// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
    inout();
    // t_start;
    // for no test case
    // answer();

    // when test cases exist
    test()
    {
        // pcs;
        answer();
    }
    // t_show;

    return 0;
}
