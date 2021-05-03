#include<iostream>
using namespace std;
int main(){
    long long int mn,mx;

    long long int n,i,arr[100005];

    long long int t,tk=0;
    cin>>t;
    while(t--){
        tk++;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        mx=mn=arr[0];
        for(i=1;i<n;i++){
            if(arr[i]<mn)
            mn=arr[i];
            if(arr[i]>mx)
            mx=arr[i];
        }

        long long int ans = mn*mx;
        // cout<<t<<"\n";
        cout<<"Case "<<tk<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}