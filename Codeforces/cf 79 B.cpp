#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct
{
    int r;
    int c;
}cord;

int cmp(cord a, cord b)
{
    if(a.r<b.r)
        return 1;
    if(a.r==b.r)
        return a.c<b.c;
    return 0;
}

int main()
{
    int row,column,nd,nq,i,cnt,dm;
    int x,y;
    cord damaged[1005];

    scanf("%d %d %d %d",&row,&column,&nd,&nq);

    for(i=0;i<nd;i++)
    {
        scanf("%d %d",&damaged[i].r,&damaged[i].c);
    }

    sort(damaged,damaged+nd,cmp);

    while(nq--)
    {
        dm=0;

        scanf("%d %d",&x,&y);
        for(i=0;i<nd;i++)
        {
            if((damaged[i].r>x)||(damaged[i].r==x && damaged[i].c>y))
                break;
            else if(damaged[i].r==x && damaged[i].c==y)
            {
                dm=1;
                break;
            }
        }
        if(dm)
        {
            printf("Waste\n");
            continue;
        }
        else
        {
            cnt=(x-1)*column+y;
            cnt=cnt-i;
            cnt=cnt%3;

            if(cnt==1)
                printf("Carrots\n");
            else if(cnt==2)
                printf("Kiwis\n");
            else
                printf("Grapes\n");
        }
    }
    return 0;
}
