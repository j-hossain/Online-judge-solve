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

void precalc()
{
}

int cnt[5][MM], las[5], pre[5][MM];
int val[] = {1, 10, 100, 1000, 10000};

ll getSum(int st, int en, int k)
{
    ll sum = 0LL;
    for (int i = st; i <= en; i++)
    {
        int tar = 0;
        for (int j = i + 1; j < 5; j++)
        {
            tar = max(tar, las[j]);
        }
        if (tar <= k)
        {
            sum += (val[i] * (cnt[i][k - 1] - cnt[i][pre[i][k - 1]]));
        }
    }
    return sum;
}

void answer()
{
    string s;
    cin >> s;
    int n = s.size();
    ll org = 0LL;
    for (int i = 0; i < 5; i++)
    {
        las[i] = 0;
        for (int j = 0; j <= n; j++)
        {
            cnt[i][j] = 0;
            pre[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ch = s[i - 1] - 'A';
        las[ch] = i;
        cnt[ch][i]++;
        for (int x = ch + 1; x < 5; x++)
        {
            pre[ch][i] = max(pre[ch][i], las[x]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int ch = s[i - 1] - 'A';
        bool f = false;
        for (int x = ch + 1; x < 5; x++)
        {
            if (las[x] > i)
                f = true;
        }
        if (f)
            org -= val[ch];
        else
            org += val[ch];
    }
    cout << org << NN;
    for (int i = 0; i < 5; i++)
    {
        cnt[i][0] = 0;
        for (int j = 1; j <= n; j++)
        {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    ll ans = org;
    for (int i = 1; i < n; i++)
    {
        int ch = s[i - 1] - 'A';
        ll nw;
        for (int x = 0; x < 5; x++)
        {
            nw = org;
            if (x < ch)
            {
                nw = org + (2 * getSum(x, ch - 1, i));
                if (las[ch] > i)
                    nw += val[ch];
                else
                    nw -= val[ch];
                if (las[x] > i)
                    nw -= val[x];
                else
                    nw += val[x];
            }
            else if (x > ch)
            {
                nw = org - (2 * getSum(ch, x - 1, i));
                if (las[ch] > i)
                    nw += val[ch];
                else
                    nw -= val[ch];
                if (las[x] > i)
                    nw -= val[x];
                else
                    nw += val[x];
            }
            ans = max(ans, nw);
            cout << ans << " " << i << NN;
        }
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
        // pcs;
        answer();
    }

    return 0;
}