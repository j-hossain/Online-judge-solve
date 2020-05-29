#include<stdio.h>

int X[]={-1,0,1,0};
int Y[]={0,-1,0,1};

int main()
{
    char adj[101][101],pr[2],vis[27],te;
    int cnt,row,column,i,j,d,x,y;

    for(i=0;i<26;i++)
        vis[i]=0;
    cnt=0;

    scanf("%d %d %s",&row,&column,pr);
    for(i=0;i<row;i++)
        scanf("%s",adj[i]);
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(adj[i][j]==pr[0])
            {
                if(!vis[pr[0]-'A'])
                    vis[pr[0]-'A']=1;
                for(d=0;d<4;d++)
                {
                    x=j+X[d];
                    y=i+Y[d];
                    if(x>=0 && x<column && y>=0 && y<row && adj[y][x]!='.')
                    {
                        te=adj[y][x];
                        if(!vis[te-'A'])
                        {
                            vis[te-'A']=1;
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n",cnt);
}
