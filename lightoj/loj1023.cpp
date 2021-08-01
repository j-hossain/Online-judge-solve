#include<iostream>
#include<string>
using namespace std;
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}
int printed;
string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void show(string out,int taken, int n, int k){
    // cout<<out<<"\n";
    if(printed==k){
        return;
    }
    if(taken==(1<<n)-1){
        cout<<out<<"\n";
        printed++;
        return;
    }

    for(int i=0;i<n;i++){
        if(!((1<<i)&taken)){
            out.push_back(alp[i]);
            show(out,taken|(1<<i),n,k);
            out.pop_back();
        }
    }
}

int main(){
    inout();
    fast();
    int n,k,t,tk;
    cin>>t;
    for(tk=1;tk<=t;tk++){
        cin>>n>>k;
        printed=0;
        cout<<"Case "<<tk<<":\n";
        show("",0,n,k);
    }
    return 0;
}