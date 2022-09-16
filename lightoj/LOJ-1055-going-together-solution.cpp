#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int n;
char grph[15][15];
int vis[3][15][15];
int dis[3][15][15];

//direction array
int di[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dj[]= { 0, 0,-1, 1, -1, 1, -1, 1};

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main(){
    inout();
    int t;
    cin>>t;
    pair<int,int>u[3];
    int ii[3],jj[3];
    pair<int,int>v[3];
    pair<int,int>temp;
    queue<pair<int,int>> qq[3];
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>grph[i];
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    vis[i][j][k]=0;
                    dis[i][j][k]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grph[i][j]=='A' or grph[i][j]=='B' or grph[i][j]=='C'){
                    qq[grph[i][j]-'A'].push({i,j});
                }
            }
        }
        for(int i=0;i<3;i++){
            u[i] = qq[i].front();
            dis[i][u[i].first][u[i].second]=0;
            // cout<<u[i].first<<" "<<u[i].second<<"\n";
        }
        int ans=-1;
        while(!qq[0].empty() or !qq[1].empty() or !qq[2].empty()){
            int cnt=0;
            for(int i=0;i<3;i++){
                if(!qq[i].empty()){
                    u[i] = qq[i].front();
                    qq[i].pop();
                    vis[i][u[i].first][u[i].second]=1;
                }
                if(grph[u[i].first][u[i].second]=='X')cnt++;
            }
            if(cnt==3){
                ans=max(dis[0][u[0].first][u[1].second],max(dis[1][u[1].first][u[1].second],dis[2][u[2].first][u[2].second]));
                break;
            }
            for(int i=0;i<4;i++){
                for(int j=0;j<3;j++){
                    ii[j] = di[i]+u[j].first;
                    jj[j] = dj[i]+u[j].second;
                    temp = {ii[j],jj[j]};
                    if(ii[j]>=0 and ii[j]<n and jj[j]>=0 and jj[j]<n and u[0]!=temp and u[1]!=temp and u[2]!=temp){
                        if((grph[ii[j]][jj[j]]=='.' or grph[ii[j]][jj[j]]=='X') and !vis[j][ii[j]][jj[j]]){
                            v[j] = {ii[j],jj[j]};
                            // vis[j][v[j].first][v[j].second]=1;
                            
                        }
                        else{
                            cout<<j<<"\n";
                            v[j]=u[j];
                        }
                    }
                    else{
                        v[j]=u[j];
                    }
                }
                cout<<v[0].first<<" "<<v[0].second<<"\n";
                cout<<v[1].first<<" "<<v[1].second<<"\n";
                cout<<v[2].first<<" "<<v[2].second<<"\n";
                cout<<"\n";
                if(v[0]!=u[0] or v[1]!=u[1] or v[2]!=u[2]){
                    qq[0].push(v[0]);
                    qq[1].push(v[1]);
                    qq[2].push(v[2]);
                    dis[0][v[0].first][v[0].second]=dis[0][u[0].first][u[0].second]+1;
                    dis[1][v[1].first][v[1].second]=dis[1][u[1].first][u[1].second]+1;
                    dis[2][v[2].first][v[2].second]=dis[2][u[2].first][u[2].second]+1;
                }
            }
        }
        for(int i=0;i<3;i++){
            while(!qq[i].empty())
                qq[i].pop();
        }
        cout<<"Case "<<tc<<": ";
        if(ans!=-1)
            cout<<ans<<"\n";
        else{
            cout<<"trapped\n";
        }
    }
}