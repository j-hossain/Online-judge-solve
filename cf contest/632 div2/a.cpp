#include<stdio.h>
int main()
{
    int mat[101][101],row,column,i,j,c,t,start;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&row,&column);
        c=start=0;
        for(i=0;i<row;i++)
        {
            c=start;
            for(j=0;j<column;j++)
            {
                mat[i][j]=c;
                c=c^1;
            }
            start=start^1;
        }
        if(row%2 && column%2)
        {

        }
        else if(!(row%2) && !(column%2))
        {
            mat[row-1][column-2]=0;
        }
        else
        {
            mat[row-1][column-1]=0;
        }

        for(i=0;i<row;i++)
        {
            c=start;
            for(j=0;j<column;j++)
            {
                if(mat[i][j])
                    printf("W");
                else
                    printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}
