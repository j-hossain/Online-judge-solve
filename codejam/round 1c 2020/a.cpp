#include<stdio.h>

int dir(char d)
{
    if(d=='N')
        return 0;
    if(d=='W')
        return 1;
    if(d=='S')
        return 2;
    if(d=='E')
        return 3;
}

int dif(int a,int b)
{
    return a>b?(a-b):(b-a);
}

int dis(int a,int b)
{
    return dif(a,0)+dif(b,0);
}

int X[]={0,-1,0,1};
int Y[]={1,0,-1,0};


int main()
{
    int x,y,t,tk,i,d,dif,mn;
    char path[10005];
    scanf("%d",&t);
    tk=0;
    while(t--)
    {
        tk++;
        mn=1000000;
        scanf("%d %d",&x,&y);
        scanf("%s",path);
        for(i=0;path[i]!='\0';i++)
        {
            if(x==0 && y==0)
            {
                mn=0;
                break;
            }
            d=dir(path[i]);
            x+=X[d];
            y+=Y[d];
            dif=dis(x,y);
            if(dif<=(i+1))
            {
                mn=i+1;
                break;
            }
        }
        if(mn!=1000000)
        printf("Case #%d: %d\n",tk,mn);
        else
            printf("Case #%d: IMPOSSIBLE\n",tk);
    }
}
