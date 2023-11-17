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

ll ans[204][204];

void precalc(){
    ll cur = 0LL;
    set<ll> st;
    for(int i=0;i<203;i+=2){
        for(int j=0;j<203;j+=2){
            if((i/2)%2){
                if((j/2)%2){
                    ans[i+1][j] = cur++;
                    ans[i+1][j+1] = cur++;
                    ans[i][j] = cur++;
                    ans[i][j+1] = cur++;
                }
                else{
                    ans[i+1][j+1] = cur++;
                    ans[i+1][j] = cur++;
                    ans[i][j+1] = cur++;
                    ans[i][j] = cur++;
                }
            }
            else{
                if((j/2)%2){
                    ans[i][j+1] = cur++;
                    ans[i][j] = cur++;
                    ans[i+1][j+1] = cur++;
                    ans[i+1][j] = cur++;
                }
                else{
                    ans[i][j] = cur++;
                    ans[i][j+1] = cur++;
                    ans[i+1][j] = cur++;
                    ans[i+1][j+1] = cur++;
                }
            }
            
        }
    }
    for(int i=0;i<200;i++){
        for(int j=0;j<200;j++){
            ll num1 = ans[i][j]^ans[i][j+1]^ans[i+1][j]^ans[i+1][j+1];
            ll num2 = ans[i+2][j]^ans[i+2][j+1]^ans[i+3][j]^ans[i+3][j+1];
            ll num3 = ans[i][j+2]^ans[i][j+3]^ans[i+1][j+2]^ans[i+1][j+3];
            ll num4 = ans[i+2][j]^ans[i+2][j+1]^ans[i+3][j]^ans[i+3][j+1];
            if(num1!=num2 or num3!=num3){
                cout<<num1<<SS<<num2<<SS<<num3<<SS<<num4<<NN;
            }
            // st.insert(num);
            // if(num){
            //     cerr<<num<<SS<<ans[i][j]<<SS<<ans[i][j+1]<<SS<<ans[i+1][j]<<SS<<ans[i+1][j+1]<<NN;
            // }
        }
    }
    for(auto s:st) cerr<<s<<NN;
}

void answer(){
    ll n,m;
    cin>>n>>m;
    set<ll> st;
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