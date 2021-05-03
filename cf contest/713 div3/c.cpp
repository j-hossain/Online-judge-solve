#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int tx;cin>>tx;while(tx--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


void solve(){
    string inp;
    int g[2],t[2],i,n;
    test(){
        cin>>t[0]>>t[1]>>inp;
        n=t[1]+t[0];
        g[0]=g[1]=0;
        for(i=0;i<n;i++){
            g[inp[i]-'0']++;
        }
        t[0]-=g[0];
        t[1]-=g[1];
        int flag=1;
        for(i=0;i<n;i++){
            if(inp[i]=='0'){
                if(inp[n-i-1]=='?' && t[0]>=1){
                    t[0]--;
                    inp[n-i-1]='0';
                }
                else if(inp[n-i-1]!='0'){
                    flag=0;
                    break;
                }
            }
            if(inp[i]=='1'){
                if(inp[n-i-1]=='?' && t[1]>=1){
                    t[1]--;
                    inp[n-i-1]='1';
                }
                else if(inp[n-i-1]!='1'){
                    flag=0;
                    break;
                }
            }
        }
        // cout<<inp<<"\n";

        if(flag){
            for(i=0;i<=n/2;i++){
                if(inp[i]!='?')
                    continue;
                if(i==n-i-1){
                    if(t[0]>=1){
                        inp[i]='0';
                        t[0]--;
                    }
                    else if(t[1]>=1){
                        inp[i]='1';
                        t[1]--;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                else if(t[0]>=2){
                    inp[i]=inp[n-i-1]='0';
                    t[0]-=2;
                }
                else if(t[1]>=2){
                    inp[i]=inp[n-i-1]='1';
                    t[1]-=2;
                }
                else{
                    flag=0;
                    break;
                }
            }
        }

        if(flag && t[0]==0 && t[1]==0){
            cout<<inp<<"\n";
        }
        else
            cout<<"-1\n";   
    }
}

DN
{
    // fast();
    inout();
    
    solve();

    return 0;
}
