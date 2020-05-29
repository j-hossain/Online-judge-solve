#include<stdio.h>
int main()
{
    int i,n,j,flag,t;
    char grid[55][55];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",grid[i]);

        }
        flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(grid[i][j+1]=='0' && grid[i+1][j]=='0')
                    {
                        flag=1;
                    }
                }
                 if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
