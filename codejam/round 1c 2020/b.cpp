#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct str
{
    int v;
    int alpha;
};
int cmp(struct str a, struct str b)
{
    return a.v<b.v;
}
int main()
{
    int t,u,dd,v,alpha,i,j,tk;
    int mapi[27],hasmap[27];
    struct str d[10];
    char r[20],m[20];
    freopen("output.txt","w+",stdout);
    scanf("%d",&t);
    tk=0;
    while(t--)
    {
        tk++;
        for(i=0;i<27;i++)
        {
            mapi[i]=10;
            hasmap[i]=0;
        }

        scanf("%d",&u);
        for(i=0;i<10000;i++)
        {
            scanf("%s %s",m,r);
            for(j=0;r[j]!='\0';j++)
            {
                if(!hasmap[r[j]-'A'])
                    hasmap[r[j]-'A']=1;
            }
            if(strlen(m)==strlen(r))
            {
                v=m[0]-'0';
                alpha=r[0]-'A';
                if(strlen(m)>=2 && strlen(r)>=2)
                {
                    if(r[0]==r[1] && m[1]=='0')
                        v--;
                }
                if(mapi[alpha]>v)
                    mapi[alpha]=v;
            }
        }

        for(i=0,j=0;i<26;i++)
        {
            if(hasmap[i])
            {
                d[j].alpha=i;
                d[j].v=(mapi[i]%10);
                j++;
            }
        }

        sort(d,d+10,cmp);
        printf("Case #%d: ",tk);
        for(i=0;i<10;i++)
            printf("%c",d[i].alpha+'A');
        printf("\n");
    }
}
