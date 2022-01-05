#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define DN int main()
#define li long long int
#define uli unsigned long long int
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define inp(x) cin >> x
#define inp1(x, y) cin >> x >> y
#define inp2(x, y, z) cin >> x >> y >> z
#define pno cout << "NO\n"
#define pys cout << "YES\n"
#define out(x) cout << x;
#define outsp(x) cout << x << " "
#define outln(x) cout << x << "\n"
#define out2(x, y) cout << x << " " << y << "\n"
#define pcs cout << "Case " << tk << ": "
#define mx 100005
#define mx2 200005
#define md 1000000007
#define spc ' '
#define nn "\n"
#define bitOn(list, target) list | (1 << target)
#define bitOff(list, target) list &(~(1 << target))
#define bitCheck(list, target) (list & (1 << target)) == (1 << target) ? true : false

#define vcc(x) vector<x>
#define qq(x) queue<x>

#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1

#define ff(s, e) for (i = s; i < e; i++)
#define bf(s, e) for (i = s; i > e; i--)
#define ff2(j, s, e) for (j = s; j < e; j += 1)
#define bf2(j, s, e) for (j = s - 1; j >= e; j -= 1)
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(li t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// void _print(lld t) {cerr << t;}
void _print(double t) { cerr << t; }
void _print(uli t) { cerr << t; }

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct mymy
{
    int i;
    int v;
    int mm, mn;
    // string a;
    // li y;
    // li z;
    // void getZ(){
    //     z = (y-x+1)%2;
    // }
    bool operator<(const mymy &a) const
    {
        return v < a.v;
    }
};

void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif

} // predefined common functions
int findPar(int a, int *color)
{
    if (color[a] == a)
        return a;
    return color[a] = findPar(color[a], color);
}

li gcd(li a, li b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

li lcm(li a, li b)
{
    return (a * b) / gcd(a, b);
}

int n, helt[16], dp[1 << 16];
string pw[16];

int getAns(int killed)
{
    if (killed == (1 << (n + 1)) - 1)
    {
        // cout << "hello\n";
        return 0;
    }
    if (dp[killed] != -1)
    {
        return dp[killed];
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        int c = bitCheck(killed, i);
        if (!c)
        {
            for (int j = 0; j <= n; j++)
            {
                int pwi = pw[j][i - 1] - '0';
                int v = bitCheck(killed, j);
                if (v and pwi > 0)
                {
                    // cout << "helo\n";
                    int cnt = helt[i] / pwi + (helt[i] % pwi == 0 ? 0 : 1);
                    if (cnt > 0)
                    {
                        int x = bitOn(killed, i);
                        ans = min(ans, cnt + getAns(x));
                        // cout << ans << "\n";
                    }
                }
            }
        }
    }

    // cout << ans << "\n";
    return dp[killed] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> helt[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        pw[0].push_back('1');
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pw[i];
    }

    int ans = getAns(1);
    cout << ans << "\n";
}

DN
{
    fast();
    inout();
    int tc = 1;
    test()
    {
        cout << "Case " << tc << ": ";
        solve();
        tc++;
    }

    return 0;
}
// Ninja techniques

// easyli fond out which bits are on
//  int n=4;//     int t=(1<<n)-1;
//      while(t){
//          cout<<"First t: "<<t<<"\n";
//          int k=t&-t;
//           k=t&-t denotes the lowest on bit
//          cout<<"k: "<<k<<"\n";
//          t-=k;
//          cout<<"Second t: "<<t<<"\n";
//      }

// eulers toitient Function
//  void phi_1_to_n(int n) {
//      vector<int> phi(n + 1);
//      phi[0] = 0;
//      phi[1] = 1;
//      for (int i = 2; i <= n; i++)
//          phi[i] = i;

//     for (int i = 2; i <= n; i++) {
//         if (phi[i] == i) {
//             for (int j = i; j <= n; j += i)
//                 phi[j] -= phi[j] / i;
//         }
//     }
// }

// faster seive
//  const ll N=1e8;

// vll primes;
// void optimize_seive()
// {
//     vector<bool> vis(N,0);
//     primes.emplace_back(2);
//     for(ll i=3 ; i< N ; i+=2)
//     {
//         if(vis[i]==0)
//         {
//             primes.emplace_back(i);
//             for(ll j = i*i ; j < N ; j+=2*i)
//             {
//                 vis[j]=1;
//             }
//         }
//     }
// }

// int lower_bound(int arr[], int N, int X)
// {
//     int mid;

//     // Initialise starting index and
//     // ending index
//     int low = 0;
//     int high = N;

//     // Till low is less than high
//     while (low < high) {
//         mid = low + (high - low) / 2;

//         // If X is less than or equal
//         // to arr[mid], then find in
//         // left subarray
//         if (X <= arr[mid]) {
//             high = mid;
//         }

//         // If X is greater arr[mid]
//         // then find in right subarray
//         else {
//             low = mid + 1;
//         }
//     }

//     // if X is greater than arr[n-1]
//     if(low < N && arr[low] < X) {
//        low++;
//     }

//     // Return the lower_bound index
//     return low;
// }