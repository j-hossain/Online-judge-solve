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
    int taken;
}edge;

int group[1006];
edge edges[25005];

int findGroup(int x){
    if(group[x]!=x)
        group[x] = findGroup(group[x]);
    return group[x];
}

// void mergeGroup(int u, int v){
//     if(group[v]!=v)
//         mergeGroup(u,group[v]);
//     group[v] = u;
// }

bool comp(edge a, edge b){
    return a.w<b.w;
}

int main(){
    inout();
    int n,m,gu,gv,w,i,j;

    while(cin>>n>>m){
        if(n==0 && m==0)
            break;

        for(i=0;i<m;i++){
            cin>>edges[i].u>>edges[i].v>>edges[i].w;
            edges[i].taken = 0;
        }

        sort(edges,edges+m,comp);
        
        for(i=0;i<n;i++)
            group[i]=i;

        j=0;
        for(i=0;i<m;i++){
            if(j==n+1)
                break;
            gu=findGroup(edges[i].u);
            gv=findGroup(edges[i].v);

            if(gu==gv){
                continue;
            }
            else{
                j++;
                edges[i].taken =1;
                group[gv] = gu;
            }
        }
        if(m-j==0){
            cout<<"forest\n";
            continue;
        }
        j=0;
        for(i=0;i<m;i++){
            if(!edges[i].taken){
                if(!j)
                    j=1;
                else
                    cout<<" ";
                cout<<edges[i].w;
            }
        }
        cout<<"\n";
    }
    return 0;
}