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
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS " " 
#define NN "\n"
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"

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
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}
ll g[1001][1001];

ll getAns(ll r[], ll c[], ll n, ll m, ll x, ll k){
    // Taking the selected columns
    ll ret = 0LL;
    for(ll j=0;j<m;j++){
        if((1LL<<j)&x){
            k--;
            ret+=c[j];
            for(ll i=0;i<n;i++){
                r[i]-=g[i][j];
            }
        }
    }
    // Taking the rest of the number of rows greedily
    sort(r,r+n,greater<ll>());
    for(ll i=0;i<min(k,n);i++){
        if(r[i]>0) ret+=r[i];
    }
    return ret;
}


void precalc(){
    
}

void answer(){
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    if(n<m){
        // Transpose the matrix to keep the number of columns lower than rows
        for(ll i=0;i<m;i++){
            for(ll j=0;j<i and j<n;j++){
                swap(g[i][j],g[j][i]);
            }
        }
        swap(n,m);
    }
    // Row sums
    ll r[n+2];
    for(ll i=0;i<n;i++){
        r[i] = 0LL;
        for(ll j=0;j<m;j++){
            r[i]+=g[i][j];
        }
    }
    // column sums
    ll c[m+2];
    for(ll j=0;j<m;j++){
        c[j] = 0LL;
        for(ll i=0;i<n;i++){
            c[j]+=g[i][j];
        }
    }
    // bruteforce over all possible combination for columns
    ll ans = 0;
    for(ll i=0;i<(1LL<<m);i++){
        if(__builtin_popcount(i)<=k)ans = max(ans,getAns(r,c,n,m,i,k));
    }
    cout<<ans<<NN;
}
// remember these polls
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    freopen("wigz.in", "r", stdin);
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