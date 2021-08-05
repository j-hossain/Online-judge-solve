#include<iostream>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}
//accepted
int main(){
    inout();
    int t,n,i,j,k,dp[105][105],arr[105],sum[105];
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=INT32_MIN;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            dp[i][i]=arr[i];
            sum[i] = arr[i]+sum[i-1];
        }

        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    dp[i][j]=max(dp[i][j],sum[k]-sum[i-1]-(k+1<=j?dp[k+1][j]:0));
                    dp[i][j]=max(dp[i][j],sum[j]-sum[k-1]-(k-1>=i?dp[i][k-1]:0));
                }
            }
        }
        cout<<"Case "<<tt<<": ";
        cout<<dp[1][n]<<"\n";
    }
}