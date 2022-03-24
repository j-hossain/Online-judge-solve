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
template <typename ARR>
bool ISSORTED(ARR arr, int n, int order)
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
public:
    int i;
    int v;
    mtup(int a, int b)
    {
        i = a;
        v = b;
    }
    mtup()
    {
        i = 0;
        v = 0;
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

int grid[1005][1005];
int n, m;
vector<tuple<int, int, int>> ans;
queue<tuple<int, int, int>> boxes;

int di[] = {0, 0, 1, 1};
int dj[] = {0, 1, 0, 1};
int di2[] = {0, 0, -1, -1};
int dj2[] = {0, -1, 0, -1};

int getCol(int i, int j)
{
    if (i < 0 || i >= n - 1 || j < 0 || j >= m - 1)
        return 0;
    set<int> col;
    if (grid[i][j] != 0)
        col.insert(grid[i][j]);
    if (grid[i + 1][j] != 0)
        col.insert(grid[i + 1][j]);
    if (grid[i][j + 1] != 0)
        col.insert(grid[i][j + 1]);
    if (grid[i + 1][j + 1] != 0)
        col.insert(grid[i + 1][j + 1]);

    if (col.size() == 1)
    {
        grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = grid[i + 1][j + 1] = 0;
        int c = *col.begin();
        col.clear();
        return c;
    }
    col.clear();
    return 0;
}

void answer()
{
    int c;
    cin >> n >> m;
    ff(i, n)
    {
        ff(j, m)
        {
            cin >> grid[i][j];
        }
    }
    int sq = max(n, m);

    ff(i, n - 1)
    {
        ff(j, m - 1)
        {
            c = getCol(i, j);
            if (c)
            {
                // out2(i, j);
                // outln(c);
                boxes.push({i, j, c});
            }
        }
    }
    if (boxes.empty())
    {
        out(-1);
        return;
    }
    while (!boxes.empty())
    {
        tuple<int, int, int> u = boxes.front();
        ans.push_back(u);
        boxes.pop();
        ff(i, 4)
        {
            ff(j, 4)
            {
                c = getCol(get<0>(u) + di[i] + di2[j], get<1>(u) + dj[i] + dj2[j]);
                if (c)
                {
                    boxes.push({get<0>(u) + di[i] + di2[j], get<1>(u) + dj[i] + dj2[j], c});
                }
            }
        }
    }
    bool flag = true;
    ff(i, n)
    {
        ff(j, m)
        {
            // out(grid[i][j], 1);
            if (grid[i][j] != 0)
                flag = false;
        }
        // cout << NN;
    }
    if (!flag)
    {
        out(-1);
        return;
    }
    out(ans.size());
    bf(i, ans.size())
    {
        out(get<0>(ans[i]) + 1, get<1>(ans[i]) + 1, get<2>(ans[i]), 2);
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
