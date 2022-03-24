#include<iostream>
#include<vector>
#define mxz         2500 
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

vector<int> adjMat[mxz+1];
int day[mxz+1],vis[mxz+1],dayCnt[3*mxz];

int callBfs(int s, int n,int t){
    int qq[mxz+1];
    int f,r,u,v,i,mxDay;
    f=r=0;
    qq[r++]=s;
    day[s]=0;
    vis[s]=t;
    mxDay=0;
    while(f<r){
        u=qq[f++];
        // if(vis[u]==t)
        //     continue;      
        vis[u]=t;
        dayCnt[day[u]]++;
        
        if(day[u]>mxDay)
            mxDay=day[u];

        for(i=0;i<adjMat[u].size();i++){
            v=adjMat[u][i];
            if(vis[v]!=t){
                day[v]=day[u]+1;
                qq[r++]=v;
                vis[v]=t;
            }
        }
    }

    return mxDay;
}

int main(){
    // inout();
    fast();
    int e,n,u,i,j,mxi,s,t,tk,m;

    cin>>e;
    for(i=0;i<e;i++){
        cin>>n;
        for(j=0;j<n;j++){
            cin>>u;
            adjMat[i].push_back(u);
        }
    }

    cin>>t;
    tk=0;
    while (tk<t)
    {
        tk++;
        cin>>s;
        m = callBfs(s,e,tk);

        if(m==0){
            cout<<m<<"\n";
            continue;
        }

        // for(i=0;i<e;i++)
        //     cout<<day[i]<<" ";
        // cout<<"\n";
        mxi=1;
        for(i=2;i<=m;i++){
            // cout<<i<<" "<<dayCnt[i]<<"\n";
            if(dayCnt[i]>dayCnt[mxi]){
                dayCnt[mxi]=0;
                mxi=i;
            }
            else
                dayCnt[i]=0;
        }

        cout<<dayCnt[mxi]<<" "<<mxi<<"\n";
        dayCnt[mxi]=0;
    }
    
}