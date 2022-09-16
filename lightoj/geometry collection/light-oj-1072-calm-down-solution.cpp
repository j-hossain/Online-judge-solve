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
    double n;
    double ang;
    double r;
    for(int tc=1;tc<=t;tc++){
        cin>>r>>n;
        ang = pi/n;
        ang = sin(ang);
        double ans = (r*ang)/(1+ang);
        printf("Case %d: %.10lf\n",tc,ans);
    }
    return 0;
}