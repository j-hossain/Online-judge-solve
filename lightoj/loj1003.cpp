#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
//time limmit
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

map<string,vector<string>>mp;
unordered_map<string,int>vis;

int cicle(string u){
    vis[u]=1;
    for(auto at:mp[u]){
        if(vis[at]==0){
            if(cicle(at))
                return 1;
        }
        else if(vis[at]==1)
            return 1;
    }
    vis[u]=2;
    return 0;
}

int main(){
    inout();
    fast();
    int t,n,i,flag;
    string u,v;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        mp.clear();
        for(i=0;i<n;i++){
            cin>>v>>u;
            mp[u].push_back(v);
        }
        vis.clear();
        flag=1;
        for(auto at:mp){
            if(vis[at.first]==0){
                if(cicle(at.first)){
                    flag=0;
                    break;
                }
                at.second.clear();
            }
        }
        cout<<"Case "<<tc<<": ";
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}