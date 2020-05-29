#include<stdio.h>

int X[]={0,1,0,-1};
int Y[]={-1,0,1,0};

int dir(char d)
{
    if(d=='N')
        return 0;
    else if(d=='E')
        return 1;
    else if(d=='S')
        return 2;
    else if(d=='W')
        return 3;
}

int main()
{
    //freopen("uvaOut.txt","w+",stdout);
    char grid[12][12],temp;
    int row,col,start,step,loop,i,j,dx,dy,d;
    int mapi[12][12];
    while(scanf("%d %d %d",&row,&col,&start) && (row || col || start))
    {
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                mapi[i][j] = -1;
        for(i=0;i<row;i++)
        {
            scanf("%s",grid[i]);
        }
        start--;
        mapi[0][start] = 0;
        step = 0;
        loop = 0;
        dy=0;
        dx=start;
        while(1)
        {
            d=dir(grid[dy][dx]);
            dx+=X[d];
            dy+=Y[d];
            step++;
            if(dx<0 || dx>=col || dy<0 || dy>=row)
                break;
            else if(mapi[dy][dx]==-1)
                mapi[dy][dx]=step;
            else
            {
                loop=step-mapi[dy][dx];
                step=mapi[dy][dx];
                break;
            }
        }

        if(loop)
            printf("%d step(s) before a loop of %d step(s)\n",step,loop);
        else
            printf("%d step(s) to exit\n",step);
    }
    return 0;
}
