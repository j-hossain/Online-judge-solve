#include<iostream>
#include<queue>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}
int allZero(int, int);
int getMax(int, int);
void visitAll(int, int);

int grph[205][205],vis[205],group[205];

int main(){
    inout();

    int t,n,ne,e,i,j,cnt;

    cin>>t;
    while(t--){
        cnt = 0;
        cin>>n;
        for(i=1;i<=n;i++){
            group[i] = 2;
            vis[i] = 0;
            cin>>ne;
            for(j=0;j<ne;j++){
                cin>>e;
                grph[i][e] = grph[e][i] = 1;
            }
        }

        //including non connected components, no friends, no enemy
        for(i=1; i<=n; i++){
            if(allZero(i,n)){
                vis[i] = 1;
                cnt++;
            }
        }

        //getting the max number of people from each graph part
        for(i=1; i<=n; i++){
            if(!vis[i]){
                cnt += getMax(i,n);
            }
        }

        //clearing the graph
        for(i=1; i<=200; i++){
            vis[i] = 0;
            for(j=1; j<=200; j++)
                grph[i][j] = 0;
        }


        cout<<cnt<<"\n";
    }
    return 0;
}

int allZero(int p, int n){
    for(int i=1; i<=n; i++){
        if(grph[p][i])
            return 0;
    }
    return 1;
}

int getMax(int s, int n){
    queue<int> sq;
    sq.push(s);
    group[s] = 0;
    int grp[2];
    grp[0] = 1;
    grp[1] = 0;

    while(!sq.empty()){
        int u = sq.front();
        sq.pop();
            for(int i=1; i<=n; i++){
                if(grph[u][i]){
                    if(group[i]==2){
                        sq.push(i);
                        group[i] = group[u]^1;
                        grp[group[i]]++;
                    }
                    else if(group[i]==group[u]){
                        visitAll(s,n);
                        return 0;//no one to invite if cycle found
                    }

                }
            }
        vis[u] = 1;
    }

    return grp[0]>grp[1]?grp[0]:grp[1];
}

void visitAll(int s, int n){
    queue<int> sq;
    sq.push(s);
    int visit[200];
    for(int i=0; i<=n; i++)
        visit[i] = 0;

    while(!sq.empty()){
        int u = sq.front();
        sq.pop();
        for(int i=1; i<=n; i++){
            if(grph[u][i]){
                if(!visit[i])
                    sq.push(i);
            }
        }
        vis[u] = visit[u] = 1;
    }
}
