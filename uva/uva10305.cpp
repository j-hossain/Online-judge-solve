#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

vector<int>adj[101];
int visited[101];
vector<int>seq;

void mydfs(int u)
{
    int i,v;
    visited[u]=1;
    for(i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(!visited[v])
        {
            mydfs(v);
        }
    }
            seq.push_back(u);
}
int main()
{
    int n,e,u,v,i;
    while(1)
    {
        scanf("%d %d",&n,&e);

        if(n==0 && e==0)
        {
            break;
        }
        for(i=1;i<=100;i++)
        {
            adj[i].clear();
            visited[i]=0;
        }
        seq.clear();

        for(i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
                mydfs(i);
        }
        for(i=n-1;i>=0;i--)
        {
            printf("%d",seq[i]);
            if(i>0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
