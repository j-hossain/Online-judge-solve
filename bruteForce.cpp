#include<bits/stdc++.h>
using namespace std;

#define li long long int

const int MD = 1e9+7;

double ans[3002][3002][2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    double arr[n+2];
    // for(int i=0;i<=n;i++)
    //     for(int j=0;j<=n;j++) ans[i][j][0]=ans[i][j][1]=1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            double prev = ans[i-1][j-1][0]+ans[i-1][j][0]+ans[i-1][j-1][1]+ans[i-1][j][1];
            ans[i][j][0] = prev*arr[i];
            ans[i][j][1] = prev*(1-arr[i]);
        }
    }
    double ret = 0.0;
    for(int i=n/2+1;i<=n;i++){
        ret+=ans[n][i][0];
        ret+=ans[n][i][1];
    }
    cout<<ret<<"\n";
    return 0;
}
