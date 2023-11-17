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
template<class T> using ordered_set = tree< T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;


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
    ll n;
    cin>>n;
    ll a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 3;
    vector<pair<int, int>> op;
    while(op.size()<50){
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                if(a[i]+a[i-1]>=a[i-1]){
                    op.push_back({i+1,i});
                    a[i] = a[i]+a[i-1];
                }
                else{
                    op.push_back({i,i+1});
                    a[i-1] = a[i]+a[i-1];
                }
            }
        }
        bool f = true;
        for(int i=1;i<n;i++) f &= (a[i]>=a[i-1]);
        if(f) break;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<SS;
    }
    cout<<NN;
    cout<<op.size()<<NN;
    for(int i=0;i<op.size();i++){
        cout<<op[i].first<<SS<<op[i].second<<NN;
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
        // cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}