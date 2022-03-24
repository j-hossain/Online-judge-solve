#include<stdio.h>

typedef struct
{
    int x;
    int y;
}pr;

int main()
{
    int k,x,y,dif,mul,i,total,temp;
    pr pairs[10000];
    while(scanf("%d",&k)!=EOF)
    {
        i=0;
        for(y=k+1;y<=2*k;y++)
        {
            mul=k*y;
            dif=y-k;
            if(mul%dif==0)
            {
                pairs[i].x=mul/dif;
                pairs[i++].y=y;
            }
        }
        total=i;
        printf("%d\n",total);
        for(i=0;i<total;i++)
        {
            printf("1/%d = 1/%d + 1/%d\n",k,pairs[i].x,pairs[i].y);
        }
    }
}
