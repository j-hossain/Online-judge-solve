#include<stdio.h>
int main()
{
    int i,j,t;
    char sd[10][10];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<9;i++)
            scanf("%s",sd[i]);
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(sd[i][j]=='2')
                    sd[i][j]='1';
            }
        }
        for(i=0;i<9;i++)
            printf("%s\n",sd[i]);
    }
    return 0;
}
