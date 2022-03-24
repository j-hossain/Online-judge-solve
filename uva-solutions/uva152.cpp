#include<stdio.h>
#include<math.h>

typedef struct
{
    int x;
    int y;
    int z;
    int mnd; //minimum distance
}cord;

int distance(cord a,cord b)
{
    a.x-=b.x;
    a.y-=b.y;
    a.z-=b.z;
    a.x*=a.x;
    a.y*=a.y;
    a.z*=a.z;
    return sqrt(a.x+a.y+a.z);
}

int main()
{
    cord point[5001];
    int x,y,z,print[10];
    int dis,n,i;
    for(i=0;i<10;i++)
        print[i]=0;
    i=0;
    while(1)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(!x && !y && !z)
            break;
        point[i].x=x;
        point[i].y=y;
        point[i].z=z;
        point[i].mnd=300;
        i++;
    }
    n=i;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                dis=distance(point[i],point[j]);
                if(dis<point[i].mnd)
                    point[i].mnd=dis;
                    //printf("%d\n",point[i].mnd);
            }
        }
        if(point[i].mnd<10)
            print[point[i].mnd]++;
    }
    for(i=0;i<10;i++)
        printf("%4d",print[i]);
    printf("\n");
    return 0;
}
