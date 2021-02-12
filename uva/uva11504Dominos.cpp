//since the range is huge, i will use 2d vector
//first i will assign everyone as its own parent
//whenever node v is accessible from node u
//if v is its own parent, make everyones parent par[u], whose parents are v
//if v's parent is someone else, then ignore
//finally, count the number of parents in parent array
//day 2
//when there can be a bigger chain that is discovered later, this parent checking condition is not letting them connect
//without this condition everything gets connected, wich is not valid
//need to find a better way to concat
//day 3
//all these ideas didnt work
//so i grabed an idea from github
//i was thinking hoe do i handle the bi directional edges
//then i saw this idea of using two dfs
// first one puts everything on a stack, when it is discovered
//the second dfs starts from the last node that was discovered and finds all the connected components easily
//now let me finish him !!
//accepted

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int n,m;
int par[100005];
int vis[100005];
vector<int> grph[100005];
stack<int> st;

// int findPar(int a){
//     if(par[a]==a)
//         return a;
//     par[a]=findPar(par[a]);
//     return par[a];
// }

// void callBfs(int s){
//     int u,v;
//     queue<int> qq;
//     while(!qq.empty())
//         qq.pop();
//     qq.push(s);
//     // for(i=1;i<=n;i++)
//     //     vis2[i]=0;
//     while(!qq.empty()){
//         u=qq.front();
//         qq.pop();
//         vis[u]=1;

//         for(int i=0;i<grph[u].size();i++){
//             v=grph[u][i];
//             // if(par[u]!=v)
//                 par[v]=u;
//             if(vis[v]!=1){
//                 // cout<<u<<" "<<v<<"\n";
//                 qq.push(v);
//             }
//         }
//     }
//     return;
// }

void dfsWithStack(int a){
    vis[a]=1;
    for(int i=0;i<grph[a].size();i++){
        if(!vis[grph[a][i]])
            dfsWithStack(grph[a][i]);
    }
    st.push(a);
}
void callDfs(int a){
    vis[a]=1;
    for(int i=0;i<grph[a].size();i++){
        if(!vis[grph[a][i]])
            callDfs(grph[a][i]);
    }
}

int main(){
    inout();//for file input output
    int t,u,v,cnt;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cnt=0;
        for(int i=1;i<=n;i++){
            //clearing everything
            par[i]=i;
            vis[i]=0;
            if(!grph[i].empty())
            grph[i].clear();
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<m;i++){
            cin>>u>>v;
            grph[u].push_back(v);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i])
                dfsWithStack(i);
                
            // for(int i=1;i<=n;i++){
            //     cout<<par[i]<<" ";
            // }
            // cout<<"\n";
        }

        for(int i=1;i<=n;i++){
            vis[i]=0;
            // cout<<par[i]<<" ";
            //st.insert(findPar(i));
        }

        while(!st.empty()){
            u=st.top();
            st.pop();
            if(!vis[u])
            {
                cnt++;
                callDfs(u);
            }
        }
        
        cout<<cnt<<"\n";
    }
}