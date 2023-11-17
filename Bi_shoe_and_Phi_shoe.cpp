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
const ll MM = 1e6 + 5;
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

vector<pair<int, int>> phi(MM);

bool comp(pii a, pii b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

void precalc()
{
    for (int i = 0; i < MM; i++)
        phi[i].first = phi[i].second = i;
    for (int i = 2; i < MM; i++)
    {
        if (phi[i].first == i)
        {
            for (int j = i; j < MM; j += i)
            {
                phi[j].first *= (1 - (1 / (double)i));
            }
        }
    }
    phi.erase(phi.begin());
    phi.erase(phi.begin());
    sort(All(phi), comp);
}

void answer()
{
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int j = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; i++)
    {
        while (j < MM - 2 and phi[j].first < a[i])
            j++;
        ans += phi[j].second;
    }
    cout << ans << SS << "Xukha" << NN;
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