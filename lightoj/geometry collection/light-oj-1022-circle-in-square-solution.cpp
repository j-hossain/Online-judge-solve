#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    double pi = acos(-1.0);
    int t;
    cin>>t;
    double r;
    for(int tc=1;tc<=t;tc++){
        cin>>r;
        double a = r*r;
        double cir = pi*a;
        double sq = 4*a;
        printf("Case %d: %.2lf\n",tc,sq-cir);
    }
    return 0;
}