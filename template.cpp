#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define DN int main()
#define li long long int
#define uli unsigned long long int
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define inp(x) cin >> x
#define inp1(x, y) cin >> x >> y
#define inp2(x, y, z) cin >> x >> y >> z
#define pno cout << "NO\n"
#define pys cout << "YES\n"
#define out(x) cout << x;
#define outsp(x) cout << x << " "
#define outln(x) cout << x << "\n"
#define out2(x, y) cout << x << " " << y << "\n"
#define pcs cout << "Case " << tk << ": "
#define mx 100005
#define mx2 200005
#define md 1000000007
#define spc ' '
#define nn "\n"

#define vcc(x) vector<x>
#define qq(x) queue<x>

#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1

#define ff(s, e) for (i = s; i < e; i++)
#define bf(s, e) for (i = s; i > e; i--)
#define ff2(j, s, e) for (j = s; j < e; j += 1)
#define bf2(j, s, e) for (j = s - 1; j >= e; j -= 1)

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct mymy
{
    int i;
    int v;
    int mm, mn;
    // string a;
    // li y;
    // li z;
    // void getZ(){
    //     z = (y-x+1)%2;
    // }
    bool operator<(const mymy &a) const
    {
        return v < a.v;
    }
};

void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

li arr[mx];
string grph[mx];
int n,m;
int I[] = {0,1,0,-1};
int J[] = {1,0,-1,0};

int dfs(int i,int j){
    int cnt=0;
    for(int k=0;k<4;k++){
        int tempi = i+I[k];
        int tempj = j+J[k];
        if(tempi!=i and tempj!=j){
            if(tempi>=0 and tempj>=0 and tempi<n and tempj<n){
                cnt++;
            }
        }
    }

    if(cnt<=1){

    }
}

void logic()
{
    int posi,posj;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>grph[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grph[i][j]=='L'){
                posi = i;
                posj = j;
            } 
        }
    }

    dfs(posi,posj);

}
DN
{
    fast();
    inout();
    test()
        logic();

    return 0;
}
// Ninja techniques

// easyli fond out which bits are on
//  int n=4;
//      int t=(1<<n)-1;
//      while(t){
//          cout<<"First t: "<<t<<"\n";
//          int k=t&-t;
//           k=t&-t denotes the lowest on bit
//          cout<<"k: "<<k<<"\n";
//          t-=k;
//          cout<<"Second t: "<<t<<"\n";
//      }

// eulers toitient Function
//  void phi_1_to_n(int n) {
//      vector<int> phi(n + 1);
//      phi[0] = 0;
//      phi[1] = 1;
//      for (int i = 2; i <= n; i++)
//          phi[i] = i;

//     for (int i = 2; i <= n; i++) {
//         if (phi[i] == i) {
//             for (int j = i; j <= n; j += i)
//                 phi[j] -= phi[j] / i;
//         }
//     }
// }

// faster seive
//  const ll N=1e8;

// vll primes;
// void optimize_seive()
// {
//     vector<bool> vis(N,0);
//     primes.emplace_back(2);
//     for(ll i=3 ; i< N ; i+=2)
//     {
//         if(vis[i]==0)
//         {
//             primes.emplace_back(i);
//             for(ll j = i*i ; j < N ; j+=2*i)
//             {
//                 vis[j]=1;
//             }
//         }
//     }
// }
// O(n) time subarray sum from https://www.geeksforgeeks.org/sum-of-all-subarrays/
// long int SubArraySum( int arr[] , int n )
// {
//     long int result = 0;

//     // computing sum of subarray using formula
//     for (int i=0; i<n; i++)
//         result += (arr[i] * (i+1) * (n-i));

//     // return all subarray sum
//     return result ;
// }