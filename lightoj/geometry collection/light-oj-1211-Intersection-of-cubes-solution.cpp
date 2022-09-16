#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

const int MM = 1004;
const double pi = acos(-1.0);

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main(){
    inout();
    int t;
    cin>>t;
    int ans;
    int n,a,b,c;
    int x1[101];
    int y1[101];
    int z1[101];
    int x2[101];
    int y2[101];
    int z2[101];
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x1[i]>>y1[i]>>z1[i];
            cin>>x2[i]>>y2[i]>>z2[i];
        }
        a=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(!(x1[k]<=min(x1[i],x2[j]) and max(x1[i],x2[j])<=x2[k])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    a = abs(x1[i]-x2[j]);
                    break;
                }
            }
            if(a!=-1){
                break;
            }
        }
        if(a==-1)a=0;
        
        b=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(!(y1[k]<=min(y1[i],y2[j]) and max(y1[i],y2[j])<=y2[k])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    b = abs(y1[i]-y2[j]);
                    break;
                }
            }
            if(b!=-1){
                break;
            }
        }
        if(b==-1)b=0;
        
        c=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(!(z1[k]<=min(z1[i],z2[j]) and max(z1[i],z2[j])<=z2[k])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    c = abs(z1[i]-z2[j]);
                    break;
                }
            }
            if(c!=-1){
                break;
            }
        }
        if(c==-1)c=0;
        // cout<<a<<b<<c<<"\n";
        ans = a*b*c;
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}