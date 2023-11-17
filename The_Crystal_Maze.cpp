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

int n,m,cnt,vis[502][502];
string g[502];

void dfs(int i, int j, int ca){
    if(i<0 or i>=n or j<0 or j>=m) return;
    if(g[i][j]=='#') return;
    if(g[i][j]=='C') cnt++;
    g[i][j] = '#';
    vis[i][j] = ca;
    dfs(i-1,j,ca);
    dfs(i+1,j,ca);
    dfs(i,j-1,ca);
    dfs(i,j+1,ca);
}

void precalc(){
    
}

void answer(){
    cin>>n>>m;
    int q;
    cin>>q;
    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)vis[i][j] = 0;
    }
    int ca = 1;
    int ans[100000];
    ans[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]!='#'){
                cnt=0;
                dfs(i,j,ca);
                ans[ca++] = cnt;
            }
        }
    }
    while(q--){
        ca++;
        int i,j;
        cin>>i>>j;
        cout<<ans[vis[i][j]]<<NN;
    }
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
        cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}