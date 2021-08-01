#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define mx 1000004
#define li long long int

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


int prmMap[mx];
vector<li> prm;

void getPrm (){
    prm.push_back(2);
    for(li i=3;i<mx;i+=2){
        if(prmMap[i]==0){
            prm.push_back(i);
            for(li j=i*i;j<mx;j+=2*i)
                prmMap[j] = 1;
        }
    }
}

li getAns(li n){
    li ans = 1;
    li cnt=0;
    for(int i=0;i<prm.size() && prm[i]<=sqrt(n);i++){
        cnt=0;
        while(n%prm[i]==0){
            n/=prm[i];
            cnt++;
        }
        ans*=(cnt+1);
    }
    if(n>1){
        ans*=2;
    }
    return ans-1;
}

int main(){
    inout();
    li t,n,ans;
    getPrm();
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        ans = getAns(n);
        cout<<"Case "<<tt<<": ";
        cout<<ans<<"\n";
    }
}