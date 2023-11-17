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
const ll MM = 1e5 + 3;
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

pair<int, int> seg[3 * MM];
bool prop[3 * MM];
int a[MM];
string s;
int n;

void build(int st, int en, int nd)
{
    seg[nd] = {0, 0};
    prop[nd] = false;
    if (st == en)
    {
        if (s[st] == '1')
            seg[nd].first = a[st];
        else
            seg[nd].second = a[st];
        return;
    }
    build(left);
    build(right);
    seg[nd].first = seg[nd * 2].first ^ seg[nd * 2 + 1].first;
    seg[nd].second = seg[nd * 2].second ^ seg[nd * 2 + 1].second;
}

void update(int st, int en, int nd, int i, int j)
{
    if (prop[nd])
    {
        swap(seg[nd].first, seg[nd].second);
        prop[nd] = false;
        if (st != en)
        {
            prop[nd * 2] ^= true;
            prop[nd * 2 + 1] ^= true;
        }
    }
    if (st > j or en < i)
        return;
    if (i <= st and en <= j)
    {
        swap(seg[nd].first, seg[nd].second);
        if (st != en)
        {
            prop[nd * 2] ^= true;
            prop[nd * 2 + 1] ^= true;
        }
        return;
    }
    update(left, i, j);
    update(right, i, j);
    seg[nd].first = seg[nd * 2].first ^ seg[nd * 2 + 1].first;
    seg[nd].second = seg[nd * 2].second ^ seg[nd * 2 + 1].second;
}

void precalc()
{
}

void answer()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    build(0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int l, r;
            cin >> l >> r;
            update(0, n - 1, 1, l - 1, r - 1);
        }
        else
        {
            int x;
            cin >> x;
            if (x)
            {
                cout << seg[1].first << SS;
            }
            else
                cout << seg[1].second << SS;
        }
    }
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