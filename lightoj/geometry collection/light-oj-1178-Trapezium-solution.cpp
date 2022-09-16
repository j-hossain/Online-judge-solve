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
    double ans;
    double a,b,c,d;
    for(int tc=1;tc<=t;tc++){
        cin>>a>>c>>b>>d;
        if(a<b){
            swap(a,b);
        }
        double s = (a+b+c+d)/2;
        ans = ((a+b)/(a-b))*sqrt((s-a)*(s-b)*(s-b-c)*(s-b-d));
        printf("Case %d: %.6lf\n",tc,ans);
    }
    return 0;
}