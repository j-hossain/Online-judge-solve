#include<stdio.h>
int main()
{
    int row,column,i,j,flag=0;
    char pixel[2];

    scanf("%d %d",&row,&column);
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%s",pixel);
            if(pixel[0]=='C' || pixel[0]=='M' ||pixel[0]=='Y')
                flag=1;
        }
    }
    if(flag)
        printf("#Color\n");
    else
        printf("#Black&White\n");
    return 0;
}
