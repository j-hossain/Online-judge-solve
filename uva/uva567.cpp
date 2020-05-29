#include<stdio.h>
int adj[21][21],dis[21],que[21],visit[21],u,v,e,n,ret,rear,fron,j,source,en,t=0,i;

int mybfs()
{
    for(i=1;i<21;i++)
    {
        visit[i]=0;
        dis[i]=0;
    }

    rear=fron=0;
    que[rear++]=source;
    dis[source]=0;
    visit[source]=1;
    while(fron<=rear)
    {
        u=que[fron++];
        for(i=1;i<21;i++)
        {
            if(adj[u][i] && !visit[i])
            {
                //printf("%d\n",i);
                que[rear++]=i;
                dis[i]=dis[u]+1;
                visit[i]=1;
                if(i==en)
                {
                    printf("%2d to %2d: %d\n",source,en,dis[i]);
                    return 0;
                }
            }
        }
    }
}
int main()
{
    while(1)
    {
        for(i=1;i<=20;i++)
        {
            for(j=1;j<21;j++)
                adj[i][j]=0;
                adj[j][i]=0;
        }

        t++;
        for(i=1;i<20;i++)
        {
            ret=scanf("%d",&e);
            //printf("%d\n",e);
            if(ret==EOF)
                return 0;
            while(e--)
            {
                scanf("%d",&v);
                adj[i][v]=1;
                adj[v][i]=1;
            }

        }
        scanf("%d",&n);
        printf("Test Set #%d\n",t);
        while(n--)
        {
            scanf("%d %d",&source,&en);
            mybfs();
        }
        printf("\n");
    }
}

