#include<bits/stdc++.h>
using namespace std;

//typedef long long int ll;

int m,n,i,u,v;
vector<int>adj[200020];
int dir[200020];
int edge[200020];
int possible;

void mydfs(int u, int d)
{
    dir[u]=d;
    for(auto i=adj[u].begin();i!=adj[u].end();i++)
    {
        v=*i;
        //printf("%d %d %d\n",u,v,i);
        if(dir[v]==-1)
        {
            if(dir[u])
                mydfs(v,0);
            else
                mydfs(v,1);
        }
        else if(dir[u]==dir[v])
        {
            possible=0;
            return;
        }

    }
}

int main()
{
    for(i=0;i<200020;i++)
        dir[i]=-1;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i]=u;
    }
    possible=1;
    mydfs(1,0);
    if(!possible)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(i=0;i<n;i++)
        printf("%d",dir[edge[i]]);
    printf("\n");
    return 0;
}
