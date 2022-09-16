/*
    ▀ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▀
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█▀▀▄▄░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▀▀▄░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▀▄░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▄▀░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▄▄▀░░░░░░░░░░░░░░░
    ░░░░░░░░░█▄▄▀▀░░░░JOKER░░░░░░░░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ▄ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▄
*/

// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

// <for runtime show>
using namespace std::chrono;

#define t_start auto start = high_resolution_clock::now();
#ifndef ONLINE_JUDGE
#define t_show auto stop = high_resolution_clock::now();auto duration = duration_cast<milliseconds>(stop - start);cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<for debug config>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " " << x << "\n";
#else
#define debug(x)
#endif
//</for debug config>

//<shortcut macros>
#define li  long long int
#define uli unsigned long long int

// most used numbers
const int MM = 1e5 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);

// loops
#define ff(i, e)        for (li i = 0; i < e; i++)
#define bf(i, s)        for (li i = s - 1; i >= 0; i--)
#define ff2(j, s, e)    for (li j = s; j < e; j++)
#define bf2(j, s, e)    for (li j = s - 1; j >= e; j--)

// runs test cases
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pno cout << "NO\n"
#define pys cout << "YES\n"
#define pcs cout << "Case " << TK << ": "
#define SS  ' '
#define NN  '\n'

void out(auto x)                                    {cout << x;}
void out(auto x, char ender)                        {out(x);out(ender);}
void out(auto x, auto y, char ender)                {out(x, SS);out(y, ender);}
void out(auto x, auto y, auto z, char ender)        {out(x, SS);out(y, SS);out(z, ender);}
void out(auto x, auto y, auto z, auto a, char ender){out(x, SS);out(y, SS);out(z, SS);out(a, ender);}

// arrays simplified
#define ARIN(arr, n)    ff(i, n)cin >> arr[i];
#define AROUT(arr, n)   ff(i, n)out(arr[i]);

// order is 1 for ascending and -1 for descending
bool ISSORTED(auto arr, auto n, int order){ff2(i, 1, n){if (order == 1){if (arr[i] - arr[i - 1] < 0)return false;}else{if (arr[i] - arr[i - 1] > 0)return false;}}return true;}


// template declarations simplified
#define vcc(x)      vector<x>
#define qq(x)       queue<x>
#define MP(a, b)    make_pair(a, b)
#define PP(vec, x)  vec.push_back(x)
#define ALL(x)      x.begin(), x.end()
#define VIP(vec, x) cin >> x;PP(vec, x)
//</shortcut macros>

// for segmentation
#define left    st, (st + en) / 2, nd * 2
#define right   (st + en) / 2 + 1, en, nd * 2 + 1

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// custom tuple class
class mtup{
public:
    int i;
    int v;
    mtup(int a = 0, int b = 0){
        i = a;
        v = b;
    }
    bool operator<(const mtup &a) const{
        return v < a.v;
    }
    bool operator>(const mtup &a) const{
        return v > a.v;
    }
};

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

void answer(){
    int r,c;
    char grid[30][30];
    cin>>r>>c;
    r*=2;
    c*=2;
    for(int i=0;i<=r;i++){
        if(i%2==0){
            for(int j=0;j<=c;j++){
                if(j%2==0){
                    grid[i][j]='+';
                }
                else{
                    grid[i][j]='-';
                }
            }
        }
        else{
            for(int j=0;j<=c;j++){
                if(j%2==0){
                    grid[i][j]='|';
                }
                else{
                    grid[i][j]='.';
                }
            }
        }
    }
    grid[0][0]=grid[0][1]=grid[1][0]=grid[1][1]='.';
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            cout<<grid[i][j];
        }
        cout<<NN;
    }
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main(){
    fast();
    // inout();
    t_start;
    // for no test case
    // answer();

    // when test cases exist
    test(){
        // pcs;
        cout<<"Case #"<<TK<<":\n";
        answer();
    }
    // t_show;

    return 0;
}
