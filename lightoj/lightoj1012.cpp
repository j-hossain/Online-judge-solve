#include<stdio.h>

typedef struct axis
{
    int x;
    int y;
}cord;

char adj[100][100];
int visited[100][100];
int row,column,cnt;

int X[]={0,0,1,-1};
int Y[]={-1,1,0,0};

cord temp;

void mydfs(cord u)
{
    int i;
    cnt++;
    visited[u.y][u.x]=1;
    for(i=0;i<4;i++)
    {
        temp.x=u.x+X[i];
        temp.y=u.y+Y[i];
        if(temp.x>=0 && temp.x<column && temp.y>=0 && temp.y<row)
        {
            if(adj[temp.y][temp.x]=='.' && !visited[temp.y][temp.x])
                mydfs(temp);
        }
    }
}
int main()
{
    int t,tk=0,i,j;
    cord start;
    scanf("%d",&t);
    while(tk<t)
    {
        cnt=0;
        tk++;
        scanf("%d %d",&column,&row);
        for(i=0;i<row;i++)
            scanf("%s",adj[i]);
        for(j=0;j<row;j++)
        {
            for(i=0;i<column;i++)
            {
                visited[j][i]=0;
                if(adj[j][i]=='@')
                {
                    start.x=i;
                    start.y=j;
                }
            }
        }
        mydfs(start);
        printf("Case %d: %d\n",tk,cnt);
    }
    return 0;
}
