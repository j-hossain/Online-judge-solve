#include<iostream>
#include<queue>
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int grph[30][30],visited[30];

void myBfs(int u,int n){
    queue <int> sq;
    sq.push(u);
    while(!sq.empty()){
        u = sq.front();
        sq.pop();
        visited[u]=1;
        for(int i=0;i<n;i++){
            if(grph[u][i] && !visited[i]){
                sq.push(i);
            }
        }
    }
}

void clearThem(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            grph[i][j]=0;
        visited[i]=0;
    }
}

int main(){
    //inout();
    int t,n,i,j,u,v,cnt;
    string x;
    cin>>t;
    getline(cin,x);
    getline(cin,x);
    while(t--){
        getline(cin,x);
        n = x[0]-'A'+1;
        while(1){
            getline(cin,x);
            if(x[0]=='\0')
                break;
            u = x[0]-'A';
            v = x[1]-'A';
            grph[u][v] = grph[v][u] = 1;
        }
        cnt = 0;
        for(i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                myBfs(i,n);
            }
        }
        cout<<cnt<<endl;
        if(t)
            cout<<endl;
        clearThem(n);
    }
}
