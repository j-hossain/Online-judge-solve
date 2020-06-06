#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> con[10005];
int vis[10005];

int cntt(int u)
{
    vis[u]=1;

    if(con[u].size()==0)
        return 0;

    int cnt=0;
    for(int i=0 ; i<con[u].size();i++)
    {
        if(!vis[con[u][i]])
            cnt+=(cntt(con[u][i])+1);
    }
    return cnt;
}

int main()
{
    int i,cnt,n,u,v,x,t,flag;

    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%d %d",&n,&x);

        for(i=0;i<=n;i++)
        {
            con[i].clear();
            vis[i]=0;
        }

        for(i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            con[u].push_back(v);
            con[v].push_back(u);
        }

        if(con[x].size()<=1)
        {
            printf("Ayush\n");
            continue;
        }

        vis[x]=1;
        cnt=0;
        for(i=0;i<con[x].size();i++)
        {
            cnt+=cntt(con[x][i]);
        }
        if(cnt%2)
            flag=0;

        cnt=con[x].size()-1;

        if(cnt%2)
            flag=flag^1;

        if(flag)
            printf("Ayush\n");
        else
            printf("Ashish\n");
    }
    return 0;
}
