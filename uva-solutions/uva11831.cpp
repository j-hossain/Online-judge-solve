#include<stdio.h>

typedef struct
{
    int x;
    int y;
}cord;

int dir(char a)
{
    if(a=='N')
        return 1;
    else if(a=='L')
        return 2;
    else if(a=='S')
        return 3;
    else
        return 4;
}

int main()
{
    int c_dr,row,column,n_ins,temp,i,j,cnt; //c_dr means current direction
    char ground[101][101],ins[50001];
    cord c_pos,tmp; //c_pos means current position

    int dr[]={4,1,2,3,4,1};
    int in[]={1,-1,0};

    int X[]={-1,0,1,0,-1};
    int Y[]={0,-1,0,1,0};

    while(1)
    {
        cnt=0;
        scanf("%d %d %d",&row,&column,&n_ins);
        if(!row && !column && !n_ins)
        {
            break;
        }
        for(i=0;i<row;i++)
        {
            scanf("%s",ground[i]);
        }
        scanf("%s",ins);

        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(ground[i][j]=='N' ||ground[i][j]=='O' ||ground[i][j]=='L' ||ground[i][j]=='S')
                {
                    c_pos.x=j;
                    c_pos.y=i;
                    c_dr=dir(ground[i][j]);
                    ground[i][j]='.';
                }
            }
        }

        for(i=0;i<n_ins;i++)
        {
            temp=in[ins[i]-'D'];
            if(!temp)
            {
                tmp.x=c_pos.x+X[c_dr];
                tmp.y=c_pos.y+Y[c_dr];
                if(tmp.x>=0 && tmp.y>=0 && tmp.x<column && tmp.y<row)
                {
                    if(ground[tmp.y][tmp.x]!='#')
                    {
                        c_pos=tmp;
                        if(ground[c_pos.y][c_pos.x]=='*')
                        {
                            cnt++;
                            ground[c_pos.y][c_pos.x]='.';
                        }

                    }
                }
            }
            else
            {
                c_dr=dr[c_dr+temp];
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
