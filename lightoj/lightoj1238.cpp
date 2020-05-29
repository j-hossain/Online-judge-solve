#include<stdio.h>

typedef struct
{
    int x;
    int y;
}cord;

char adj[21][21];
int visited[21][21];
int dis[21][21];
int row,column;

int X[]={0,0,1,-1};
int Y[]={-1,1,0,0};

void mybfs(cord source)
{
    int f,r,i;
    cord que[21*21];
    cord temp,u;
    f=r=0;
    que[r++]=source;
    visited[source.y][source.x]=1;
    dis[source.y][source.x]=0;
    while(f<r)
    {
        u=que[f++];
        for(i=0;i<4;i++)
        {
            temp.x=u.x+X[i];
            temp.y=u.y+Y[i];
            if(temp.x>=0 && temp.x<column && temp.y>=0 && temp.y<row)
            {
                if(!visited[temp.y][temp.x] && adj[temp.y][temp.x]!='#' && adj[temp.y][temp.x]!='m')
                {
                    que[r++]=temp;
                    visited[temp.y][temp.x]=1;
                    dis[temp.y][temp.x]=1+dis[u.y][u.x];
                }
            }
        }
    }
}

int main()
{
    int t,tk=0,mx,i,j,p1,p2,p3;
    cord a,b,c,h;
    scanf("%d",&t);
    while(tk<t)
    {
        tk++;
        scanf("%d %d",&row,&column);
        for(i=0;i<row;i++)
        {
            scanf("%s",adj[i]);
            for(j=0;j<column;j++)
            {
                if(adj[i][j]=='h')
                {
                    h.y=i;
                    h.x=j;
                }
                else if(adj[i][j]=='a')
                {
                    a.y=i;
                    a.x=j;
                }
                else if(adj[i][j]=='b')
                {
                    b.y=i;
                    b.x=j;
                }
                else if(adj[i][j]=='c')
                {
                    c.y=i;
                    c.x=j;
                }
                visited[i][j]=0;
                dis[i][j]=0;
            }
        }
        mybfs(h);

        p1=dis[a.y][a.x];
        p2=dis[b.y][b.x];
        p3=dis[c.y][c.x];

        p1=(p1>p2)?p1:p2;
        p1=(p1>p3)?p1:p3;

        printf("Case %d: %d\n",tk,p1);
    }
    return 0;
}
