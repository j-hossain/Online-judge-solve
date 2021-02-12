#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int grp[500005],grpCnt[500005],vis[500005];
vector<int> adjmat[500005];

int callBfs(int s, int g){
    queue<int> qq;
    int u,v,i,cnt=0;
    qq.push(s);

    while(!qq.empty()){
        u=qq.front();
        qq.pop();
        if(!vis[u]){
            vis[u]=1;
            cnt++;
            grp[u]=g;
            for(i=0;i<adjmat[u].size();i++){
                v=adjmat[u][i];
                if(!vis[v])
                    qq.push(v);
            }
        }
    }

    return cnt;
}

int main(){
    inout();
    int i,j,m,n,k,prev,now,gCnt,eachCnt;
    cin>>n>>m;
    gCnt=0;
    for(i=0;i<m;i++){
        cin>>k;
        if(k>0){
            cin>>prev;
        }

        for(j=1;j<k;j++){
            cin>>now;
            adjmat[prev].push_back(now);
            adjmat[now].push_back(prev);
            prev=now;
        }
    }

    for(i=1;i<=n;i++){
        if(!vis[i]){
            eachCnt = callBfs(i,gCnt);
            grpCnt[gCnt++]=eachCnt;
        }
    }

    for(i=1;i<=n;i++){
        cout<<grpCnt[grp[i]]<<" ";
    }
    cout<<"\n";
    return 0;
}