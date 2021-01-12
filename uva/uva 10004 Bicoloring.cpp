#include<iostream>
#include<queue>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

int grph[205][205],n,e;

int colorize(){
    int clr[n],i,j,vis[n],u;
    queue<int>qq;

    for(i=0;i<n;i++){
        vis[i]=0;
        clr[i]=-1;
    }
    clr[0]=1;
    qq.push(0);

    while(!qq.empty()){
        u = qq.front();
        qq.pop();
        vis[u]=1;
        for(i=0;i<n;i++){
            if(grph[u][i]==1){
                if(clr[i]==-1)
                    clr[i]=clr[u]^1;
                if(clr[i]==clr[u]){
                    return 0;
                }
                if(!vis[i])
                    qq.push(i);
            }
        }
    }

    return 1;
}



int main(){
    int i,j,u,v;
    //inout();

    while(cin>>n){
        if(!n)
            break;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                grph[i][j]=0;

        cin>>e;

        for(i=0;i<e;i++){
            cin>>u>>v;
            grph[u][v]=1;
            grph[v][u]=1;
        }

        if(colorize())
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
    }
    return 0;
}
