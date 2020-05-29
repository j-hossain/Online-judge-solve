#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct time
{
    int s;
    int e;
    int p;
};

bool cmp(struct time a,struct time b)
{
    return a.s<b.s;
}

int main()
{
    int t,tk,n,i,flag;
    struct time tm[1001],c,j;
    char name[1001];
    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        tk++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&tm[i].s,&tm[i].e);
            tm[i].p=i;
        }
        sort(tm,tm+n,cmp);
        c.s=c.e=j.s=j.e=0;
        flag=0;
        for(i=0;i<n;i++)
        {
            if(c.e<=tm[i].s)
            {
                c.s=tm[i].s;
                c.e=tm[i].e;
                name[tm[i].p]='C';
            }
            else if(j.e<=tm[i].s)
            {
                j.s=tm[i].s;
                j.e=tm[i].e;
                name[tm[i].p]='J';
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            name[n]='\0';
            printf("Case #%d: %s\n",tk,name);
        }
        else
            printf("Case #%d: IMPOSSIBLE\n",tk);
    }
    return 0;
}
