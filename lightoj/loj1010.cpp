#include<iostream>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

void logic(int t){
    int n,m,ans;
    cin>>n>>m;
    cout<<"Case "<<t<<": ";
    if(n==1 || m==1){
        ans = max(n,m);
    }
    else if(n==2 || m==2){
        m = max(m,n);
        ans = m/4;
        ans*=2;
        if(m%4==1){
            ans+=1;
        }
        else if(m%4!=0)
            ans+=2;
        ans*=2;
    }
    else{
        ans = (m*n+1)/2;
    }
    cout<<ans<<"\n";
}

int main(){
    inout();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        logic(tc);
    }
}