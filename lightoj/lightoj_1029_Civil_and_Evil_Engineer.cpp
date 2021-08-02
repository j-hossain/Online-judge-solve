#include<iostream>
#include<algorithm>
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct 
{
    /* data */
    int u,v,w;
}node;

int cmp(node a, node b){
    return a.w<b.w;
}

int vis[106],grp[106];

int findPar(int a){
    if(grp[a]==a)
        return a;
    return grp[a] = findPar(grp[a]);
}

int main(){
    inout();
    node arr[12000],temp;
    int t,n,u,v,w,mn,mx,cnt;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        for(int i=0;i<=n;i++){
            vis[i]=0;
            grp[i]=i;
        }
        int e=0;
        while(cin>>u>>v>>w){
            if(u==0&&v==0&&w==0)
                break;
            arr[e].u = u;
            arr[e].v = v;
            arr[e].w = w;
            e++;
        }

        sort(arr,arr+e,cmp);
        // for(int i=0;i<e;i++){
        //     cout<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].w<<"\n";
        // }
        mn = cnt =0;
        for(int i=0;i<e and cnt<=n;i++){
            u = arr[i].u;
            v = arr[i].v;
            w = arr[i].w;
            findPar(u);
            findPar(v);

            if(grp[u] != grp[v]){
                grp[grp[v]] = grp[u];
                cnt++;
                mn+=w;
            }
        }
        for(int i=0;i<=n;i++){
            vis[i]=0;
            grp[i]=i;
        }
        mx = cnt =0;
        for(int i=e-1;i>=0 and cnt<=n;i--){
            u = arr[i].u;
            v = arr[i].v;
            w = arr[i].w;
            findPar(u);
            findPar(v);

            if(grp[u] != grp[v]){
                grp[grp[v]] = grp[u];
                cnt++;
                mx+=w;
            }
        }
        mx+=mn;
        cout<<"Case "<<tt<<": ";
        if(mx&1){
            cout<<mx<<"/2\n";
        }
        else{
            cout<<(mx/2)<<"\n";
        }
    }
    return 0;
}