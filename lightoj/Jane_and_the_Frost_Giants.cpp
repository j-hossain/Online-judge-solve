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
const ll MM = 2e2 + 3;
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

struct points{
    int i,j;
    points(int i, int j){
        this->i = i;
        this->j = j;
    }
    points(){i=j=0;}
};

string g[MM];
int dis[MM][MM];
int dis1[MM][MM];

void precalc(){
    
}

void answer(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    vector<points> fires;
    points jeni;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='F') fires.push_back({i,j});
            else if(g[i][j]=='J')jeni = {i,j};
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dis[i][j] = 1e9;
    }
    queue<points> qq;
    for(int i=0;i<(int)fires.size();i++){
        qq.push(fires[i]);
        auto [x,y] = fires[i];
        dis[x][y] = 0;
    }
    while (!qq.empty())
    {
        auto[x,y] = qq.front();
        qq.pop();
        for(int i=0;i<4;i++){
            int xx = dx[i]+x;
            int yy = dy[i]+y;
            if(xx>=0 and xx<n and yy>=0 and yy<m){
                if(g[xx][yy]!='#'){
                    if(dis[x][y]+1<dis[xx][yy])
                    {
                        dis[xx][yy] = dis[x][y]+1;
                        qq.push({xx,yy});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dis1[i][j] = 1e9;
    }
    qq.push(jeni);
    dis1[jeni.i][jeni.j] = 0;
    // cout<<jeni.i<<SS<<jeni.j<<NN;
    int ans = 1e8;
    while (!qq.empty())
    {
        auto [x,y] = qq.front();
        if(x==n-1 or y==m-1 or y==0 or x==0) ans = min(ans,dis1[x][y]+1);
        qq.pop();
        for(int i=0;i<4;i++){
            int xx = dx[i]+x;
            int yy = dy[i]+y;
            if(xx>=0 and xx<n and yy>=0 and yy<m){
                if(g[xx][yy]=='.'){
                    if(dis1[x][y]+1<dis[xx][yy] and dis1[x][y]+1<dis1[xx][yy])
                    {
                        dis1[xx][yy] = dis1[x][y]+1;
                        qq.push({xx,yy});
                    }
                }
            }
        }
    }
    if(ans==(int)1e8) cout<<"IMPOSSIBLE\n";
    else cout<<ans<<NN;
    

    
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
    inout();
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