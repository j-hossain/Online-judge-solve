//direct implementation of kruskal's mst akgo
//accepted
#include<iostream>
#include<algorithm>
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct {
    int u;
    int v;
    int w;
}edge;

edge ed[200005];
int n,m,sum,par[200005];

int comp(edge a, edge b){
    return a.w<b.w;
}

int findPar(int a){
    if(par[a]==a)return a;
    par[a]=findPar(par[a]);
    return par[a];
}

void concat(int a, int b){
    for(int i=0;i<n;i++)
        if(par[i]==a)
            par[i]=b;
}

int main(){
    fast();
    inout();
    // cout<<"test\n";
    int cnt;
    while(1){
        cin>>n>>m;
        if(!n and !m)
            break;
        sum=cnt=0;
        for(int i=0;i<n;i++)
            par[i]=i;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>ed[i].u>>ed[i].v>>ed[i].w;
            sum+= ed[i].w;
        }
        // cout<<sum<<"\n";
        sort(ed,ed+m,comp);

        for(int i=0;i<m;i++){
            int pu = findPar(ed[i].u);
            int pv = findPar(ed[i].v);
            if(cnt==n-1)
                break;
            if(pu!=pv){
                concat(pu,pv);
                sum-=ed[i].w;
                cnt++;
            }
        }

        cout<<sum<<"\n";
    }
    return 0;
}