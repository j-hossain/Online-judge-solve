
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define nl cout<<"\n";
string spc=" ";



void solve2(){
    char st[10][10];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>st[i][j];
        }
    }
    string sol;
    if(st[1][0]==st[0][0] && st[1][0]==st[2][0]){
        sol=st[1][0];
    }
    else if(st[1][2]==st[0][2] && st[1][2]==st[2][2]){
        sol=st[1][2];
    }
    else if(st[1][1]==st[0][0] && st[1][1]==st[2][2]){
        sol=st[1][1];
    }
    else if(st[1][1]==st[0][1] && st[1][1]==st[2][1]){
        sol=st[1][1];
    }
    else if(st[1][1]==st[0][2] && st[1][1]==st[2][0]){
        sol=st[1][1];
    }
    else if(st[0][0]==st[0][1] && st[0][1]==st[0][2]){
        sol=st[0][0];
    }
    else if(st[1][0]==st[1][1] && st[1][1]==st[1][2]){
        sol=st[1][0];
    }
    else if(st[2][0]==st[2][1] && st[2][1]==st[2][2]){
        sol=st[2][0];
    }
    else{
        sol="DRAW";
    }
    if(sol==".") cout<<"DRAW"<<endl;
    else cout<<sol<<endl;
}





int main()
{

    ios::sync_with_stdio(0);  cin.tie(0);
    ll n; cin>>n;
    while(n--)
        solve2();


    return 0;
}
