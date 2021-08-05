#include<iostream>
#include<iomanip>
using namespace std;

double dp[105],n,arr[105];
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
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        double e=0;
        double ev = 0;
        for(int i=n-1;i>=0;i--){
            e=ev=0;
            for(int j=1;j<=6;j++){
                if(i+j<n){
                    e++;
                    ev+=arr[i+j]+arr[i];
                }
            }
            if(e>0){
                arr[i] = ev/e;
            }
        }
        cout<<"Case "<<tt<<": ";
        cout<<fixed<<setprecision(7)<<arr[0]<<"\n";
    }
}