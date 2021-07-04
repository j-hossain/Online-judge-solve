#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define li long long int
#define mx 10005
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

vector<li>prm;
set<li>prm2;
int chk[mx];
li mul[mx];
li ans[10000002],asz;

void setPrm(){
    prm.push_back(2);
    for(li i=3;i<mx;i+=2){
        if(chk[i]==0){
            prm.push_back(i);
            for(li j=i*i;j<mx;j+=2*i)
                chk[j]=1;
        }
    }
}

void setFor(li a){
    li sq = sqrt(a);
    li temp;
    for(int i=0;i<prm.size() && prm[i]<=sq;i++){
        if(a%prm[i]==0){
            temp = 1;
            prm2.insert(prm[i]);
            while(a%prm[i]==0){
                a/=prm[i];
                temp*=prm[i];
            }
            mul[prm[i]]= max(temp,mul[prm[i]]);
        }
    }
    if(a!=1){
        mul[a] = max(a,mul[a]);
        prm2.insert(a);
    }
}

void multi(li x){
    li prd,rem = 0;
    for(int i=0;i<asz;i++){
        prd = ans[i]*x+rem;
        rem = prd/10;
        ans[i] = prd%10;
    }
    while(rem){
        ans[asz] = rem%10;
        rem/=10;
        asz++;
    }
}

int main(){
    inout();
    li t,n,arr[1005],i,lc,tk;
    setPrm();
    cin>>t;
    for(tk=1;tk<=t;tk++){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        for(i=0;i<prm.size();i++)
            mul[prm[i]]=0;
        for(i=0;i<n;i++){
            setFor(arr[i]);
        }

        ans[0]=1;
        asz = 1;
        for(auto pr:prm2){
            // cout<<mul[pr]<<"\n";
            multi(mul[pr]);
        }
        cout<<"Case "<<tk<<": ";
        for(i=asz-1;i>=0;i--)
            cout<<ans[i];
        cout<<"\n";
        prm2.clear();

    //1 by one lcm, using gcd-lcm relatioship
        //this doesnt work
        // lc = (arr[0]*arr[1])/__gcd(arr[0],arr[i]);
        // for(i=2;i<n;i++){
        //     lc = (lc*arr[i])/__gcd(lc,arr[i]);
        // }
        // cout<<"Case "<<tk<<": ";
        // cout<<lc<<"\n";
    }
}