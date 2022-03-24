#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct
{
    int t;
    int node;
}trp;

int visited[100005];
vector<int>adj[100005];
trp f[100005];

void trpdfs(int u, int &time)
{
    int v,i;
    visited[u]=1;
    time+=1;
    for(i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(!visited[v])
            trpdfs(v,time);
    }
    time+=1;
    f[u].t=time;
    f[u].node=u;
}

bool comp(trp a, trp b)
{
    return a.t<b.t;
}
int main()
{
    int n,c,e,u,v;
    int p[100005];
    memset(visited,0,100005);
    //memset(f,0,100005);
    int time=0;
    scanf("%d %d",&n,&e);
    for(v=1;v<=e;v++)
    {
        scanf("%d",&c);
        while(c--)
        {
            scanf("%d",&u);
            adj[u].push_back(v);
        }
    }
    for(u=1;u<=n;u++)
    {
        if(!visited[u])
        {
            trpdfs(u,time);
        }
    }
    sort(f,f+n,comp);
    v=0;
    for(u=1;u<=n;u++)
    {
        p[f[u].node]=v;
        v=f[u].node;
    }
    for(u=1;u<=n;u++)
        printf("%d ",p[u]);
    printf("\n");
    return 0;
}
