#include<stdio.h>
char grid[105][105];
int r,c;

int X[]={1,1,1,0,0,-1,-1,-1};
int Y[]={1,0,-1,1,-1,1,0,-1};

void mydfs(int i,int j)
{
    int x,ti,tj;

    for(x=0;x<8;x++)
    {
        ti=i+X[x];
        tj=j+Y[x];

        if(ti<r && ti>=0 && tj<c && tj>=0)
        {
            if(grid[ti][tj]=='@')
                {
                    grid[ti][tj]='*';
                    mydfs(ti,tj);
                }
        }
    }
}

int main(){

    int i,j,cnt;
    //freopen("uvaOut.txt","w+",stdout);
    while(1){
        scanf("%d %d",&r,&c);
        if(!r && !c)
            break;

        for(i=0;i<r;i++)
            scanf("%s",grid[i]);
        cnt=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]=='@')
                {
                    grid[i][j]='*';
                    mydfs(i,j);
                    cnt++;
                }
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
