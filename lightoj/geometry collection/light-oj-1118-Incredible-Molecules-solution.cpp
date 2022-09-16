#include<iostream>
#include<stdio.h>
#include<cmath>
#include<utility>
#include<vector>
#include<algorithm>
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
    int n;
    int x1,x2,y1,y2,r1,r2;
    double ans;
    for(int tc=1;tc<=t;tc++){
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;
        if(r1<r2){
            swap(x1,x2);
            swap(y1,y2);
            swap(r1,r2);
        }
        double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        if(d<r1+r2){
            double x = ((r1*r1)-(r2*r2)+(d*d))/(2*d);
            if(x<=r1){
                double y = sqrt(r1*r1-x*x);
                // cout<<y<<"\n";
                ans = r1*r1*asin(y/r1)-y*sqrt(r1*r1-y*y)+r2*r2*asin(y/r2)-y*sqrt(r2*r2-y*y);
            }
            else{
                ans=pi*r2*r2;
            }
        }
        else{
            ans=0;
        }
        printf("Case %d: %.6lf\n",tc,ans);
    }
    return 0;
}