#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define blk 320
#define mx 100006

struct query
{
    int l,r,ind,k;

    bool operator<(const query &a)const{
        int x = l/blk;
        int y = a.l/blk;
        if(x==y)
            return r<a.r;
        return x<y;
    }
};

query qr[mx];
vector<int> grph[mx];
int st[mx],en[mx],ft[2*mx],time;
int col[mx],freq[mx],ffre[mx];

void dfs(int u, int par){
    st[u] = time;
    ft[time] = u ;
    time++;
    for(int i=0;i<grph[u].size();i++){
        if(grph[u][i]!=par){
            dfs(i,u);
        }
    }
    en[u] = time;
    ft[time] = u;
}

void mosAdd(int i){
    int col = 
}

void mosRem(int i){

}

int main(){
    int n,q,u,v;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    time = 1;
    dfs(1,0);
    for(int i=0;i<q;i++){
        cin>>u>>v;
        qr[i].l = st[u];
        qr[i].r = en[u];
        qr[i].ind = i;
        qr[i].k = v;
    }
    sort(qr,qr+q);
    u = 0;
    v = -1;
    for(int i=0;i<q;i++){
        while(u<qr[i].l) mosRem(u--);
        while(u>qr[i].l) mosAdd(++u);
        while(v>qr[i].r) mosRem(v--);
        while(v<qr[i].r) mosAdd(++v);
    }
}