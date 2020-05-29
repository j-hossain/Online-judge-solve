#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

typedef struct
{
    int left;
    int right;
}node;

int main()
{
    int u,v,w,r_cnt,l_cnt;
    int n,i,tk=0,t;
    node nd[101];
    scanf("%d",&t);
    while(tk<t)
    {
        tk++;
        r_cnt=l_cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            nd[i].left=0;
            nd[i].right=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(!nd[u].right && !nd[v].left)
            {
                nd[u].right=nd[v].left=1;
                r_cnt+=w;
            }
            else
            {
                nd[u].left=nd[v].right=1;
                l_cnt+=w;
            }
            //printf("%d %d\n",l_cnt,r_cnt);
        }
        printf("Case %d: %d\n",tk,(r_cnt<l_cnt)?r_cnt:l_cnt);
    }
    return 0;
}

