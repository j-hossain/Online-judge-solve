#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
//accepted

using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int n,m;
string u,v;
int grph[26][26];
map<string,int> mpos;
map<int, string> mName;
int vis[26];
int grp[26];
int par[26];
int grpCnt;

void concat(int a,int b){
    if(grp[a]==grp[b])
        return;
    for(int i=1;i<=n;i++)
    {
        if(grp[i]==grp[a])
            grp[i]=grp[b];
    }
}

void connect(int u, int v){
    for(int i=1;i<=n;i++){
        if(grph[i][u]){
            grph[i][v]=1;
            if(grph[v][i])
                concat(v,i);
        }
    }
}

void callBfs(int s){
    queue<int> qq;
    int x;
    while(!qq.empty())
        qq.pop();
    qq.push(s);
    vis[s]=1;

    while(!qq.empty()){
        
        x=qq.front();
        qq.pop();
        vis[x]=1;
        for(int i=1;i<=n;i++){
            if(grph[x][i]){
                if(grph[i][x])
                    concat(i,x);
                connect(x,i);
            }
        }
    }
}

int main()
{
    inout();
    int tt=0;
    while(1){
        tt++;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        int cnt=1;
        grpCnt=1;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            grp[i]=i;
            for(int j=1;j<=n;j++)
                grph[i][j]=0;
        }
        if(!mpos.empty())
            mpos.clear();
        if(!mName.empty())
            mName.clear();
        for(int i=0;i<m;i++){
            cin>>u>>v;
            if(mpos[u]==0){
                mName[cnt]=u;
                mpos[u]=cnt++;
            }
            if(mpos[v]==0){
                mName[cnt]=v;
                mpos[v]=cnt++;
            }
            grph[mpos[u]][mpos[v]]=1;
        }

        for(int i=1;i<=n;i++){
            if(!vis[i])
                callBfs(i);   
        }

        // for(int i=1;i<=n;i++)
        //     cout<<grp[i]<<" ";
        // cout<<"\n";
        if(tt>1)
            cout<<"\n";
        cout<<"Calling circles for data set "<<tt<<":\n";
        for(int i=1;i<=n;i++)
            vis[i]=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt=0;
                for(int j=1;j<=n;j++){
                    if(grp[i]==grp[j]){
                        vis[j]=1;
                        if(cnt>0)
                            cout<<", ";
                        cnt++;
                        cout<<mName[j];
                    }
                }
                cout<<"\n";
            }
        }
    }

    return 0;
}