#include<stdio.h>
#include<ctype.h>
#include<math.h>

typedef struct
{
    int x;
    int y;
    int exist;
    double dis;
}key;

double dis(key pos,key *shifts,int n)
{
    double mn=0;
    double d;
    for(int i=0;i<n;i++)
    {
        d=pow(shifts[i].x-pos.x,2)+pow(shifts[i].y-pos.y,2);
        d=sqrt(d);
        if(d<mn || mn==0)
        {
            mn=d;
        }
    }
    return mn;
}

int main()
{
    key mapi[1000];
    key shifts[10000];
    int row,col,mx,lenght,i,flag,j,temp,scnt,tcnt;
    double d;
    char board[35][35],inp[500005];
    for(i=0;i<1000;i++)
    {
        mapi[i].exist=0;
        mapi[i].dis=0;
    }

    scnt=0;
    tcnt=0;
    flag=1;
    scanf("%d %d %d",&row,&col,&mx);

    for(i=0;i<row;i++)
    {
        scanf("%s",board[i]);
    }

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]=='S')
            {
                shifts[scnt].x=j+1;
                shifts[scnt++].y=i+1;
            }
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]=='S')
                continue;

            temp = board[i][j];
            mapi[temp].exist=1;
            mapi[temp].x=j+1;
            mapi[temp].y=i+1;

            d=dis(mapi[temp],shifts,scnt);

            if(!mapi[temp].dis || d<mapi[temp].dis)
            {
                    mapi[temp].dis=d;
            }
        }
    }
    scanf("%d",&lenght);
    scanf("%s",inp);

    for(i=0;i<lenght;i++)
    {
        temp = inp[i];

        if(isupper(inp[i]))
        {
            inp[i]=tolower(inp[i]);
            temp = inp[i];
            if(mapi[temp].exist && scnt>0)
            {
                if(mapi[temp].dis>mx)
                    tcnt++;
            }
            else
            {
                flag=0;
                break;
            }
        }
        else if(!mapi[temp].exist)
        {
            flag=0;
            break;
        }
    }

    if(flag)
        printf("%d\n",tcnt);
    else
        printf("-1\n");
    return 0;
}
