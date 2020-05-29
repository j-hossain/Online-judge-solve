#include<stdio.h>
#include<string.h>

typedef struct
{
    int x;
    int y;
}cord;

int X[]={0,-1,1};
int Y[]={-1,0,0};

int i,t,row,column;
char path[9][9],dir[3][6]={"forth", "left", "right"},word[8]="IEHOVA#",go[8][6];
cord start,ennd;

void mydfs(cord u,int x)
{
    if(x==8)
        return ;
    cord temp;
    for(i=0;i<3;i++)
    {
        temp.x=u.x+X[i];
        temp.y=u.y+Y[i];
        if(temp.x>=0 && temp.x<column && temp.y>=0)
        {
            if(path[temp.y][temp.x]==word[x])
            {
                //printf("working\n");
                strcpy(go[x],dir[i]);
                //printf("%s\n",go[x]);
                mydfs(temp,x+1);
            }
        }
    }
}

int main()
{

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&row,&column);
        for(i=0;i<row;i++)
            scanf("%s",path[i]);
        for(i=0;i<column;i++)
        {
            if(path[row-1][i]=='@')
            {
                start.x=i;
                start.y=row-1;
                break;
            }
        }
        for(i=0;i<column;i++)
        {
            if(path[0][i]=='@')
            {
                start.x=i;
                start.y=0;
                break;
            }
        }

        mydfs(start,0);
        for(i=0;i<7;i++)
        {
            if(i>=1)
                printf(" ");
            printf("%s",go[i]);
        }

        printf("\n");
    }
    return 0;
}
