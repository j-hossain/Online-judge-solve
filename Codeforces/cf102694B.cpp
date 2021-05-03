#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//not accepted
vector<int> grph[300005];
int dis[300005];
int mxDis,cor;

void goDfs(int par, int now){
    dis[now] = dis[par]+1;
    if(dis[now]>mxDis){
        mxDis=dis[now];
        cor = now;
    }
    for(int i=0;i<grph[now].size();i++){
        if(grph[now][i]!=par){
            goDfs(now,grph[now][i]);
        }
    }
}

int main(){
    int n,u,v,i,c1,c2;

    cin>>n;
    i=0;
    while(i<n-1){
        cin>>u>>v;
        grph[u].push_back(v);
        grph[v].push_back(u);
        i++;
    }
    mxDis = 0;
    for(i=1;i<=n;i++){
        dis[i]=0;
    }
    dis[0]=-1;
    goDfs(0,1);
    c1 = cor;
    goDfs(0,cor);

    for(int i=1;i<=n;i++){
        if(dis[i]==mxDis || i==c1){
            cout<<(mxDis+1)<<"\n";
        }else
            cout<<mxDis<<"\n";
    }
    return 0;
}