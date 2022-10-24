#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int arr[105];
    for(int tk=1;tk<=t;tk++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int f=1;
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]) f=0;
        }
        if(f==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
