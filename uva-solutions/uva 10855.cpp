#include<stdio.h>

int sn,bn;
char sm[4][100][100],big[100][100];

void rotata(int a, int b)
{
    int r,c;
    for(r=0;r<sn;r++)
        for(c=0;c<sn;c++)
            sm[b][c][sn-r-1]=sm[a][r][c];
}

int match(int r,int c,int k)
{
    int i,j,flag=0;
    for(i=0;i<sn;i++)
    {
        for(j=0;j<sn;j++)
        {
            if(sm[k][i][j]!=big[r+i][c+j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }

    if(flag)
        return 0;
    return 1;
}

int main()
{
    int i,j,k,cnt[4];

    while(scanf("%d %d",&bn,&sn) && bn && sn)
    {
        for(i=0;i<bn;i++)
            scanf("%s",big[i]);
        for(i=0;i<sn;i++)
            scanf("%s",sm[0][i]);

        for(i=0;i<3;i++)
            rotata(i,i+1);

        for(i=0;i<4;i++)
            cnt[i]=0;

        for(i=0;i<=bn-sn;i++)
        {
            for(j=0;j<=bn-sn;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(match(i,j,k))
                        cnt[k]++;
                }
            }
        }

        printf("%d",cnt[0]);
        for(i=1;i<4;i++)
            printf(" %d",cnt[i]);
        printf("\n");
    }
    return 0;
}
