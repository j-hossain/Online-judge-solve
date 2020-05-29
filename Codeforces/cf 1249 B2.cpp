#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int visited[200001];
int cnt[200001];
int books[200001];
int c;

void mydfs(int u)
{
    int v;
    visited[u]=1;
    c++;
    v=books[u];
    if(u==v || visited[v])
    {
        cnt[u]=c;
        return;
    }
    else if(!visited[v])
    {
        mydfs(v);
        cnt[u]=c;
    }
}

int main()
{
    int t,n,i,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&books[i]);
            books[i]--;
            visited[i]=0;
            cnt[i]=0;
        }
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                c=0;
                mydfs(i);
            }
        }
        for(i=0;i<n;i++)
            printf("%d ",cnt[i]);
        printf("\n");
    }
    return 0;
}

