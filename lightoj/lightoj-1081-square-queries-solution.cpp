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
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<milliseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<shortcut macros>
#define li long long int
#define uli unsigned long long int

// most used numbers
const int MM = 5e2 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// runs test cases
#define test() \
    int TT;    \
    cin >> TT; \
    for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS ' '
#define NN '\n'

// template declarations simplified
#define pii pair<int, int>
#define pll pair<li, li>
#define MP(a, b) make_pair(a, b)
#define PP(x) push_back(x)
#define ALL(x) x.begin(), x.end()

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

int arr[MM][MM];
int seg[3*MM][3*MM];

void build2(int st, int en, int nd, int r, int sr){
    if(st==en){
        seg[r][nd]=arr[sr][st];
        return;
    }
    build2(left,r,sr);
    build2(right,r,sr);
    int sft = nd<<1;
    seg[r][nd] = max(seg[r][sft],seg[r][sft+1]);
}

void merge(int st, int en, int nd, int r){
    if(st==en){
        seg[r][nd] = max(seg[r<<1][nd],seg[(r<<1)+1][nd]);
        return; 
    }
    merge(left,r);
    merge(right,r);
    seg[r][nd] = max(seg[(r<<1)][nd],seg[(r<<1)+1][nd]);
}

void build(int st,int en, int nd, int n){
    if(st==en){
        build2(0,n-1,1,nd,st);
        return;
    }
    build(left,n);
    build(right,n);
    merge(0,n-1,1,nd);
}

int query2(int st, int en, int nd, int r, int i, int j){
    if(en<i or j<st) return 0;
    if(i<=st and en<=j){
    // cout<<st<<" "<<en<<" "<<seg[r][nd]<<"\n";
        return seg[r][nd];
    }
    return max(query2(left,r,i,j),query2(right,r,i,j));
}

int query(int st, int en, int nd, int ri,int rj, int ci, int cj, int n){
    if(en<ri or rj<st) return 0;
    if(ri<=st and en<=rj){
    // cout<<st<<" "<<en<<"--\n";
        return query2(0,n-1,1,nd,ci,cj);
    }
    return max(query(left,ri,rj,ci,cj,n),query(right,ri,rj,ci,cj,n));
}

void answer()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    build(0,n-1,1,n);
    while(q--){
        int ri,rj,ci,cj,d;
        cin>>ri>>ci>>d;
        ri--;
        ci--;
        rj = ri+d-1;
        cj = ci+d-1;
        // cout<<ri<<ci<<rj<<cj<<"\n";
        cout<<query(0,n-1,1,ri,rj,ci,cj,n)<<"\n";
    }
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
    inout();
    //    t_start;
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }
    //     t_show;

    return 0;
}
