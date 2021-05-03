#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

//undirected bhable hobe na maybe

vector<pair<string,string>> inp;
map<string,string> par;

int main(){
    inout();
    string u,v;
    int t,m,flag;
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>m;
        flag=1;
        while(m--){
            cin>>u>>v;   
            inp.push_back({u,v});
            par[u] = u;
            par[v] = v;
        }

        for(auto i: inp){
            u = i.first;
            v = i.second;

            if(u==findPar(v)){
                flag=0;
                break;
            }
            else if(par[u]==u)
        }

        cout<<"Case "<<tk<<": ";
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        
        par.clear();
    }
}