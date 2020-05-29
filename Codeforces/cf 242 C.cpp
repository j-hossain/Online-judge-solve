#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>

#define li long long int
#define pr pair<li,li>

using namespace std;

int X[]={1,1,1,0,0,-1,-1,-1};
int Y[]={1,0,-1,1,-1,-1,1,0};

map<pr,li>grid;
map<pr,li>vis;
map<pr,li>dis;

void mybfs(pr u)
{
    li x,y,t,tt;
    pr p;
    queue<pr>que;
    que.push(u);
    dis[u]=0;
    while(!que.empty())
    {
        //printf("working\n");
        u=que.front();
        vis[u]=1;
        que.pop();
        t=u.first;
        tt=u.second;
        for(int i=0;i<8;i++)
        {
            x=t+X[i];
            y=tt+Y[i];
            p = {x,y};
            //printf("%lld %lld %lld\n",p.first,p.second,grid[p]);
            if(grid[p] && !vis[p])
            {
                //printf("work\n");
                que.push(p);
                vis[p]=1;
                dis[p]=dis[u]+1;
            }
        }
    }
}
int main()
{
    li x1,x2,y1,y2,a,b,r,n,i,j;
    pr p;
    scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&r,&a,&b);
        for(j=a;j<=b;j++)
        {
            p={r,j};
            grid[p]=1;
        }
    }
    p={x1,y1};
    mybfs(p);

    p={x2,y2};
    if(dis[p])
        printf("%lld\n",dis[p]);
    else
        printf("-1\n");
    return 0;
}

