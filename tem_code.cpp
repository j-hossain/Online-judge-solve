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
const int MM = 3e3 + 3;
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

pii pnt[MM];
pii qrs[MM];

int nums[MM][MM];

int getDis(pii a, pii b){
    int x = abs(a.first-b.first);
    x*=x;
    int y = abs(a.second-b.second);
    y*=y;
    double dd = (double)x+y;
    int db = sqrt(dd);
    if(db*db!=dd) db++;
    return db;
}

int low(int q,int d){
    int l,u;
    l=0;
    u = q;
    while(l<u){
        int md = (l+u)/2;
        if(qrs[md].first<d) l = md+1;
        else u = md;
    }
    return l;
}

void answer()
{
    int n,q;
    while(cin>>n>>q){
        if(n==0 and q==0) break;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            pnt[i] = {x,y};
        }
        for(int i=0;i<q;i++){
            int rr;
            cin>>rr;
            qrs[i] = {rr,i};
        }
        sort(qrs,qrs+q);

        for(int i=0;i<n;i++){
            for(int j=0;j<q;j++){
                nums[i][j]=0;
            }
            for(int j=0;j<n;j++){
                int dis = getDis(pnt[i],pnt[j]);
                int pos = low(q,dis);
                // cout<<pos<<"\n";
                nums[i][pos]++;
            }
            for(int j=1;j<q;j++){
                nums[i][j] +=nums[i][j-1];
            }
        }

        double ans[q+2];
        double pos = 1.0/n;
        for(int j=0;j<q;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                sum+=nums[i][j];
            }
            ans[qrs[j].second] = pos*sum; 
        }
        for(int i=0;i<q;i++){
            printf("%.2lf\n",ans[i]);
        }
        printf("\n");
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
    // for(li i=0; i<MM; i++)
    // {
    //     for(li j=0; j<=i; j++)
    //     {
    //         if(j==0||j==i) c[i][j]=1;
    //         else c[i][j]=(c[i-1][j-1]+c[i-1][j])%2;
    //         // cout<<c[i][j]<<" ";
    //     }
    //     // cout<<"\n";
    // }
    //    t_start;
    //     for no test case
    answer();

    //     when test cases exist
    // test()
    // {
    //     cout<<"Case "<<TK<<":"<<NN;
    //     // pcs;
    //     answer();
    // }
    //     t_show;

    return 0;
}
