#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

vector<int> adj[30002];
vector<int> weight[30002];
int dis[30002];
int visited[30002];

void mybfs(int source)
{
    int f,r,u,v,w,que[30002],i;
    f=r=0;
    que[r++]=source;
    dis[source]=0;
    visited[source]=1;
    while(f<r)
    {
        u=que[f++];
        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            w=weight[u][i];
            if(!visited[v])
            {
                que[r++]=v;
                dis[v]=w+dis[u];
                visited[v]=1;
                //printf("%d= %d\n",v,dis[v]);
            }
        }
    }
}

int maxim(int n)
{
    int i,index,mx=0;
    for(i=0;i<n;i++)
    {
        if(dis[i]>mx)
        {
            index=i;
            mx=dis[i];
        }
    }
    return index;
}
int main()
{
    int t,tk=0,n,w,v,u,i,mx;
    scanf("%d",&t);
    while(tk<t)
    {
        tk++;
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            visited[i]=0;
            dis[i]=0;
            adj[i].clear();
            weight[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        mybfs(0);
        mx=maxim(n);
        //printf("%d\n",dis[mx]);
        for(i=0;i<=n;i++)
        {
            visited[i]=0;
            dis[i]=0;
        }
        mybfs(mx);
        mx=maxim(n);
        printf("Case %d: %d\n",tk,dis[mx]);
//        for(i=0;i<n;i++)
//            printf("%d ",dis[i]);
//        printf("\n");
    }
}
