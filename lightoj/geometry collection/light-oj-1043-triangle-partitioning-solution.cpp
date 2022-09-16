#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    double pi = acos(-1.0);
    int t;
    cin>>t;
    double a,b,c,d,r1,r2;
    for(int tc=1;tc<=t;tc++){
        cin>>a>>b>>c>>r1;
        printf("Case %d: %.6lf\n",tc,sqrt(r1/(r1+1.0))*a);
    }
    return 0;
}