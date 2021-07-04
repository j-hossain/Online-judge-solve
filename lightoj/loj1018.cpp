#include<iostream>
#include<vector>
using namespace std;
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int n,cc[17][17],dp[1<<17];


int getIt(int msk){
    // cout<<msk<<"\n";
    if(msk==0)
        return 0;
    // cout<<dp[msk]<<"\n";
    if(dp[msk]!=-1)
        return dp[msk];
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(msk & (1<<i))
            temp.push_back(i);
    }
    int tt,ans = 1<<17;
    if(temp.size()==1)
        return dp[msk] = 1;
    for(int i=1;i<temp.size();i++){
        // cout<<(msk&(~cc[temp[i]][temp[j]]))<<"\n";
        tt=getIt(msk&(~cc[temp[0]][temp[i]])); 
        // cout<<tt<<"\n";
        ans = min(ans, 1+tt);
        // cout<<i<<" "<<j<<"\n";
    }
    
    return dp[msk]=ans;
}

int main(){
    inout();
    fast();
    int t, i, ans, x[17], y[17];
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>n;
        for(i=0;i<(1<<n);i++){
            dp[i]=-1;
        }
        for(i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }

        for(i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cc[i][j]=0;
                for(int k=0;k<n;k++){
                    if((x[i]-x[j])*(y[k]-y[i])==(x[k]-x[i])*(y[i]-y[j])){
                        cc[i][j]|=(1<<k);
                    }
                }
                // cout<<cc[i][j]<<"\n";
                cc[j][i]=cc[i][j];
            }
        }

        ans = getIt((1<<n)-1);
        cout<<"Case "<<tk<<": "<<ans<<"\n";
    }
}