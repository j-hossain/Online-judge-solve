#include<stdio.h>

typedef struct
{
    int a;
    int b;
}container;

int main()
{
    container con[21],temp;
    int n,m,i,j,cnt,match;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&con[i].a,&con[i].b);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(con[i].b<con[j].b)
            {
                temp=con[i];
                con[i]=con[j];
                con[j]=temp;
            }
        }
    }

    cnt=match=i=0;

    while(cnt<m)
    {
        if(cnt+con[i].a<=m)
        {
            cnt+=con[i].a;
        }
        else
        {
            con[i].a=m-cnt;
            cnt=m;
        }
        match+=(con[i].a*con[i].b);
        i++;
    }
    printf("%d\n",match);
    return 0;
}
