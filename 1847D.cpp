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
const ll MM = 2e5 + 3;
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

vector<int> str[MM],enn[MM];
ll a[MM];
ll seg[3*MM]; 

void build(int st, int en, int nd){
    if(st==en){
        seg[nd] = a[st];
        return ;
    }
    build(left);
    build(right);
    seg[nd] = seg[nd*2]+seg[(nd*2)+1];
}

void update(int st, int en, int nd, int p){
    if(p<st or en<p) return;
    if(st==en){
        if(st==p) seg[nd] = a[st];
        return;
    }
    update(left,p);
    update(right,p);
    seg[nd] = seg[nd*2]+seg[(nd*2)+1];
}

ll query(int st, int en, int nd, int i, int j){
    if(en<i or j<st) return 0 ;
    if(i<=st and en<=j) return seg[nd];
    return query(left,i,j)+query(right,i,j);
}


void precalc(){
    
}

void answer(){
    ll n,m,q;
    cin>>n>>m>>q;
    string s;
    cin>>s;
    // cout<<s<<"--\n";
    for(int i=1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        str[l].push_back(i);
        enn[r].push_back(i);
    }
    set<ll> cur;
    int pos[n+2];
    for(int i=0;i<n;i++){
        while(!str[i].empty()){
            cur.insert(str[i].back());
            str[i].pop_back();
        }
        if(!cur.empty()) pos[i] = *cur.begin();
        else pos[i] = n+2;
        while(!enn[i].empty()){
            cur.erase(enn[i].back());
            enn[i].pop_back();
        }
    }
    vector<pair<int,int>> pw;
    for(int i=0;i<n;i++){
        if(pos[i]!=n+2){
            pw.push_back({pos[i],i});
        }
    }
    sort(All(pw));
    int segSize = pw.size();
    for(int i=0;i<pw.size();i++){
        pos[pw[i].second] = i;
        a[i] = s[pw[i].second]=='1'?1:0;
    }
    build(0,segSize,1);
    int tot = 0;
    for(int i=0;i<n;i++){
        tot+=s[i]=='1';
    }
    for(int i=0;i<q;i++){
        ll x;
        cin>>x;
        x--;
        if(s[x]=='1'){
            tot--;
            s[x] = '0';
        }
        else{
            tot++;
            s[x] = '1';
        }
        if(pos[x]!=n+2){
            a[pos[x]] ^=1;
            update(0,segSize,1,pos[x]);
        }
        ll len = min(segSize,tot);
        ll sm = query(0,segSize,1,0,len-1);
        ll ze = len-sm;
        cout<<ze<<NN;
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
    // fast();
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