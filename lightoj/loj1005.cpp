#include<iostream>
using namespace std;
#define li long long int
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li dp[35][35][1000];

li getWays(li r, li c, li k){
    if(dp[r][c][k]!=-1)
        return dp[r][c][k];
    if(k>r || k>c){
        dp[r][c][k]=0;
        return dp[r][c][k];
    }
    if(k==0){
        dp[r][c][k]=1;
        return dp[r][c][k];
    }
    dp[r][c][k] = c*(getWays(r-1,c-1,k-1))+getWays(r-1,c,k);
    return dp[r][c][k];
}

int main(){
    inout();
    fast();
    li n,k,i,j,t,tk;
    cin>>t;
    tk=0;
    while(t--){
        tk++;
        cin>>n>>k;
        for(i=0;i<31;i++){
            for(j=0;j<31;j++){
                for(int z=0;z<1000;z++)
                    dp[i][j][z]=-1;
            }
        }
        dp[n][n][k]=getWays(n,n,k);
        cout<<"Case "<<tk<<": ";
        cout<<dp[n][n][k]<<"\n";
    }
    return 0;
}