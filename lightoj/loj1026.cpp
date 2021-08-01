#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define mx 100005
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}



vector<int> grph[mx];
vector<pair<int,int>> ans;
int vis[mx],in[mx],low[mx],ttt;

int getNum(string a){
    int num = 0;
    for(int i=1;i<a.size()-1;i++){
        num = num*10 + a[i]-'0';
    }
    return num;
}

void dfs(int u, int par){
    vis[u]=1;
    in[u] = low[u] = ttt++;

    for(int i=0;i<grph[u].size();i++){
        int v = grph[u][i];
        if(v!=par){
            if(!vis[v]){
                dfs(v,u);
                if(in[u]<low[v])
                    ans.push_back(make_pair(min(u,v),max(u,v)));
            }
            low[u] = min(low[u],low[v]);
        }
    }
}

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second<b.second;
}

int main(){
    inout();
    int t, n, i, u, v, e;
    string num;
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>u;
            vis[u]=0;
            grph[u].clear();
            cin>>num;
            e = getNum(num);

            while(e--){
                cin>>v;
                grph[u].push_back(v);
                grph[v].push_back(u);
            }
        }
        ttt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-11);
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        cout<<"Case "<<tk<<":\n";
        cout<<ans.size()<<" critical links\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" - "<<ans[i].second<<"\n";
        }
        ans.clear();
    }
    return 0;
}