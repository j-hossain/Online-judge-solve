#include<stdio.h>

typedef struct axis
{
    int x;
    int y;
}cord;

int X[]={1,0,0,-1};
int Y[]={0,1,-1,0};

char area[51][51];
int n;
int visited1[51][51],lenght1;
int visited2[51][51],lenght2;
cord land1[2501],land2[2501],point1,point2,u,temp;

int distance(cord a,cord b)
{
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

int main()
{
    int i,j,f,r;
    scanf("%d",&n);
    scanf("%d %d",&point1.y,&point1.x);
    scanf("%d %d",&point2.y,&point2.x);
    for(i=0;i<n;i++)
    {
        scanf("%s",area[i]);
    }
    //running a bfs for land1
    f=r=0;
    land1[r++]=point1;
    visited1[point1.y][point1.x]=1;
    while(f<=r)
    {
        u=land1[f++];
        for(i=0;i<4;i++)
        {
            temp.x=u.x+X[i];
            temp.y=u.y+Y[i];
            if(temp.x>0 && temp.x<=n && temp.y>0 && temp.y<=n)
            {
                if((area[temp.y-1][temp.x-1]=='0') && (!visited1[temp.y][temp.x]))
                {
                    //printf("%d %d\n",temp.x,temp.y);
                    land1[r++]=temp;
                    visited1[temp.y][temp.x]=1;
                }
            }
        }
    }
    lenght1=r;
    f=r=0;
    land2[r++]=point2;
    visited2[point2.y][point2.x]=1;
    while(f<r)
    {
        u=land2[f++];
        for(i=0;i<4;i++)
        {
            temp.x=u.x+X[i];
            temp.y=u.y+Y[i];
            if(temp.x>0 && temp.x<=n && temp.y>0 && temp.y<=n)
            {
                if((area[temp.y-1][temp.x-1]=='0') && (!visited2[temp.y][temp.x]))
                {
                    land2[r++]=temp;
                    visited2[temp.y][temp.x]=1;
                }
            }
        }
    }
    lenght2=r;
    //now claculating the min distance;

    int t,dis=distance(point1,land2[0]);
//    point2=land2[0];
//    for(i=1;i<lenght2;i++)
//    {
//        t=distance(point1,land2[i]);
//        if(t<dis)
//        {
//            point2=land2[i];
//            dis=t;
//        }
//    }
//    for(i=0;i<lenght1;i++)
//    {
//        t=distance(point2,land1[i]);
//        if(t<dis)
//        {
//            dis=t;
//        }
//    }
    for(i=0;i<lenght1;i++)
    {
        for(j=0;j<lenght2;j++)
        {
            t=distance(land1[i],land2[j]);
            if(t<dis)
                dis=t;
        }
    }
    printf("%d\n",dis);
    return 0;
}
