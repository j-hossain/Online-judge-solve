#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define DN          int main()
#define li          unsigned long long int
#define uli         unsigned long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inp(x)      cin>>x
#define inp1(x,y)   cin>>x>>y
#define inp2(x,y,z) cin>>x>>y>>z
#define pno         cout<<"NO\n"
#define pys         cout<<"YES\n"
#define out(x)      cout<<x;
#define outsp(x)    cout<<x<<" "
#define outln(x)    cout<<x<<"\n"
#define out2(x,y)   cout<<x<<" "<<y<<"\n"
#define pcs         cout<<"Case "<<tk<<": "
#define mx          100005
#define mx2         200005
#define md          1000000007
#define spc         ' '
#define nn          "\n"

#define vcc(x)      vector<x>
#define qq(x)       queue<x>

#define left        st,(st+en)/2,nd+nd
#define right       (st+en)/2+1,en,nd+nd+1

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e)      for(j=s;j<e;j+=1)
#define bf2(j,s,e)      for(j=s-1;j>=e;j-=1)

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct mymy{
    int i;
    int v;
    int mm,mn;
    // string a;
    // li y;
    // li z;
    // void getZ(){
    //     z = (y-x+1)%2;
    // }
    bool operator<(const mymy &a)const{
        return v<a.v;
    }
};

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


uli gcd(uli a, uli b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void logic(){
    uli x,y,m,n;
    cin>>x>>y>>m;
    x-=m;
    y-=m;
    // cout<<a<<spc<<b<<'\n';
    n = __gcd(x,y);
    cout<<n<<"\n";
}
DN
{
    fast();
    // inout();
    int tc = 1; 
    test(){
        // cout<<"Case "<<tc<<":"<<nn;
        logic();
    }
    
    return 0;
}
// Ninja techniques

//easyli fond out which bits are on
// int n=4;//     int t=(1<<n)-1;
//     while(t){
//         cout<<"First t: "<<t<<"\n";
//         int k=t&-t;
//          k=t&-t denotes the lowest on bit
//         cout<<"k: "<<k<<"\n";
//         t-=k;
//         cout<<"Second t: "<<t<<"\n";
//     }

//eulers toitient Function
// void phi_1_to_n(int n) {
//     vector<int> phi(n + 1);
//     phi[0] = 0;
//     phi[1] = 1;
//     for (int i = 2; i <= n; i++)
//         phi[i] = i;

//     for (int i = 2; i <= n; i++) {
//         if (phi[i] == i) {
//             for (int j = i; j <= n; j += i)
//                 phi[j] -= phi[j] / i;
//         }
//     }
// }

//faster seive
// const ll N=1e8;

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