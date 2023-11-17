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



void precalc(){
    
}

void answer(){
    int n,k;
    cin>>n>>k;
    int a[n+2];
    for(int i=0;i<n;i++) a[i] = 0;
    int need;
    for(int i=1;i<=n/2;i++){
        need = i/k+(i%k!=0);
        int nd = need;
        for(int j=0;j<i;j++){
            if(a[j]) nd--;
        }
        for(int j=i-1;i>=0 and nd;j--){
            if(a[j]==0){
                a[j] = 1;
                a[n-j-1] = 1;
                nd--;
            }
        }
    }
    int ex = 0;
    for(int i=n/2+1;i<=n;i++){
        int nd = i/k+(i%k!=0);
        // cout<<nd<<SS<<ex<<NN;
        for(int j=0;j<i;j++){
            if(a[j])nd--;
        }
        if(nd<ex) nd = 0;
        else nd-=ex;
        ex+=nd;
        // cout<<nd<<SS<<ex<<NN;
    }
    cout<<(2*need)+ex<<NN;
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
        // pcs;
        answer();
    }

    return 0;
}