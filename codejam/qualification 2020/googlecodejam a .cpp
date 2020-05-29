#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int adj[102][102],i,j,n,t,sum,cntr,cntc,tk;
    set<int>x;
    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        tk++;
        sum=cntr=cntc=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            x.clear();
            for(j=1;j<=n;j++)
            {
                scanf("%d",&adj[i][j]);
                x.insert(adj[i][j]);
                if(i==j)
                    sum+=adj[i][j];
            }
            if(x.size()<n)
                cntr++;
        }
        for(i=1;i<=n;i++)
        {
            x.clear();
            for(j=1;j<=n;j++)
            {
                x.insert(adj[j][i]);
            }
            if(x.size()<n)
                cntc++;
        }
        printf("Case #%d: %d %d %d\n",tk,sum,cntr,cntc);
    }
    return 0;
}
