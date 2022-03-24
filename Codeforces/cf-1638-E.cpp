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
#define pcs \
    cout << "Case " << TK << ": "
#define SS \
    ' '
#define NN \
    "\n"

void out(auto x, int ender = 2)
{
    // ender is 1 for ending with space, 2 for ending with an endline, and other for none
    cout << x;
    if (ender == 1)
        cout << " ";
    else if (ender == 2)
        cout << "\n";
}
void out(auto x, auto y, int ender = 2)
{
    out(x, 1);
    out(y, ender);
}
void out(auto x, auto y, auto z, int ender = 2)
{
    out(x, 1);
    out(y, 1);
    out(z, ender);
}

// arrays simplified
#define ARIN(arr, n)   \
    ff(i, n)           \
    {                  \
        cin >> arr[i]; \
    }
#define AROUT(arr, n) \
    ff(i, n)          \
    {                 \
        out(arr[i]);  \
    }
// order is 1 for ascending and -1 for descending

bool ISSORTED(auto arr, auto n, int order)
{
    ff2(i, 1, n)
    {
        if (order == 1)
        {
            if (arr[i] - arr[i - 1] < 0)
                return false;
        }
        else
        {
            if (arr[i] - arr[i - 1] > 0)
                return false;
        }
    }
    return true;
}

// most used numbers
#define MM (int)(1e6 + 3)
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
#define left \
    st, (st + en) / 2, nd * 2
#define right \
    (st + en) / 2 + 1, en, nd * 2 + 1

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// custom tuple class
class mtup
{
public:
    int i;
    li v;
    mtup(int a = 0, li b = 0)
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

int n;
mtup segTree[3 * MM];

void buildSeg(int st, int en, int nd)
{
    if (st == en)
    {
        segTree[nd].i = 1;
        segTree[nd].v = 0;
        return;
    }
    buildSeg(left);
    buildSeg(right);

    if (segTree[nd * 2].i == segTree[nd * 2 + 1].i)
    {
        segTree[nd].i = segTree[nd * 2].i;
    }
    else
    {
        segTree[nd].i = 0;
    }
    segTree[nd].v = 0;
}

void updateCol(int st, int en, int nd, int i, int j, int c)
{
    if (en < i or j < st)
    {
        return;
    }
    if (i <= st and en <= j)
    {
        segTree[nd].i = c;
        return;
    }
    if (st == en)
        return;

    updateCol(left, i, j, c);
    updateCol(right, i, j, c);

    if (segTree[nd * 2].i == segTree[nd * 2 + 1].i)
    {
        segTree[nd].i = segTree[nd * 2].i;
    }
    else
    {
        segTree[nd].i = 0;
    }
}

void updateVal(int st, int en, int nd, int c, int val)
{
    if (segTree[nd].i == c)
    {
        segTree[nd].v += val;
        return;
    }
    if (segTree[nd].i != 0)
        return;
    if (st == en)
    {
        return;
    }
    updateVal(left, c, val);
    updateVal(right, c, val);

    if (segTree[nd * 2].i == segTree[nd * 2 + 1].i)
    {
        segTree[nd].i = segTree[nd * 2].i;
    }
    else
    {
        segTree[nd].i = 0;
    }
}

li query(int st, int en, int nd, int i, int parc, int parv)
{
    // out(st, en, nd, 2);
    if (parc != 0)
    {
        segTree[nd].i = parc;
    }
    segTree[nd].v += parv;

    if (st == en and en == i)
    {
        return segTree[nd].v;
    }
    if (en < i or st > i)
        return 0;

    li ret = query(left, i, segTree[nd].i, segTree[nd].v) + query(right, i, segTree[nd].i, segTree[nd].v);
    segTree[nd].v = 0;
    return ret;
}

void answer()
{
    int q, i, j, c, v;
    li ans;
    string op;
    cin >> n >> q;
    buildSeg(0, n - 1, 1);
    while (q--)
    {
        cin >> op;
        if (op == "Color")
        {
            cin >> i >> j >> c;
            i--;
            j--;
            // update their color
            updateCol(0, n - 1, 1, i, j, c);
        }
        else if (op == "Add")
        {
            cin >> c >> v;
            // add v to c colored indexes
            updateVal(0, n - 1, 1, c, v);
            // cout << "ALL: ";
            // ff(i, n)
            // {
            //     ans = query(0, n - 1, 1, i, 0, 0);
            //     out(ans, 1);
            // }
            // cout << NN;
        }
        else if (op == "Query")
        {
            cin >> i;
            i--;
            // get the current value of ith index
            ans = query(0, n - 1, 1, i, 0, 0);
            out(ans);
        }
    }
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
    t_start;
    // for no test case
    answer();

    // when test cases exist
    // test()
    // {
    //     // pcs;
    //     answer();
    // }
    // t_show;

    return 0;
}
