#include<iostream>
#include<stdio.h>
#include<cmath>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

const int MM = 1004;

int x[MM];
int y[MM];
pair<double,double> midPoint;

int gcd(int a, int b){
    if(b==0)
        return 1;
    else 
        return gcd(b,a%b);
}

pair<double,double> calcMidPoint(int x1,int y1,int x2,int y2){
    return {(x1+x2)/2.0,(y1+y2)/2.0};
}

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

vector<pair<double,double>> mids;

bool comp(pair<double,double> a,pair<double,double> b){
    if(a.first<b.first){
        return true;
    }
    else if(a.first==b.first){
        return a.second<b.second;
    }
    else
        return false;
}

int main(){
    inout();
    int t;
    cin>>t;
    int n;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                midPoint = calcMidPoint(x[i],y[i],x[j],y[j]);
                mids.push_back(midPoint);
            }
        }
        sort(mids.begin(),mids.end(),comp);
        int cnt=1;
        int ans=0;
        for(int i=1;i<mids.size();i++){
            // cout<<mids[i].first<<" "<<mids[i].second<<"\n";
            if(mids[i]==mids[i-1])
                cnt++;
            else{
                ans+=(cnt*(cnt-1)/2);
                cnt=1;
            }
        }
        ans+=(cnt*(cnt-1)/2);
        cout<<"Case "<<tc<<": "<<ans<<"\n";
        mids.clear();
    }
    return 0;
}