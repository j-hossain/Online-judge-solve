#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
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

int hv[105],dp[105][105],k,n;

int getIt(int i, int x){
    if(x==k || i>n)
        return 0;

    if(dp[i][x]!=-1)
        return dp[i][x];
    
    return dp[i][x]=max(getIt(i+1,x),(hv[i]-i+1)+getIt(hv[i]+1,x+1));
}

int main(){
    inout();
    int w,x,y[105],ans,t;
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>n>>w>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        for(int i=1;i<=n;i++){
            cin>>x>>y[i];
        }
        sort(y+1,y+n+1);
        
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(abs(y[j]-y[i])<=w)
                    hv[i]=j;
                else{
                    break;
                }
            }
        }

        cout<<"Case "<<tk<<": "<<getIt(1,0)<<"\n";
    }
}