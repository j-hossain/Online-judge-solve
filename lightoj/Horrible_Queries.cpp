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

int seg[3*MM],pro[3*MM];

void build(int st, int en, int nd){
    pro[nd] = 0;
    if(st==en){
        seg[nd] = 0;
        return;
    }
    build(left);
    build(right);
    seg[nd] = seg[nd*2]+seg[nd*2+1];
}

void update(int st, int en, int nd, int i, int j, int val){
    if(pro[nd]){
        seg[nd]+=((en-st+1)*pro[nd]);
        if(st!=en){
            pro[nd*2]+=pro[nd];
            pro[nd*2+1]+=pro[nd];
        }
        pro[nd] = 0;
    }

    if(en<i or j<st) return;
    if(i<=st and en<=j){
        seg[nd]+=((en-st+1)*val);
        if(st!=en){
            pro[nd*2]+=val;
            pro[nd*2+1]+=val;
        }
        return ;
    }
    update(left,i,j,val);
    update(right,i,j,val);
    seg[nd] = seg[nd*2]+seg[nd*2+1];
}

int query(int st, int en, int nd, int i, int j){
    if(pro[nd]){
        seg[nd]+=((en-st+1)*pro[nd]);
        if(st!=en){
            pro[nd*2]+=pro[nd];
            pro[nd*2+1]+=pro[nd];
        }
        pro[nd] = 0;
    }

    if(en<i or j<st) return 0;
    if(i<=st and en<=j){
        return seg[nd];
    }
    return query(left,i,j)+query(right,i,j);
}

void precalc(){
    
}

void answer(){
    int n,q;
    cin>>n>>q;
    build(0,n-1,1);
    while(q--){
        int t,i,j,v;
        cin>>t>>i>>j;
        if(!t){
            cin>>v;
            update(0,n-1,1,i,j,v);
        }
        else cout<<query(0,n-1,1,i,j)<<NN;
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
        cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}