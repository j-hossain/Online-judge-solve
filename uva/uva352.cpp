#include<stdio.h>
#include<string.h>

typedef struct axis
{
    int x,y;
}cord;
int visited[26][26];
char image[26][26];

int X[]={1,1,0,-1,-1,-1,0,1};
int Y[]={0,-1,-1,-1,0,1,1,1};

int lenght;

void mydfs(cord s)
{
    int i;
    cord temp;
    visited[s.x][s.y]=1;
    for(i=0;i<8;i++)
    {
        temp.x=s.x+X[i];
        temp.y=s.y+Y[i];
        if(temp.x>=0 && temp.x<lenght && temp.y>=0 && temp.y<lenght)
        {
            if((!visited[temp.x][temp.y])&& (image[temp.x][temp.y]=='1'))
                {
                    mydfs(temp);
                }
        }
    }
}

int main()
{
    cord temp;
    int i,j,cnt,n=0;
    while(scanf("%d",&lenght)!=EOF)
    {
        cnt=0;
        n++;
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
                visited[i][j]=0;
        }

        for(i=0;i<lenght;i++)
        {
            scanf("%s",image[i]);
        }
        for(i=0;i<lenght;i++)
        {
            for(j=0;j<lenght;j++)
            {
                temp.x=i;
                temp.y=j;
                if((!visited[temp.x][temp.y])&& (image[temp.x][temp.y]=='1'))
                {
                    cnt++;
                    mydfs(temp);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",n,cnt);
    }
    return 0;
}
