#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//tle
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int a,b,k,mnm,mxm,t,sq,i;
    cin>>t;
    while (t--)
    {
        /* code */
        cin>>a>>b>>k;
        int g = __gcd(a,b);
        if(a==b)
            mnm=0;
        else if(g==a || g==b)
            mnm=1;
        else
            mnm=2;
        sq = sqrt(a);
        mxm=0;
        int flag=(a==1)?1:0;
        for(i=2;i<=sq;i++){
            while(a%i==0){
                flag=1;
                a/=i;
                mxm++;
            }
            sq = sqrt(a);
        }
        if(!flag || a!=1)
            mxm++;
        sq = sqrt(b);
        flag=(b==1)?1:0;
        for(i=2;i<=sq;i++){
            while(b%i==0){
                flag=1;
                b/=i;
                mxm++;
            }
            sq = sqrt(b);
        }
        if(!flag || b!=1)
            mxm++;
        // cout<<mxm<<" "<<mnm<<"\n";
        if((mxm>=k && k>=mnm & k==1 & mnm==1)||(mxm>=k && k>=mnm & k!=1))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
    
}