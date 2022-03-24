#include<stdio.h>
#include<string.h>

int check(char g[3][4], char t)
{
    int i,j;

    for(i=0;i<3;i++)
    {
        if(g[i][0]==t && g[i][1]==t && g[i][2]==t)
            return 1;
        else if(g[0][i]==t && g[1][i]==t && g[2][i]==t)
            return 1;
    }
    if(g[0][0]==t && g[1][1]==t && g[2][2]==t)
        return 1;
    if(g[0][2]==t && g[1][1]==t && g[2][0]==t)
        return 1;

    return 0;
}

int main()
{
    char grid[3][4],temp[4],inp[10];
    int cnt1,cnt2,cnt3,n,i,j,dif,flag;

    scanf("%d",&n);
    while(n--)
    {
        cnt1=cnt2=cnt3=0;

        scanf("%s",inp);
        if(!strcmp(inp,"end"))
            break;

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                grid[i][j]=inp[3*i+j];
            }
        }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(grid[i][j]=='X')
                    cnt1++;
                else if(grid[i][j]=='O')
                    cnt2++;
                else if(grid[i][j]=='.')
                    cnt3++;
            }
        }
        dif=cnt1-cnt2;
        flag=0;


        if(dif==1)
        {
            if(check(grid,'X') && !check(grid,'O'))
                flag=1;
            else if(!check(grid,'O') && !check(grid,'X') && cnt3==0)
                flag=1;
        }
        else if(dif==0)
        {
            if(check(grid,'O') && !check(grid,'X'))
                flag=1;
        }

        if(flag)
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
