#include<stdio.h>
#include<string.h>

int main()
{
    char st[51][101];
    int n,lenght,tk,mxl,flag,t;
    int i,j,k,cnt,index;

    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        tk++;
        mxl=0;
        index=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",st[i]);
            lenght=strlen(st[i]);
            if(lenght>mxl)
            {
                mxl=lenght;
                index=i;
            }
        }
        flag=0;
        for(i=0;i<n;i++)
        {
            lenght=strlen(st[i]);
            for(j=lenght-1,k=mxl-1;j>0;j--,k--)
            {
                if(st[i][j]!=st[index][k])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
        {
            printf("Case #%d: ",tk);
            for(i=1;i<mxl;i++)
                printf("%c",st[index][i]);
            printf("\n");
        }
        else
            printf("Case #%d: *\n",tk);
    }
    return 0;
}

