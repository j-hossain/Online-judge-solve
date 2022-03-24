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

int grph[205][205],vis[205],group[205];

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
    grp[0] = grp[1] = 0;

    while(!sq.empty()){
        int u = sq.front();
        sq.pop();
        vis[u] = 1;

        for(int i=1; i<=n; i++){
            if(grph[u][i]){
                if(group[i]==2){
                    sq.push(i);
                    group[i] = group[u]^1;
                    grp[group[i]]++;
                }
                else if(group[i]==group[u])//no one to invite if cycle found
                    return 0;
            }
        }
    }

    return grp[0]>grp[1]?grp[0]:grp[1];
}

int main(){
    inout();

    int t,n,ne,e,i,j,cnt,ts=0;

    cin>>t;
    while(t--){
        ts++;
        if(ts==190){

        cin>>n;
        cout<<n<<endl;
        for(i=1;i<=n;i++){
            group[i] = 2;
            vis[i] = 0;
            cin>>ne;
            cout<<ne;
            for(j=0;j<ne;j++){
                cin>>e;
                cout<<" "<<e;
                grph[i][e] = grph[e][i] = 1;
            }
            cout<<endl;
        }
        }
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
    }
    return 0;
}
