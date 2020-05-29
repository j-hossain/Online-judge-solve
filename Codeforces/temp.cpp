#include<bits/stdc++.h>
using namespace std;
typedef		long long       ll;
typedef		vector<ll>      vll;
#define		pb              push_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		ss              ' '
#define     pii             pair<ll,ll>
const double eps = 1e-8;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1, 0} ;
int dy[] = {1,-1, 0, 0, -1, 1, -1, 1, 0} ;

map<pii,ll>edges;
map<pii,ll>vis;
map<pii,ll>dis;

void bfs(pii &u)
{
    queue<pii>q;
    q.push(u);
    dis[u]=0;
    while(!q.empty())
    {
        u = q.front();
        vis[u]=1;
        q.pop();
        ll i,j;
        i=u.first;
        j=u.second;
        for(ll k=0; k<8; ++k)
        {
            ll x,y;
            x=i+dx[k];
            y=j+dy[k];
            pii p= {x,y};
            if(edges[p]&&!vis[p])
            {
                q.push(p);
                vis[p]=1;
                dis[p]=dis[u]+1;
            }


        }

    }
}


int main()
{

//     ios::sync_with_stdio(0);
//	cin.tie(0);

    ll x1,x2,y1,y2,n;
    pii p;
    cin>>x1>>y1>>x2>>y2>>n;
    for(ll i=0; i<n; ++i)
    {
        ll a,b,r;
        cin>>r>>a>>b;
        for(ll j=a; j<=b; ++j)
        {
            p= {r,j};
            edges[p]=1;
        }
    }
    p= {x1,y1};
    bfs(p);

    if(dis[ {x2,y2}])
    {
        cout<<dis[ {x2,y2}]<<nn;
    }
    else
        cout<<-1<<nn;






}

