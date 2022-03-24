#include<stdio.h>

typedef struct
{
    int x;
    int y;
}cord;

char image[101][101];

int X[]={1,0,0,-1};
int Y[]={0,1,-1,0};

int n;

void mydfs(cord u)
{
    cord temp;
    image[u.y][u.x]='.';
    for(int i=0;i<4;i++)
    {
        temp.x=u.x+X[i];
        temp.y=u.y+Y[i];
                //printf("%d %d\n",temp.x,temp.y);
        if(temp.x>=0 && temp.x<n && temp.y>=0 && temp.y<n )
        {
            if(image[temp.y][temp.x]=='x' || image[temp.y][temp.x]=='@')
            {
                mydfs(temp);
            }

        }
    }
}

int main()
{
    int t,tk,cnt;
    cord temp;
    tk=0;
    scanf("%d",&t);
    while(tk<t)
    {
        cnt=0;
        tk++;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",image[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]=='x')
                {
                    temp.y=i;
                    temp.x=j;
                    cnt++;
                    mydfs(temp);
                }
            }
        }
        printf("Case %d: %d\n",tk,cnt);
    }
    return 0;
}
