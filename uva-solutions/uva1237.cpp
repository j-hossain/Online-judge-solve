#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
    int name[21];
    int l;
    int h;
}company;

bool cmp(company a, company b)
{
    return a.l<b.l;
}
int main()
{
    int t,n,q,pr,i,cnt,index;
    company c[10001];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d",c[i].name,&c[i].l,&c[i].h);
        }

        sort(c,c+n,cmp);


//        for(i=0;i<n;i++)
//        {
//            printf("%s %d %d\n",c[i].name,c[i].l,c[i].h);
//        }

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&pr);
            i=cnt=index=0;
            while(c[i].l<=pr && i<n)
            {
                if(c[i].h>=pr)
                {
                    cnt++;
                    index=i;
                }
                i++;
            }

            if(cnt==1)
                printf("%s\n",c[index].name);
            else
            {
                //printf("%d %d\n",cnt,index);
                printf("UNDETERMINED\n");
            }
        }
        if(t>0)
            printf("\n");
    }
    return 0;
}
