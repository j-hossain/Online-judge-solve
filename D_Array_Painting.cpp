/*
Here's to the crazy ones, the misfits, the rebels, the troublemakers,
the round pegs in the square holes ... the ones who see things differently .
They're not fond of rules, and they have no respect for the status quo. ...
You can quote them, disagree with them, glorify or vilify them,
but the only thing you can't do is ignore them because they change things. ...
They push the human race forward, and while some may see them as the crazy ones,
we see genius, because the people who are crazy enough to think that they can change the world, are the ones who do.
*/
/*
I watched a snail crawl along the edge of a straight razor.
That's my dream; that's my nightmare.
Crawling, slithering, along the edge of a straight razor.d.. and surviving..


1 3 6 2 7 4 5
2 5 -1 -1 -1 4 -1


*/
// Templates
// 1. tempgeo.cpp
// 2. tempunion.cpp
// 3. mysegtree.cpp
// 4. tempnt.cpp

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define int ll
#define pii pair <int, int>
#define pll pair <long long, long long>
#define trip pair < int, pair < int, pair < int, int > > >
#define endl '\n'
#include <random>
#define PI (2.0 * acos(0.0))
#define testcase int TT; cin >> TT; for (int tc = 1; tc <= TT; tc++)
// #define info pair<int, pair < int, string > >

#define mkp make_pair
#define info pair < int, pii >
// typedef fraction T;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
int fx[10] = {1, -1, 0, 0, 1, -1, 1, -1};
int fy[10] = {0, 0, 1, -1, 1 , -1, -1, 1};
const long long M = 2e5 + 30, M2 = 1e6 + 20, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
inline int ceil(int a, int b) {
return (a + b - 1) / b;
}
inline int abs (int a, int b) {
int d1 = a - b;
if (d1 < 0) d1 *= -1;
return d1;
}

long long bigmod (int n, int p, int md) {
if (p == 0) return 1;
long long ans= bigmod(n, p / 2, md);
ans = (ans * ans) % md;
if (p % 2 == 1) ans = (ans * n) % md;
return ans;
}
long long pinverse (int num, int md) {
return bigmod(num, md - 2, md);
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ceil is a bad function
// think about reverse process
// read statement carefully
// think about corner cases before implementing
// don't forget to comment/uncomment define endl in interactive/non-interactive problems
// check if you are returning from solve before resetting array values
// try not to use continue / return statement, try to use if else
// try to write custom functions if stl one deals with floating point values
// don't use unordered map without custom hash
// multiset is bad try to use map if possible
// don't forget to return a value from a non-void function
vector < int > pos[3];
void precomp() {
}
void solve () {
    int n;
    cin >> n;
    vector < int > ara(n + 2, 0), vis(n + 2, 0);
    for (int i = 1, x; i <= n; i++) {
        cin >> ara[i];
        pos[ara[i]].push_back(i);
    }
    int ans = 0;
    for (int x : pos[2]) {
        int got = 0;
        for (int i = x; i <= n; i++) {
            if (vis[i]) break;
            vis[i] = 1;
            got = 1;
            if (ara[i] == 0) break;
        }
        for (int i = x - 1; i >= 1; i--) {
            if (vis[i]) break;
            vis[i] = 1;
            got = 1;
            if (ara[i] == 0) break;
        }
        ans += got;
    }
    vector < int > nv;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            int j = i;
            int zr = 0, sw = 0;
            int pre = 0;
            while (j <= n && vis[j] == 0){
                if (ara[j] == 0) zr++;
                if (ara[j] == 1 && pre == 0) sw++;
                pre = ara[j];
                vis[j] = 1;
                j++;
            }
            ans += max(zr, sw); 
            i = j - 1;
        }
    }
    cout << ans << endl;
}
int32_t main () {
    // freopen("E:/newts/in.txt", "r", stdin);
    // freopen("E:/newts/out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    // int T;
    // scanf("%d", &T);
    // while (T--) {
    // testcase {
        // cout << "Case #" << tc << ": ";
        // cout << "Case " << tc << ": ";
       solve ();
    // }
return 0;
}
/*
*/