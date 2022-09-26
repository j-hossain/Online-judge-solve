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

//<shortcut macros>
#define li  long long int
#define uli unsigned long long int

// most used numbers
const int MM = 1e5 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);

//direction array
int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1, -1, 1};

// runs test cases
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS  ' '
#define NN  '\n'

// template declarations simplified
#define pii             pair<int,int>
#define pll             pair<li,li>
#define MP(a, b)        make_pair(a, b)
#define PP(x)           push_back(x)
#define ALL(x)          x.begin(), x.end()

// for segmentation
#define left    st, (st + en) / 2, nd * 2
#define right   (st + en) / 2 + 1, en, nd * 2 + 1
//</shortcut macros>

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}
 
string inp;
int seg[3*MM],lzy[3*MM];

int query(int st, int en, int nd,int i){
    if(lzy[nd]){
        lzy[nd]=0;
        if(st!=en){
            lzy[nd*2] ^=1;
            lzy[nd*2+1] ^=1;
        }
        seg[nd] = en-st+1-seg[nd];
    }
    if(st>i or en<i) return 0;
    if(st==en and st==i){
        return seg[nd];
    }
    return query(left,i) + query(right,i);
}

void update(int st, int en, int nd, int i, int j){
    if(lzy[nd]){
        lzy[nd]=0;
        if(st!=en){
            lzy[nd*2] ^=1;
            lzy[nd*2+1] ^=1;
        }
        seg[nd] = en-st+1-seg[nd];
    }
    if(st>j or en<i) return;
    if(i<=st and en<=j){
        seg[nd] = en-st+1-seg[nd];
        if(st!=en){
            lzy[nd*2] ^=1;
            lzy[nd*2+1] ^=1;
        }
        return;
    }
    update(left,i,j);
    update(right,i,j);
    seg[nd] = seg[nd*2]+seg[nd*2+1];
}

void build(int st, int en, int nd){
    if(st==en){
        seg[nd] = (inp[st]=='1');
        lzy[nd]=0;
        return;
    }
    build(left);
    build(right);
    seg[nd] = seg[nd*2]+seg[nd*2+1];
    lzy[nd]=0;
}

void answer(){
    cin>>inp;
    int n;
    n = inp.size();
    build(0,n-1,1);
    // cout<<inp<<"\n";
    int q;
    cin>>q;
    while(q--){
        string tp;
        cin>>tp;
        if(tp[0]=='Q'){
            int i;
            cin>>i;
            i--;
            cout<<query(0,n-1,1,i)<<"\n";
        }
        else{
            int i,j;
            cin>>i>>j;
            i--;
            j--;
            update(0,n-1,1,i,j);
        }
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
    inout();
//    t_start;
//     for no test case
//     answer();

//     when test cases exist
    test(){
        cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }
//     t_show;

    return 0;
}
