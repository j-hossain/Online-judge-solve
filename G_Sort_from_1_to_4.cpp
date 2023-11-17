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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}


int forThis(vector<vector<int>>& g, int tar){
    int ans = 0;
    for(int i=1;i<=4;i++){
        if(i==tar) continue;
        if(g[tar][i]>0){
            ans+=g[tar][i];
            if(g[i][tar]>0){
                int x = min(g[i][tar],g[tar][i]);
                g[i][tar]-=x;
                g[tar][i]-=x;
                g[i][i]+=x;
                g[tar][tar]+=x;
            }
        }
    }
    for(int i=1;i<=4;i++){
        if(i==tar) continue;
        if(g[i][tar]>0){
            for(int j=1;j<=4 and g[i][tar]>0;j++){
                if(j==tar) continue;
                int x = min(g[i][tar],g[tar][j]);
                g[i][tar]-=x;
                g[tar][j]-=x;
                g[i][j]+=x;
                g[tar][tar]+=x;
            }
        }
    }
    return ans;
}


int getAns(vector<vector<int>> g,int* a){
    int ans = 0;
    for(int i=0;i<4;i++){
        ans+=forThis(g,a[i]);
    }
    return ans;
}


void precalc(){
    
}

void answer(){
    int n;
    cin>>n;
    int a[n+2];
    int cnt[5] = {0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int pre = 0;
    vector<vector<int>> grid(5,vector<int>(5,0));
    for(int i=1;i<=4;i++){
        for(int j=0;j<cnt[i];j++){
            grid[i][a[pre+j]]++;
        }
        pre+=cnt[i];
    }
    int v[4] = {1,2,3,4};
    int ans = INT32_MAX;
    while (next_permutation(v,v+4))
    {
        ans = min(ans,getAns(grid,v));
    }
    cout<<ans<<NN;
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
    answer();

    //     when test cases exist
    // test()
    // {
    //     // cout<<"Case "<<TK<<":"<<NN;
    //     // pcs;
    //     answer();
    // }

    return 0;
}