#include<iostream>
using namespace std;

int grph[105][105],dis[105],taken[105];

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int findMin(int n){
    int mx = INT32_MAX;
    int ret;
    for(int i=0;i<n;i++){
        if(!taken[i] && dis[i]<mx){
            mx = dis[i];
            ret = i;
        }
    }
    return ret;
}

int main(){
    inout();
    int t, n,m, u,v,w,x;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            dis[i] = INT32_MAX;
            taken[i] = 0;
            for(int j=0;j<n;j++)
                grph[i][j]=-1;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            u--;
            v--;
            if(grph[u][v]==-1 || grph[u][v]>w){
                grph[u][v]=w;
                grph[v][u]=w;
            }
        }
        dis[0]=0;
        for(int i=0;i<n;i++){
            u = findMin(n);
            taken[u] = 1;
            for(v=0;v<n;v++){
                if(grph[u][v]!=-1 && dis[u]+grph[u][v]<dis[v]){
                    dis[v] = dis[u]+grph[u][v];
                }
            }
        }
        cout<<"Case "<<tt<<": ";
        if(dis[n-1]==INT32_MAX)
            cout<<"Impossible\n";
        else
            cout<<dis[n-1]<<"\n";
    }
}