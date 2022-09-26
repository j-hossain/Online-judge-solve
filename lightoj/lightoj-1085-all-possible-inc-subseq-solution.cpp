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
const int MM = 1e5 + 3;
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

li arr[MM];
set<li> st;
map<li,int> mp;
li seg[5*MM];

void build(int st,int en, int nd){
    if(st==en){
        seg[nd]=0;
        return;
    }
    build(left);
    build(right);
    int sft = nd<<1;
    seg[nd] = seg[sft]+seg[sft+1];
}

void update(int st, int en, int nd, int i, int v){
    if(en<i or i<st) return;
    if(st==en and st==i){
        seg[nd]+=v;
        seg[nd]%=MD;
        return;
    }
    update(left,i,v);
    update(right,i,v);
    int sft = nd<<1;
    seg[nd] = (seg[sft]+seg[sft+1])%MD;
}

li query(int st, int en, int nd, int i, int j){
    if(en<i or j<st) return 0LL;
    if(i<=st and en<=j) return seg[nd];
    return (query(left,i,j)+query(right,i,j))%MD;
}

void answer()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    li cnt=0;
    for(int el:st){
        mp[el] = ++cnt;
    }
    for(int i=0;i<n;i++){
        arr[i] = mp[arr[i]];
    }
    st.clear();
    mp.clear();

    build(0,cnt,1);
    li ans =0LL;
    for(int i=n-1;i>=0;i--){
        li til=1LL;
        if(arr[i]<cnt)
            til += query(0,cnt,1,arr[i]+1,cnt);
        ans+=til;
        ans%=MD;
        update(0,cnt,1,arr[i],til);
    }
    cout<<ans<<"\n";
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    // fast();
    inout();
    //    t_start;
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        // cout<<"Case "<<TK<<":"<<NN;
        pcs;
        answer();
    }
    //     t_show;

    return 0;
}
