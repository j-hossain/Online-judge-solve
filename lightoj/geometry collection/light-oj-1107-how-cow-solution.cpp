#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main(){
    inout();
    double pi = acos(-1.0);
    int t;
    cin>>t;
    int x1,x2,y1,y2,n,x,y;
    for(int tc=1;tc<=t;tc++){
        printf("Case %d:\n",tc);
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        while(n--){
            cin>>x>>y;
            if(x1<=x and x<=x2 and y1<=y and y<=y2){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}