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
#define mx          100000005
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

int cmp(mymy a, mymy b){
    return a.y>b.y;
}

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li arr[mx2];


void logic(){
    li n,l,r,cnt;
    cin>>n>>l>>r;
    for(li i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    li ans=0;
    // for(li i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<"\n";
    for(li i=0;i<n;i++){

        li *up = upper_bound(arr,arr+n,r-arr[i]);
        li *low = lower_bound(arr,arr+n,l-arr[i]);
        // cout<<r-arr[i]<<" "<<(up-arr)<<" "<<l-arr[i]<<" "<<(low-arr)<<"\n";
        ans += up-arr;
        ans -= low-arr;
        if(l<=2*arr[i] && 2*arr[i]<=r)
            ans--;
    }

    cout<<(ans/2)<<"\n";
    return;
    
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

//easyly fond out which bits are on
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