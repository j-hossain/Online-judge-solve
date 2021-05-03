//the x! can be diveded by 'p' prime numbers
//where p = the number of prime numbers till x
//if x=6 then x! 720 can be diveded by 2,3 and 5 only

#include<iostream>
#include<vector>
#include<cmath>
#define mxz 1000000
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int isPrime[mxz+1],prCnt[mxz+1];
vector<int> pr;

void seive(){
    isPrime[0]=isPrime[1]=0;

    for(int i=2;i<=mxz;i++){
        if(isPrime[i]==0){
            isPrime[i]=i;
            pr.push_back(i);
        }

        for(int j=0;j<pr.size() && pr[j]<=isPrime[i] && i*pr[j]<=mxz;j++)
            isPrime[i * pr[j]] = pr[j];
    }

    for(int i=1;i<=mxz;i++){
        if(isPrime[i]==i)
            prCnt[i]=prCnt[i-1]+1;
        else
            prCnt[i]=prCnt[i-1];
    }
}

int main(){
    fast();
    inout();
    int t, x, y, ans;
    seive();
    cin>>t;
    while(t--){
        cin>>x>>y;
        ans = prCnt[x];
        // cout<<ans<<"\n";
        if(ans<=y)
            cout<<"Chef\n";
        else
            cout<<"Divyam\n"; 
    }
    return 0;
}