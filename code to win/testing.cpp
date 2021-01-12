#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mx          110005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

double theFunc(double x){
    double ans;
    ans = x*x;
    ans-=4*x;
    ans-=10;

    return ans;
}

DN
{
    fast();
    inout();

    double x1,x2,x0,fx1,fx2,fx0,err;
    x1=-2;
    x2=-1;
    err=0.001;
    while(abs(x2-x1)>err){
        x0 = (x1+x2)/2.0;
        fx0 = theFunc(x0);
        fx1 = theFunc(x1);
        fx2 = theFunc(x2);
        cout<<x0<<nn;
        //cout<<"x1: "<<setw(11)<<x1<<"\tx0: "<<setw(11)<<x0<<"\tx2: "<<setw(11)<<x2;
        if(fx0==0)
            break;
        else if(fx1*fx0<0)
            x2=x0;
        else if(fx2*fx0<0)
            x1=x0;
        //cout<<abs(x1-x2)<<nn;
        //cout<<"\tfx1: "<<setw(11)<<fx1<<"\tfx0: "<<setw(11)<<fx0<<"\tfx2: "<<setw(11)<<fx2<<"\terror: "<<setw(11)<<abs(x1-x2)<<nn;
    }


    return 0;
}
