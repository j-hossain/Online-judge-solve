#include<iostream>
#include<cmath>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

double lg[1000005];
int main(){

    inout();
    int n,b,t,ans,tc;
    double a;
    lg[0] = 0;
    for(int i=1;i<1000005;i++){
        lg[i] = lg[i-1]+log10(i);
    }

    cin>>t;
    tc=0;
    while(t--){
        tc++;
        cin>>n>>b;
        a = log10(b);
        ans = lg[n]/a;
        ans++;
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
}