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

int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int vis[1010][1010];
int dis[16][1010][1010];
vector<pll> points;
ll n,k;
ll mem[16][20][(1<<17)];

void bfs(int ind){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) vis[i][j] = 0;
    }
    queue<pll> qq;
    qq.push(points[ind]);
    dis[ind][points[ind].first][points[ind].second] = 0;
    while(!qq.empty()){
        pll u = qq.front();
        qq.pop();
        vis[u.first][u.second] = 1;
        for(int i=0;i<8;i++){
            ll x = X[i]+u.first;
            ll y = Y[i]+u.second;
            if(x>=0 and x<n and y>=0 and y<n){
                if(!vis[x][y]){
                    vis[x][y] = 1;
                    dis[ind][x][y] = dis[ind][u.first][u.second]+1;
                    qq.push({x,y});
                }
            }
        }

    }
}

ll getAns(int fir, int pre, ll msk){
    if(msk==((1<<k)-1)) return dis[pre][points[fir].first][points[fir].second];
    // cout<<fir<<SS<<pre<<SS<<msk<<NN;    
    if(mem[fir][pre][msk]!=-1) return mem[fir][pre][msk];
    ll ret = INT64_MAX;
    for(int i=0;i<k;i++){
        if(msk&(1LL<<i)) continue;
        ret = min(ret,getAns(fir,i,msk|(1LL<<i))+dis[pre][points[i].first][points[i].second]);
    }
    return mem[fir][pre][msk] = ret;
}

void precalc(){
    
}

void answer(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            for(int x=0;x<(1LL<<k);x++) mem[i][j][x] = -1;
        }
    }
    for(int i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        points.push_back({x,y});
    }
    // cout<<NN;
    for(int i=0;i<k;i++){
        bfs(i);
        // for(int x=0;x<n;x++){
        //     for(int y=0;y<n;y++){
        //         cout<<dis[i][x][y]<<SS;
        //     }
        //     cout<<NN;
        // }
        // cout<<NN;
    }
    ll ans = INT64_MAX;
    for(int i=0;i<k;i++){
        ans = min(ans,getAns(i,i,(1LL<<i)));
    }
    cout<<ans<<NN;
    points.clear();

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