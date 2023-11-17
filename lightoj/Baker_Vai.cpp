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


int g[102][102],gc[102][102];
int n,m;


void precalc(){
    
}

int findMax1(int r, int c){
    for(int i=n-1;i>=r;i--){
        for(int j=m-1;j>=c;j--){
            if(gc[i][j]==-1) continue;
            if(i+1==n and j+1==m) gc[i][j] = g[i][j];
            else if(i+1==n) gc[i][j] = g[i][j]+gc[i][j+1];
            else if(j+1==m) gc[i][j] = g[i][j]+gc[i+1][j];
            else{
                if(gc[i][j+1]>=gc[i+1][j]){
                    gc[i][j] = g[i][j] + gc[i][j+1];
                }
                else gc[i][j] = g[i][j] + gc[i+1][j];
            }
        }
    }
    return gc[r][c];
}

void mark1(int i, int j){
    if(i+1==n and j+1==m){
        gc[i][j] = -1;
        return ;
    }
    if(j+1==m){
        mark1(i+1,j);
        gc[i][j] = -1;
        return;
    }
    else if(i+1==n){
        mark1(i,j+1);
        gc[i][j] = -1;
        return;
    }
    gc[i][j] = -1;
    if(gc[i][j+1]>=gc[i+1][j]) mark1(i,j+1);
    else mark1(i+1,j);

}


void answer(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            gc[i][j] = 0;
        }
    }
    n--;
    int v1 = findMax1(0,1);
    mark1(0,1);
    n++;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cerr<<gc[i][j]<<SS;
    //     }
    //     cerr<<NN;
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gc[i][j]!=-1){
                gc[i][j] = 0;
            }
        }
    }
    int v2 = findMax1(0,0);
    // cerr<<v2<<NN;
    int ans1=v1+v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            gc[i][j] = 0;
        }
    }
    m--;
    v1 = findMax1(1,0);
    mark1(1,0);
    m++;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gc[i][j]!=-1){
                gc[i][j] = 0;
            }
        }
    }
    v2 = findMax1(0,0);
    int ans2=v1+v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            gc[i][j] = 0;
        }
    }
    cout<<max(ans1,ans2)<<NN;

}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    // fast();
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