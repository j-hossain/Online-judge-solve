#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>gph[200005];
long long int sum;
int visited[200005];
int dis[200005];
long long int cnt;

void mydfs(int s,int d)
{
    visited[s]=1;
    int i,v;
    int x=cnt;
    for(i=0;i<gph[s].size();i++)
    {
        v=gph[s][i];
        if(!visited[v])
            mydfs(v,d+1);
    }
    int y=cnt;
    dis[cnt++]=d-(y-x);
}

int main()
{
    int n,i,u,v,k;
    scanf("%d %d",&n,&k);
    sum=0;
    cnt=0;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        gph[u].push_back(v);
        gph[v].push_back(u);
        visited[i]=0;
    }
    visited[n]=0;
    mydfs(1,0);
    sort(&dis[0],&dis[n],greater<int>());
    i=0;
    while(i<n)
    {
        sum+=dis[i];
        k--;
        if(!k)
            break;
        i++;
    }
    printf("%lld\n",sum);
    return 0;
}
