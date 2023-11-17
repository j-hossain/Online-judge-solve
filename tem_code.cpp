#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    freopen("wigz.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll g[503][504];
        ll r[504],c[504];
        for(int i=0;i<n;i++) r[i] = 0LL;
        for(int i=0;i<m;i++) c[i] = 0LL;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                r[i]+=g[i][j];
                c[j]+=g[i][j];
            }
        }
        ll ans = 0LL;
        if(n<m){
            for(int i=0;i<m;i++){
                for(int j=0;j<=i;j++){
                    swap(g[i][j],g[j][i]);
                }
            }
            swap(n,m);
        }
            for(ll i = 0;i<(1LL<<m);i++){
                if(__builtin_popcount(i)>k) continue;
                ll tem[n+2];
                ll cur = 0LL;
                for(int j=0;j<n;j++) tem[j] = r[j];
                for(int j=0;j<m;j++){
                    if((1LL<<j)&i){
                        cur+=c[j];
                        for(int k=0;k<n;k++) tem[k]-=g[k][j];
                    }
                }
                sort(tem,tem+n,greater<ll>());
                ll rem = k-__builtin_popcount(i);
                if(rem>n) continue;
                for(int j=0;j<rem;j++){
                    cur+=tem[j];
                }
                ans = max(ans,cur);
            }
        
        cout<<ans<<"\n";
    }
}