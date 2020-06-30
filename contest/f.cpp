#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

typedef struct
{
    int x;
    int y;
    int arr[3];
}team;

double dis(int ax,int ay,int bx,int by)
{
    int x=ax>bx?(ax-bx):(bx-ax);
    int y=by>ay?(by-ay):(ay-by);
    x*=x;
    y*=y;
    double ans=x+y;
    ans=sqrt(ans);
    return ans;
}

DN
{
    fast();

    team all[30],temp;
    int vis[30];
    int n,x,y,mi,p,i,j;
    double d,mn;

    for(i=0;i<30;i++)
        vis[i]=0;

    cin>>n>>x>>y;
    for(i=0;i<n;i++)
    {
        cin>>p>>temp.x>>temp.y;
        for(j=0;j<3;j++)
            cin>>temp.arr[j];

        all[p]=temp;
    }
    for(i=1;i<n;i++)
    {
        mn=-1.0;
        for(j=1;j<n;j++)
        {
            if(!vis[j])
            {
                d=dis(all[j].x,all[j].y,x,y);
                if(d<mn || mn==-1)
                {
                    mn=d;
                    mi=j;
                }
            }
        }
        vis[mi]=1;
        x=all[mi].x;
        y=all[mi].y;

        cout<<mi<<" "<<min(all[mi].arr[0],min(all[mi].arr[1],all[mi].arr[2]))<<endl;;

    }


    return 0;
}
