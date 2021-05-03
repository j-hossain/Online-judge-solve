#include<iostream>
#include<algorithm>
using namespace std;
//accepted


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct{
    int u;
    int v;
    int w;
}edge;

int n,e,grph[502][502],dis[502],par[502],vis[502];

int cmp(edge a, edge b);
int findPar(int a);
int doDfs(int u);

int main(){
    inout();
    edge arr[16004];
    int i,j,t,tk=0,source;
    cin>>t;
    while(t--){
        tk++;
        cin>>n>>e;
        for(i=0;i<e;i++){
            cin>>arr[i].u>>arr[i].v>>arr[i].w;
        }
        cin>>source;
        sort(arr,arr+e,cmp);

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                grph[i][j]=0;
            }
            dis[i]=-1;
            par[i]=i;
            vis[i]=0;
        }

        for(i=0;i<e;i++){
            int u=arr[i].u;
            int v=arr[i].v;
            int w=arr[i].w;
            if(findPar(u)!=findPar(v)){
                par[par[u]] = par[v];
                grph[u][v] = w;
                grph[v][u] = w;
            }
        }

        // for(i=0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         cout<<grph[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        dis[source]=0;
        doDfs(source);
        cout<<"Case "<<tk<<":\n";
        for(i=0;i<n;i++){
            if(dis[i]!=-1)
                cout<<dis[i]<<"\n";
            else
                cout<<"Impossible\n";
        }
    }
    return 0;
}

int cmp(edge a, edge b){
    return a.w<b.w;
}

int findPar(int a){
    if(par[a]==a)
        return a;
    return par[a] = findPar(par[a]);
}

int doDfs(int u){
    vis[u]=1;
    for(int i=0;i<n;i++){
        if(grph[u][i]>0 && !vis[i]){
            dis[i] = max(dis[u],grph[u][i]);
            vis[i]=1;
            doDfs(i);
        }
    }
}