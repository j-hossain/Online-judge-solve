#include<iostream>
using namespace std;
#define mx 100005
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
    li arr1[mx],arr2[mx];
    li ans, n,i,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(i=0;i<n;i++){
            cin>>arr2[i];
        }
        for(i=1;i<n;i++)
            arr2[i] += arr2[i-1];
        for(i=n-2;i>=0;i--)
            arr1[i] += arr1[i+1];
        ans = 0;
        for(i=0;i<n-1;i++){
            if(arr1[i+1]>arr2[i])
                ans = max(ans,arr2[i]) ;
            else{
                ans = max(ans,arr1[i+1]);
                break;
            }
        }

        cout<<ans<<"\n";
    }
}