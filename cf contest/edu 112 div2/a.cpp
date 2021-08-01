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
using namespace std;
//accepted
#define DN          int main()
#define li          long long int
#define uli         unsigned long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
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
#define mx          1000005
#define mx2         200005
#define md          1000000007
#define spc         ' '
#define nn          "\n"

#define vcc(x)      vector<x>
#define qq(x)       queue<x>

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e)      for(j=s;j<e;j+=1)
#define bf2(j,s,e)      for(j=s-1;j>=e;j-=1)


typedef struct{
    li x;
    li y;
    // li z;
}mymy;

// int cmp(mymy a, mymy b){
//     return a.y>b.y;
// }

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li getCount(li n, li a , li b){
    li temp = n/a;
    if(n%a!=0)
        temp++;
    temp*=b;
    return temp;
}

void logic(){
    li n,mn,temp;
    cin>>n;
    if(n<=6){
        cout<<"15\n";
        return ;
    }
    mn = __LONG_LONG_MAX__;
    if(n%6==0){
        mn=(n/6)*15;
    }
    else if(n%6<=2){
        mn = (n/6-1)*15+20;
    }
    else if(n%6<=4){
        mn = (n/6-1)*15+25;
    }
    else{
        mn = (n/6+1)*15;
    }

    if(n%8==0){
        mn = min(mn,(n/8)*20);
    }
    else if(n%8<=2){
        mn = min(mn,(n/8-1)*20+25);
    }
    else if(n%8<=6){
        mn = min(mn,(n/8)*20+15);
    }
    else{
        mn = min(mn,(n/8+1)*20) ;
    }

    if(n%10==0){
        mn = min(mn,(n/10)*25);
    }
    else if(n%10<=6){
        mn = min(mn,(n/10)*25+15);
    }
    else if(n%10<=8){
        mn = min(mn,(n/10)*25+20);
    }
    else{
        mn = min(mn,(n/10+1)*25) ;
    }
    cout<<mn<<"\n";

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

//easyli fond out which bits are on
// int n=4;
//     int t=(1<<n)-1;
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