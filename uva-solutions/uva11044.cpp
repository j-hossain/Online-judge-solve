#include<stdio.h>
int main()
{
    int row,column,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&row,&column);
        row-=2;
        column-=2;
        if(row%3!=0)
            row+=(3-row%3);
        if(column%3!=0)
            column+=(3-column%3);
        row=row/3;
        column=column/3;
        printf("%d\n",row*column);
    }
    return 0;
}
