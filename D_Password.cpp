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

const ll b = 29;
const ll b2 = 31;
const ll MD2 = 1e9+9;
ll pw[MM],pw2[MM];

bool possible(string s, int k){
    cerr<<k<<NN;
    if(!k) return true;
    int n = s.size();
    pll hs = {0LL,0LL};
    for(int i=0;i<k;i++){
        hs.first+=(pw[i]*(s[n-k+i]-'a'+1))%MD;
        hs.first%=MD;
        hs.second+=(pw2[i]*(s[n-k+i]-'a'+1))%MD2;
        hs.second%=MD2;
    }
    int f=0;
    pll mar = hs;
    for(int i=n-k-1;i>0;i--){
        hs.first-=(pw[k-1]*(s[i+k]-'a'+1))%MD;
        hs.first = (hs.first+MD)%MD;
        hs.first = (hs.first*b)%MD;
        hs.second-=(pw2[k-1]*(s[i+k]-'a'+1))%MD2;
        hs.second = (hs.second+MD2)%MD2;
        hs.second = (hs.second*b2)%MD2;
        hs.first+=(s[i]-'a'+1);
        hs.first%=MD;
        hs.second+=(s[i]-'a'+1);
        hs.second%=MD2;
        if(hs==mar) cerr<<"---"<<i<<NN;
        f|=(hs==mar);
    }
    if(f){
        int i=0;
        hs.first-=(pw[k-1]*(s[i+k]-'a'+1))%MD;
        hs.first = (hs.first+MD)%MD;
        hs.first = (hs.first*b)%MD;
        hs.second-=(pw2[k-1]*(s[i+k]-'a'+1))%MD2;
        hs.second = (hs.second+MD2)%MD2;
        hs.second = (hs.second*b2)%MD2;
        hs.first+=(s[i]-'a'+1);
        hs.first%=MD;
        hs.second+=(s[i]-'a'+1);
        hs.second%=MD2;
        cerr<<hs.first<<" "<<mar.first<<NN;
        return hs==mar;
    }
    return false;
}

void precalc(){
    pw[0] = 1LL;
    for(int i=1;i<MM;i++) pw[i] = (pw[i-1]*b)%MD;
    pw2[0] = 1LL;
    for(int i=1;i<MM;i++) pw2[i] = (pw2[i-1]*b2)%MD2;
}

void answer(){
    string s;
    cin>>s;
    int n = s.size();
    int l = 0;
    int r = n-1;
    while(l<r-1){
        int md = (l+r)/2;
        if(possible(s,md)) l = md;
        else r = md;
        cerr<<l<<SS<<r<<NN;
    }
    if(possible(s,l+1)) l++;
    if(!l){
        cout<<"Just a legend"<<NN;
    }
    else{
        for(int i=0;i<l;i++) cout<<s[i];
        cout<<NN;
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