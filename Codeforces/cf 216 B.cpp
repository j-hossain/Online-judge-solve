#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

vector<int>adj[102];
int visited[102];
int team[102];
int cnt;

void mydfs(int u,int t)
{
    int v,i;
    team[u]=t;
    visited[u]=1;
    for(i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(team[v]==-1 && !visited[v])
        {
            mydfs(v,t^1);
        }
        else if(team[u]==team[v])
        {
            //printf("%d %d\n",u,v);
            team[u]=-1;
            cnt++;
            //return;
        }
    }
}
int main()
{
    int n,i,e,u,v;
    scanf("%d %d",&n,&e);
    cnt=0;
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
        team[i]=-1;
    }
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
            mydfs(i,0);
    }
    n-=cnt;
    if(n%2)
        cnt++;
    printf("%d\n",cnt);
    return 0;
}
