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
const ll MM = 3e5 + 3;
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

ll const BS = 29;
ll const BS2 = 31;
ll const MD2 = 1e9+9;
ll PW[MM],PW2[MM];

int doHash(string& s, int& len, unordered_set<ll>& st, int cat){
    ll hs = 0LL;
    ll hs2 = 0LL;
    int n = s.size();
    int ret = -1;
    for(int i=n-1;i>=n-len;i--){
        hs = (hs*BS)%MD;
        hs = (hs+(s[i]-'a'+1))%MD;
        hs2 = (hs2*BS2)%MD2;
        hs2 = (hs2+(s[i]-'a'+1))%MD2;
    }
    if(cat==1){
        st.insert((hs<<32)|hs2);
    }
    else if(cat==2){
        if(st.find((hs<<32)|hs2)!=st.end()) ret = n-len;
    }
    for(int i=n-len-1;i>=0;i--){
        hs = ((hs-(((s[i+len]-'a'+1)*PW[len-1])%MD))+MD)%MD;
        hs = (hs*BS)%MD;
        hs = (hs+(s[i]-'a'+1))%MD;
        hs2 = ((hs2-(((s[i+len]-'a'+1)*PW2[len-1])%MD2))+MD2)%MD2;
        hs2 = (hs2*BS2)%MD2;
        hs2 = (hs2+(s[i]-'a'+1))%MD2;
        if(cat==1){
            st.insert((hs<<32)|hs2);
        }
        else if(cat==2){
            if(st.find((hs<<32)|hs2)!=st.end()) ret = i;
        }
    }
    return ret;
}

bool pos(string& a, string& b, int len){
    unordered_set<ll> st;
    doHash(a,len,st,1);
    return doHash(b,len,st,2)!=-1;
}

void printAns(string& a, string& b, int len){
    unordered_set<ll> st;
    doHash(a,len,st,1);
    int in = doHash(b,len,st,2);
    for(int i=in;i<in+len;i++) cout<<b[i];
    cout<<NN<<len<<NN;;
}


void precalc(){
    PW[0] = PW2[0] = 1LL;
    for(int i=1;i<MM;i++) PW[i] = (PW[i-1]*BS)%MD;
    for(int i=1;i<MM;i++) PW2[i] = (PW2[i-1]*BS2)%MD2;
}

void answer(){
    string a,b;
    cin>>a>>b;
    int l = 0;
    int r = b.size();
    while(l<r-1){
        int md = (l+r)/2;
        // cerr<<l<<SS<<md<<SS<<r<<NN;
        if(pos(a,b,md))l = md;
        else r = md;
    }
    if(pos(a,b,l+1)) l++;
    printAns(a,b,l);
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