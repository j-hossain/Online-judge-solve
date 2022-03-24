#include<stdio.h>

typedef struct axis
{
    int x;
    int y;
}cord;

cord start,done;
int X[]={-2,-2,-1,-1,1,1,2,2};
int Y[]={-1,1,-2,2,-2,2,-1,1};

int board[9][9];
int dis[9][9];

void mybfs()
{
    int f,r,i;
    cord temp,u,que[10000];
    f=r=0;
    dis[start.y][start.x]=0;
    board[start.y][start.x]=1;
    que[r++]=start;
    while(f<=r)
    {
        u=que[f++];
        for(i=0;i<8;i++)
        {
            temp.x=u.x+X[i];
            temp.y=u.y+Y[i];
            if(temp.x>0 && temp.x<9 && temp.y>0 && temp.y<9 )
            {
                if(!board[temp.y][temp.x])
                {
                    que[r++]=temp;
                    dis[temp.y][temp.x]=dis[u.y][u.x]+1;
                    board[temp.y][temp.x]=1;
                    if(temp.x==done.x && temp.y==done.y)
                        return;
                }
            }
        }
    }
}

int main()
{
    char sq1[3],sq2[3];
    int i,j;
    while(scanf("%s %s",sq1,sq2)!=EOF)
    {
        for(i=1;i<9;i++)
        {
            for(j=1;j<9;j++)
            {
                board[i][j]=0;
                dis[i][j]=0;
            }

        }
        start.x=sq1[0]-'a'+1;
        start.y=sq1[1]-'0';
        done.x=sq2[0]-'a'+1;
        done.y=sq2[1]-'0';
        mybfs();
        printf("To get from %s to %s takes %d knight moves.\n",sq1,sq2,dis[done.y][done.x]);
    }
    return 0;
}
