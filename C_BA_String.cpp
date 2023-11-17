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



void precalc(){
    
}

void answer(){
    ll n,k,x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    vector<ll> pos,cap,fin;
    string cur;
    cur.push_back(s[0]);
    ll cnt = 0;
    if(s[0]=='*'){
        pos.push_back(0);
        fin.push_back(0);
    }
    for(int i=1;i<n;i++){
        if(s[i]=='*'){
            if(s[i]==s[i-1]) cnt++;
            else{
                cnt = 1;
                cur.push_back(s[i]);
                pos.push_back(i);
                fin.push_back(0);
            }
        } 
        else{
            if(cnt){
                cap.push_back(cnt*k);
            }
            cnt = 0;
            cur.push_back(s[i]);
        }
    }
    if(cnt){
        cap.push_back(cnt*k);
    }
    x--;
    cnt = 0LL;
    ll mul = 0;
    ll till;
    ll rem;
    for(int i=pos.size()-1;i>=0;i--){
        mul = (cnt+1)*cap[i];
        if(cnt+mul>=x){
            rem = x-cnt;
            till = i;
        }
        cnt+=mul;
    }
    if(rem){
        fin[till]++;
        rem--;
    }
    for(int i = pos.size()-1;i>=till;i--){
        fin[i] += rem%cap[i];
        cout<<rem<<SS<<cap[i]<<NN;
        rem/=cap[i];
    }
    cnt = 0;
    for(int i=0;i<cur.size();i++){
        if(cur[i]=='a') cout<<cur[i];
        else{
            while(fin[cnt]--) cout<<'b';
            cnt++;
        }
    }
    cout<<NN;
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