#include<iostream>
using namespace std;

int grph[250][250];

int main(){
    int n,e,u,v,i,j,tk;
    cin>>tk;
    while(tk--){
        cin>>n>>e;
        for(i=0;i<e;i++){
            cin>>u>>v;
            grph[u][v]=1;
            grph[v][u]=1;
        }
    }
}
