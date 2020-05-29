#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int>graph[20002];
int cnt[2];
int visited[20002];
int team[20002];

void mybfs(int s)
{
    int que[20002];
    int f,r,u,i,v;
    f=r=0;
    que[r++]=s;
    visited[s]=1;
    team[s]=0;
    cnt[0]++;
    while(f<r)
    {
        u=que[f++];
        for(i=0;i<graph[u].size();i++)
        {
            v=graph[u][i];
            if(!visited[v])
            {

                que[r++]=v;
                visited[v]=1;
                team[v]=team[u]^1;
                cnt[team[v]]++;
                //printf("uv= %d %d\n",u,v);
                //printf("count= %d %d\n",cnt[0],cnt[1]);
            }
        }
    }
}
int main()
{
    int u,v,e,t,tk,i,mx;
    scanf("%d",&t);
    tk=1;
    while(tk<=t)
    {
        mx=0;
        for(i=0;i<20002;i++)
        {
            visited[i]=0;
            graph[i].clear();
        }

        scanf("%d",&e);
        for(i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
                graph[u].push_back(v);
                graph[v].push_back(u);
        }
        for(i=1;i<20002;i++)
        {
            cnt[0]=cnt[1]=0;
            //printf("%d ",visited[i]);
            //printf("%d\n",team[i]);
            if(!visited[i])
            {
                mybfs(i);
            }

            if(cnt[0] && cnt[1])
            {
                mx+=(cnt[0]>cnt[1]? cnt[0] : cnt[1]);
                //printf("%d\n",mx);
            }

        }
        printf("Case %d: %d\n",tk,mx);
        tk++;
    }
    return 0;
}
