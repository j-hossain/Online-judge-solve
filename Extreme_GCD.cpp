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
const ll MM = 1e4 + 3;
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

vector<int> prm[MM];
ll fact[MM];

void seive()
{
    vector<bool> isPrime(MM, true);
    isPrime[1] = false;
    for (ll i = 2; i < MM; i++)
    {
        if (isPrime[i])
        {
            prm[i].push_back(i);
            for (ll j = i + i; j < MM; j += i)
            {
                isPrime[j] = false;
                prm[j].push_back(i);
            }
        }
    }
}

ll bigmod(ll a, ll b)
{
    ll ret = 1LL;
    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % MD;
        a = (a * a) % MD;
        b >>= 1;
    }
    return ret;
}

ll nCr(ll n, ll r)
{
    if (n < r)
        return 0LL;
    return (fact[n] * (bigmod((fact[n - r] * fact[r]) % MD, MD - 2))) % MD;
}

ll getRed(vector<int> &a, map<int, int> &mp)
{
    int n = a.size();
    ll ret = 0LL;
    for (ll i = 1; i < (1LL << n); i++)
    {
        int cnt = 0;
        ll mul = 1LL;
        for (int j = 0; j < (int)a.size(); j++)
        {
            if (i & (1LL << j))
            {
                mul *= a[j];
                cnt++;
            }
        }
        mp[mul]--;
        if (cnt & 1)
            ret += mp[mul];
        else
            ret -= mp[mul];
    }
    return ret;
}

void calCount(vector<int> &a, map<int, int> &mp)
{
    int n = a.size();
    for (ll i = 1; i < (1LL << n); i++)
    {
        ll mul = 1LL;
        for (int j = 0; j < (int)a.size(); j++)
        {
            if (i & (1LL << j))
            {
                mul *= a[j];
            }
        }
        mp[mul]++;
    }
}

void precalc()
{
    seive();
    fact[0] = 1LL;
    for (int i = 1; i < MM; i++)
        fact[i] = (fact[i - 1] * i) % MD;
}

void answer()
{
    int n;
    cin >> n;
    int a[n + 2];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        calCount(prm[a[i]], mp);
    }
    ll ans = nCr(n, 4);
    ll toRed = 0LL;
    for (int i = 0; i < n; i++)
    {
        ll red = getRed(prm[a[i]], mp);
        // cout << a[i] << " = ";
        // for (auto j : prm[a[i]])
        //     cout << j << SS;
        // cout << " + " << red << NN;
        toRed += nCr(red, 3);
    }
    cout << (ans - (toRed + 1) / 2) << NN;
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