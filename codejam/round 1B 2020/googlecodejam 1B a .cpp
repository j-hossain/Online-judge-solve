#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>

using namespace std;

int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
char d[]={'E','N','W','S'};

int ex,ey;
vector<char>dir;
int mx=1000000000;
int mn=-1000000000;

int go(int sx,int sy,int p)
{
    //printf("%d %d %d\n",sx,sy,p);
    int tx,ty,i;
    if(sx==ex && sy==ey)
    {
        //printf("%d\n",p);
        return p;
    }

    if(p>=8 || sx<mn || sx>mx || sy<mn || sy>mx)
        return 0;
    for(i=0;i<4;i++)
    {
        tx=sx+(X[i]*pow(2,p));
        ty=sy+(Y[i]*pow(2,p));
        if(go(tx,ty,p+1))
        {
            //printf("%d %d %d\n",tx,ty,p);
            dir.push_back(d[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t,tk,i,ret;
    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        dir.clear();
        tk++;
        scanf("%d %d",&ex,&ey);
        ret=go(0,0,0);
        printf("Case #%d: ",tk);
        if(ret)
            for(i=dir.size()-1;i>=0;i--)
                printf("%c",dir[i]);
        else
            printf("IMPOSSIBLE");
        printf("\n");
    }
}
