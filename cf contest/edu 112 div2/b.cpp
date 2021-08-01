#include<iostream>
using namespace std;
#define li long long int
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    li t,w,h,w1,h1,ww[2],hh[2],x1,x2,y1,y2,ans;
    cin>>t;
    while(t--){
        cin>>w>>h>>x1>>y1>>x2>>y2>>w1>>h1;
        ans = __LONG_LONG_MAX__;
        int flag=0;
        if(w1+(x2-x1)<=w){
            flag=1;
            ans = min(ans,max(0LL,w1-x1)); 
            ans = min(ans,max(0LL,x2-w+w1)); 
        }
        if(h1+(y2-y1)<=h){
            flag = 1;
            ans = min(ans,max(0LL,h1-y1)); 
            ans = min(ans,max(0LL,y2-h+h1)); 
        }
        if(!flag){
            cout<<"-1\n";
            continue;
        }
        cout<<ans<<'\n';
    }
    return 0;
}